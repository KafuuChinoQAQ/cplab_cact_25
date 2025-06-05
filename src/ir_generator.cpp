#include "ir_generator.h"
#include <regex>
#include <string>
#include <vector>
namespace cplab_ir_generator
{
    // 总入口
    void ir_generator(ast_node &node)
    {
        ir_gen_declaration(node);
    }
    
    // 生成declaration相关结点的IR代码
    // 传入AST根节点给该函数,然后递归地遍历AST树,当找到一个变量/常量声明时,为对应的AST结点生成ir_code属性
    void ir_gen_declaration(ast_node &node)
    {
        if(node.name == "declaration") 
        {
            // declaration只有一个子节点,即变量声明或常量声明节点,先生成子节点的ir_code,然后赋给父节点
            ir_gen_declaration(*node.children[0]);
            node.ir_code = node.children[0]->ir_code; // 将子节点的ir_code赋给当前节点
        }
        else if(node.name == "variable_declaration") 
        {
            // variable_declaration的ir_code由其各个variable_definition子节点的ir_code拼接而成
            std::string ir_code="";
            for (auto &child : node.children)
            {
                if (child->name == "variable_definition")
                {
                    ir_gen_declaration(*child); // 递归调用
                    ir_code += child->ir_code; // 拼接子节点的ir_code
                }
            }
            node.ir_code = ir_code; // 将拼接后的ir_code赋给当前节点
        }
        else if(node.name == "constant_declaration") 
        {
            // constant_declaration的ir_code由其各个constant_definition子节点的ir_code拼接而成
            std::string ir_code="";
            for (auto &child : node.children)
            {
                if (child->name == "constant_definition")
                {
                    ir_gen_declaration(*child); // 递归调用
                    ir_code += child->ir_code; // 拼接子节点的ir_code
                }
            }
            node.ir_code = ir_code; // 将拼接后的ir_code赋给当前节点
        }
        else if(node.name == "variable_definition" || node.name == "constant_definition")
        {
            identifier* current_id; // 用于存储当前变量或常量定义对应的作用域树结点
            std::string ir_code_1=""; // 用于存储IR代码的第一部分 即声明部分
            // 对于变量或常量定义结点,直接生成其ir_code
            // 先查阅当前作用域,找到该变量或常量的标识符信息
            if (node.scope_ptr != nullptr)
            {
                // 在当前作用域中查找对应的标识符 并获取其类型
                for (auto &id : node.scope_ptr->identifiers)
                {
                    if (id.line_number == node.node_index) // 通过行号匹配标识符
                    {
                        current_id = &id; // 找到对应的标识符
                        // 找到对应的标识符,生成ir_code的第一部分
                        ir_code_1 = "%" + std::to_string(id.id_index) + " = alloca ";
                        if (id.type == "int")
                        {
                            ir_code_1 += "i32, align 4\n"; // 分配一个整型变量
                        }
                        else if(id.type == "float")
                        {
                            ir_code_1 += "float, align 4\n"; // 分配一个浮点型变量
                        }
                        else if(id.type == "char")
                        {
                            ir_code_1 += "i8, align 1\n"; // 分配一个字符型变量
                        }
                        else //数组类型
                        {
                            ir_code_1 += to_llvm_array_type(id.type); // 分配一个数组变量
                        }
                        break; // 找到后跳出循环
                    }
                }
                std::string ir_code_2=""; // 用于存储IR代码的第二部分 即初始化部分
                // 首先检查是否有初始化值,如果最后一个子节点不是constant_initial_value,则说明该变量没有初始化值,但常量一定有
                if (node.children.size() > 0 && node.children.back()->name == "constant_initial_value")
                {
                    // 如果有显式初始化,则计算初始化表达式值,然后将该值赋给id
                }
                else
                {
                    // 否则进行隐式初始化
                    if(current_id->type == "int")
                    {
                        ir_code_2 = "store i32 0, ptr %" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为0
                        if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                        {
                            current_id->const_value = 0;
                        }
                    }
                    else if(current_id->type == "float")
                    {
                        ir_code_2 = "store float 0.0, ptr %" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为0.0
                        if(current_id->kind == IdKind::Const)
                        {
                            current_id->const_value = 0.0f;
                        }
                    }
                    else if(current_id->type == "char")
                    {
                        ir_code_2 = "store i8 0, ptr %" + std::to_string(current_id->id_index) + ", align 1\n"; // 初始化为'\0'
                        if(current_id->kind == IdKind::Const)
                        {
                            current_id->const_value = '\0';
                        }
                    }
                    // 访问未初始化的数组是未定义的行为,这里我们不对其进行隐式初始化
                }
                node.ir_code = ir_code_1 + ir_code_2; // 将ir_code赋给当前节点
            }
            else
            {
                // 如果没有找到作用域指针,则说明该节点不在任何作用域中,直接报错
                throw std::runtime_error("Variable or constant definition without scope pointer.");
            }
        }
        else
        {
            // 如果不是declaration相关结点,则递归处理子节点
            for (auto &child : node.children)
            {
                ir_gen_declaration(*child); // 递归调用
            }
        }
    }

    // 将Cact类型转换为LLVM数组类型 用于数组变量的声明
    // 将如 "int[2][3][4]" 转为 "[2 x [3 x [4 x i32]]]"
    std::string to_llvm_array_type(const std::string& type_str) {
        std::regex array_regex(R"(\[(\d+)\])");
        std::smatch match;
        std::string base_type;
        if (type_str.find("int") == 0) {
            base_type = "i32";
        } else if (type_str.find("float") == 0) {
            base_type = "float";
        } else if (type_str.find("char") == 0) {
            base_type = "i8";
        } else {
            base_type = "i32"; // 默认
        }
        std::string result = base_type;
        std::string s = type_str;
        std::vector<std::string> dims;

        // 提取所有维度
        while (std::regex_search(s, match, array_regex)) {
            dims.push_back(match[1]);
            s = match.suffix();
        }

        // 从最后一维往前包裹
        for (auto it = dims.rbegin(); it != dims.rend(); ++it) {
            result = "[" + *it + " x " + result + "]";
        }
        return result+", align 16\n";
    }
}