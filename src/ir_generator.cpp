#include "ir_generator.h"
#include <regex>
#include <string>
#include <vector>
namespace cplab_ir_generator
{
    // 总入口
    void ir_generator(ast_node &node)
    {

        // 然后遍历所有节点,依次生成所有expression和condition结点的IR代码
        // 注意 这里不包括函数实参内部的expression结点
        // 因为函数实参的IR代码在函数调用时生成
        for (auto &child : node.children)
        {
            if (child->name == "condition")
            {
                // 计算逻辑表达式的值,并将IR代码添加到节点的ir_code属性上
                calculate_expression_value(*child,"bool"); // 传入子节点的类型
            }
            else if(child->name == "expression")
            {
                // 计算算术表达式的值,并将IR代码添加到节点的ir_code属性上
                std::string type = get_arithmetic_expression_type(*child); // 获取算术表达式的类型
                calculate_expression_value(*child,type); // 传入子节点的类型
            }
            else if(child->name == "block")
            {
                // 生成block结点的IR代码
                ir_gen_block(*child);
            }
            else if (child->name == "function_definition")
            {
                // 生成函数定义结点的IR代码
                ir_gen_func_definition(*child);
            }
            else
            {
                ir_generator(*child); // 递归调用
            }
        }
        // 最后,如果当前节点是根节点,将其ir_code属性设置为所有子节点的ir_code拼接而成
        // 此外还要事先声明6个标准库函数函数
        if (node.name == "compilation_unit") // 如果是根节点
        {
            std::string ir_code = "";
            // 声明库函数
            ir_code += "declare void @print_int(i32)\n";
            ir_code += "declare void @print_float(float)\n";
            ir_code += "declare void @print_char(i8)\n";
            ir_code += "declare i32 @get_int()\n";
            ir_code += "declare float @get_float()\n";
            ir_code += "declare i8 @get_char()\n";
            for (auto &child : node.children)
            {
                ir_code += child->ir_code; // 拼接子节点的IR代码
            }
            node.ir_code = ir_code; // 设置根节点的IR代码
        }
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
                        break; // 找到后跳出循环
                    }
                }
                // 如果id位于非全局作用域中 则定义一个局部变量
                if(node.scope_ptr->name != "global")
                {
                    current_id->is_global = false; // 设置为局部变量
                    std::string ir_code_1=""; // 用于存储IR代码的第一部分 即声明部分
                    std::string ir_code_2=""; // 用于存储IR代码的第二部分 即初始化部分
                    // 找到对应的标识符,生成ir_code的第一部分
                    ir_code_1 = "%id_" + std::to_string(current_id->id_index) + " = alloca ";
                    if (current_id->type == "int")
                    {
                        ir_code_1 += "i32, align 4\n"; // 分配一个整型变量
                    }
                    else if(current_id->type == "float")
                    {
                        ir_code_1 += "float, align 4\n"; // 分配一个浮点型变量
                    }
                    else if(current_id->type == "char")
                    {
                        ir_code_1 += "i8, align 1\n"; // 分配一个字符型变量
                    }
                    else //数组类型
                    {
                        ir_code_1 += to_llvm_array_type(current_id->type); // 分配一个数组变量
                    }
                    // 首先检查是否有初始化值,如果最后一个子节点不是constant_initial_value,则说明该变量没有初始化值,但常量一定有
                    if (node.children.size() > 0 && node.children.back()->name == "constant_initial_value")
                    {
                        // 如果有显式初始化,则计算初始化表达式值,然后将该值赋给id
                        // 根据助教的说法,此处的常量表达式只会是立即数,不需要递归计算表达式的值
                        if(current_id->type == "int")
                        {
                            int init_value = std::get<int>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                            ir_code_2 = "store i32 " + std::to_string(init_value) + ", i32* %id_" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为init_value
                            if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                            {
                                current_id->const_value = init_value;
                            }
                        }
                        else if(current_id->type == "float")
                        {
                            float init_value = std::get<float>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                            ir_code_2 = "store float " + std::to_string(init_value) + ", float* %id_" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为init_value
                            if(current_id->kind == IdKind::Const)
                            {
                                current_id->const_value = init_value;
                            }
                        }
                        else if(current_id->type == "char")
                        {
                            char init_value = std::get<char>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                            // 注意:这里的char类型在LLVM中是i8类型,需要转换为整数
                            ir_code_2 = "store i8 " + std::to_string(static_cast<int>(init_value)) + ", i8* %id_" + std::to_string(current_id->id_index) + ", align 1\n"; // 初始化为init_value
                            if(current_id->kind == IdKind::Const)
                            {
                                current_id->const_value = init_value;
                            }
                        }
                        else //对于数组类型,其初始化比较复杂
                        {
                            //我们考虑将高维数组摊平为一维数组来做
                            //例如,对于int a[2][2] = {{1,3},{5,7}},我们实际上只需要将1 3 5 7按顺序存进内存即可
                            //首先将数组中所有元素的初始值存储在一个vector中
                            std::variant<std::vector<int>, std::vector<float>, std::vector<char>> init_values; // 用于存储初始化值
                            //解析id.type,获取数组的基本类型,并对init_values进行初始化
                            std::string base_type = current_id->type.substr(0, current_id->type.find('['));
                            if(base_type == "int")
                            {
                                init_values = std::vector<int>(); // 初始化为int类型的vector
                            }
                            else if(base_type == "float")
                            {
                                init_values = std::vector<float>(); // 初始化为float类型的vector
                            }
                            else if(base_type == "char")
                            {
                                init_values = std::vector<char>(); // 初始化为char类型的vector
                            }
                            else
                            {
                                throw std::runtime_error("Unsupported array base type: " + base_type);
                            }
                            ast_node* init_value_node = node.children.back().get(); // 获取初始化值子节点
                            //按先序遍历init_value_node的子树,将所有constant_expression类型的节点的值存入init_values
                            std::function<void(ast_node*)> traverse = [&](ast_node* n) {
                                if(n->name == "constant_expression") // 如果是constant_expression类型的节点
                                {
                                    if(base_type == "int")
                                    {
                                        std::get<std::vector<int>>(init_values).push_back(std::get<int>(calculate_constant_expression_value(*n,base_type))); // 将值存入int类型的vector
                                    }
                                    else if(base_type == "float")
                                    {
                                        std::get<std::vector<float>>(init_values).push_back(std::get<float>(calculate_constant_expression_value(*n,base_type))); // 将值存入float类型的vector
                                    }
                                    else if(base_type == "char")
                                    {
                                        std::get<std::vector<char>>(init_values).push_back(std::get<char>(calculate_constant_expression_value(*n,base_type))); // 将值存入char类型的vector
                                    }
                                }
                                for(auto &child : n->children) // 遍历子节点
                                {
                                    traverse(child.get()); // 递归调用
                                }
                            };
                            traverse(init_value_node); // 从初始化值节点开始遍历
                            //根据init_values的大小,生成对应数量的store指令
                            if(base_type == "int")
                            {
                                auto &vec = std::get<std::vector<int>>(init_values);
                                for(size_t i = 0; i < vec.size(); ++i)
                                {
                                    // %tmp = getelementptr i32, i32* %id, i32 i
                                    std::string gep = "%tmp_reg_" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                        " = getelementptr i32, i32* %id_" + std::to_string(current_id->id_index) + ", i32 " + std::to_string(i) + "\n";
                                    std::string store = "store i32 " + std::to_string(vec[i]) + ", i32* %tmp_reg_" +
                                        std::to_string(current_id->id_index) + "_" + std::to_string(i) + ", align 4\n";
                                    ir_code_2 += gep + store;
                                }
                            }
                            else if(base_type == "float")
                            {
                                auto &vec = std::get<std::vector<float>>(init_values);
                                for(size_t i = 0; i < vec.size(); ++i)
                                {
                                    // %tmp = getelementptr float, float* %id, i32 i
                                    std::string gep = "%tmp_reg_" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                        " = getelementptr float, float* %id_" + std::to_string(current_id->id_index) + ", i32 " + std::to_string(i) + "\n";
                                    std::string store = "store float " + std::to_string(vec[i]) + ", float* %tmp_reg_" +
                                        std::to_string(current_id->id_index) + "_" + std::to_string(i) + ", align 4\n";
                                    ir_code_2 += gep + store;
                                }
                            }
                            else if(base_type == "char")
                            {
                                auto &vec = std::get<std::vector<char>>(init_values);
                                for(size_t i = 0; i < vec.size(); ++i)
                                {
                                    // %tmp = getelementptr i8, i8* %id, i32 i
                                    std::string gep = "%tmp_reg_" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                        " = getelementptr i8, i8* %id_" + std::to_string(current_id->id_index) + ", i32 " + std::to_string(i) + "\n";
                                    std::string store = "store i8 " + std::to_string(static_cast<int>(vec[i])) + ", i8* %tmp_reg_" +
                                        std::to_string(current_id->id_index) + "_" + std::to_string(i) + ", align 1\n";
                                    ir_code_2 += gep + store;
                                }
                            }
                            if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                            {
                                if(base_type == "int")
                                {
                                    current_id->const_value = std::get<std::vector<int>>(init_values);
                                }
                                else if(base_type == "float")
                                {
                                    current_id->const_value = std::get<std::vector<float>>(init_values);
                                }
                                else if(base_type == "char")
                                {
                                    current_id->const_value = std::get<std::vector<char>>(init_values);
                                }
                            }
                        }
                    }
                    else
                    {
                        // 否则进行隐式初始化
                        if(current_id->type == "int")
                        {
                            ir_code_2 = "store i32 0, i32* %id_" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为0
                            if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                            {
                                current_id->const_value = 0;
                            }
                        }
                        else if(current_id->type == "float")
                        {
                            ir_code_2 = "store float 0.0, float* %id_" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为0.0
                            if(current_id->kind == IdKind::Const)
                            {
                                current_id->const_value = 0.0f;
                            }
                        }
                        else if(current_id->type == "char")
                        {
                            ir_code_2 = "store i8 0, i8* %id_" + std::to_string(current_id->id_index) + ", align 1\n"; // 初始化为'\0'
                            if(current_id->kind == IdKind::Const)
                            {
                                current_id->const_value = '\0';
                            }
                        }
                        // 访问未初始化的数组是未定义的行为,这里我们不对其进行隐式初始化
                    }
                    node.ir_code = ir_code_1 + ir_code_2; // 将ir_code赋给当前节点
                }
                // 否则定义全局变量
                else
                {
                    current_id->is_global = true; // 设置为全局变量
                    if (current_id->type == "int")
                    {
                        // 由于全局变量必须初始化,我们首先找到初始化的值
                        int init_value = std::get<int>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        // 生成全局变量的IR代码
                        std::string ir_code = "@id_" + std::to_string(current_id->id_index) + " = global i32 " + std::to_string(init_value) + ", align 4\n";
                        node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                        // 如果是常量,则将const_value字段也设置为初始化值
                        if(current_id->kind == IdKind::Const) 
                        {
                            current_id->const_value = init_value; // 设置常量的初始值
                        }
                    }
                    else if(current_id->type == "float")
                    {
                        // 由于全局变量必须初始化,我们首先找到初始化的值
                        float init_value = std::get<float>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        // 生成全局变量的IR代码
                        std::string ir_code = "@id_" + std::to_string(current_id->id_index) + " = global float " + std::to_string(init_value) + ", align 4\n";
                        node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                        // 如果是常量,则将const_value字段也设置为初始化值
                        if(current_id->kind == IdKind::Const) 
                        {
                            current_id->const_value = init_value; // 设置常量的初始值
                        }
                    }
                    else if(current_id->type == "char")
                    {
                        // 由于全局变量必须初始化,我们首先找到初始化的值
                        char init_value = std::get<char>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        // 生成全局变量的IR代码
                        std::string ir_code = "@id_" + std::to_string(current_id->id_index) + " = global i8 " + std::to_string(static_cast<int>(init_value)) + ", align 1\n";
                        node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                        // 如果是常量,则将const_value字段也设置为初始化值
                        if(current_id->kind == IdKind::Const) 
                        {
                            current_id->const_value = init_value; // 设置常量的初始值
                        }
                    }
                    else // 数组类型
                    {
                        // 对于数组类型,我们需要将其初始化为一个全局数组 对于多维数组,我们将其展开来做初始化
                        // 例如对于float c[2][2] = {{1.1,2.2},{3.3,4.4}};
                        // 我们将其初始化为@c = global [4 x float] [float 1.1, float 2.2, float 3.3, float 4.4], align 16
                        std::variant<std::vector<int>, std::vector<float>, std::vector<char>> init_values; // 用于存储初始化值
                        //解析id.type,获取数组的基本类型,并对init_values进行初始化
                        std::string base_type = current_id->type.substr(0, current_id->type.find('['));
                        if(base_type == "int")
                        {
                            init_values = std::vector<int>(); // 初始化为int类型的vector
                        }
                        else if(base_type == "float")
                        {
                            init_values = std::vector<float>(); // 初始化为float类型的vector
                        }
                        else if(base_type == "char")
                        {
                            init_values = std::vector<char>(); // 初始化为char类型的vector
                        }
                        else
                        {
                            throw std::runtime_error("Unsupported array base type: " + base_type);
                        }
                        ast_node* init_value_node = node.children.back().get(); // 获取初始化值子节点
                        //按先序遍历init_value_node的子树,将所有constant_expression类型的节点的值存入init_values
                        std::function<void(ast_node*)> traverse = [&](ast_node* n) {
                            if(n->name == "constant_expression") // 如果是constant_expression类型的节点
                            {
                                if(base_type == "int")
                                {
                                    std::get<std::vector<int>>(init_values).push_back(std::get<int>(calculate_constant_expression_value(*n,base_type))); // 将值存入int类型的vector
                                }
                                else if(base_type == "float")
                                {
                                    std::get<std::vector<float>>(init_values).push_back(std::get<float>(calculate_constant_expression_value(*n,base_type))); // 将值存入float类型的vector
                                }
                                else if(base_type == "char")
                                {
                                    std::get<std::vector<char>>(init_values).push_back(std::get<char>(calculate_constant_expression_value(*n,base_type))); // 将值存入char类型的vector
                                }
                            }
                            for(auto &child : n->children) // 遍历子节点
                            {
                                traverse(child.get()); // 递归调用
                            }
                        };
                        traverse(init_value_node); // 从初始化值节点开始遍历
                        //将init_values中的值转换为LLVM全局数组的初始化格式
                        std::string ir_code_1="";
                        std::string ir_code_2="";
                        if(base_type == "int")
                        {
                            ir_code_1 = "@id_" + std::to_string(current_id->id_index) + " = global [" + std::to_string(std::get<std::vector<int>>(init_values).size()) + " x i32] ";
                            // 遍历init_values中的值,生成初始化数组的IR代码
                            ir_code_2 = "[";
                            for(size_t i = 0; i < std::get<std::vector<int>>(init_values).size(); ++i)
                            {
                                ir_code_2 += "i32 " + std::to_string(std::get<std::vector<int>>(init_values)[i]);
                                if(i < std::get<std::vector<int>>(init_values).size() - 1)
                                {
                                    ir_code_2 += ", ";
                                }
                            }
                            ir_code_2 += "], align 16\n"; // 添加右方括号和对齐信息
                            node.ir_code = ir_code_1 + ir_code_2; // 将生成的IR代码赋给当前节点
                        }
                        else if(base_type == "float")
                        {
                            ir_code_1 = "@id_" + std::to_string(current_id->id_index) + " = global [" + std::to_string(std::get<std::vector<float>>(init_values).size()) + " x float] ";
                            // 遍历init_values中的值,生成初始化数组的IR代码
                            ir_code_2 = "[";
                            for(size_t i = 0; i < std::get<std::vector<float>>(init_values).size(); ++i)
                            {
                                ir_code_2 += "float " + std::to_string(std::get<std::vector<float>>(init_values)[i]);
                                if(i < std::get<std::vector<float>>(init_values).size() - 1)
                                {
                                    ir_code_2 += ", ";
                                }
                            }
                            ir_code_2 += "], align 16\n"; // 添加右方括号和对齐信息
                            node.ir_code = ir_code_1 + ir_code_2; // 将生成的IR代码赋给当前节点
                        }
                        else if(base_type == "char")
                        {
                            ir_code_1 = "@id_" + std::to_string(current_id->id_index) + " = global [" + std::to_string(std::get<std::vector<char>>(init_values).size()) + " x i8] ";
                            // 遍历init_values中的值,生成初始化数组的IR代码
                            ir_code_2 = "[";
                            for(size_t i = 0; i < std::get<std::vector<char>>(init_values).size(); ++i)
                            {
                                ir_code_2 += "i8 " + std::to_string(static_cast<int>(std::get<std::vector<char>>(init_values)[i]));
                                if(i < std::get<std::vector<char>>(init_values).size() - 1)
                                {
                                    ir_code_2 += ", ";
                                }
                            }
                            ir_code_2 += "], align 16\n"; // 添加右方括号和对齐信息
                            node.ir_code = ir_code_1 + ir_code_2; // 将生成的IR代码赋给当前节点
                        }
                        if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                        {
                            if(base_type == "int")
                            {
                                current_id->const_value = std::get<std::vector<int>>(init_values);
                            }
                            else if(base_type == "float")
                            {
                                current_id->const_value = std::get<std::vector<float>>(init_values);
                            }
                            else if(base_type == "char")
                            {
                                current_id->const_value = std::get<std::vector<char>>(init_values);
                            }
                        }
                    }
                }
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

    // 计算数组的总大小 将多维数组展平为一维数组
    // 将如 "int[2][3][4]" 的总大小计算为 2*3*4=24
    int calculate_array_total_size(const std::string& type_str)
    {
        std::regex array_regex(R"(\[(\d+)\])");
        std::smatch match;
        std::string s = type_str;
        int total_size = 1;

        // 提取所有维度并相乘
        while (std::regex_search(s, match, array_regex)) {
            total_size *= std::stoi(match[1]);
            s = match.suffix();
        }
        return total_size;
    }

    // 将Cact类型转换为LLVM一维数组类型 用于数组变量的声明
    // 将如 "int[2][3][4]" 转为 "[24 x i32]"
    std::string to_llvm_array_type(const std::string& type_str)
    {
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
        
        int total_size = calculate_array_total_size(type_str);
        std::string result = "[" + std::to_string(total_size) + " x " + base_type + "]";
        return result + ", align 16\n";
    }


    // 计算单个number的值的函数,接受一个number节点,返回该节点的值
    // 对于char类型,支持转义字符'\n' '\t' '\\' ''' '"' '\0'
    std::variant<int, float, char> calculate_number_value(const ast_node &node) 
    {
        std::string value_str = node.cact_code; // 获取节点的cact代码片段
        if(node.children[0]->name == "IntegerConstant") 
        {
            // 支持十六进制、八进制和十进制
            int result;
            if (value_str.length() > 2 && (value_str.substr(0, 2) == "0x" || value_str.substr(0, 2) == "0X")) {
                // 十六进制
                result = std::stoi(value_str, nullptr, 16);
            } else if (value_str.length() > 1 && value_str[0] == '0' && value_str != "0") {
                // 八进制
                result = std::stoi(value_str, nullptr, 8);
            } else {
                // 十进制
                result = std::stoi(value_str, nullptr, 10);
            }
            return result;
        } 
        else if(node.children[0]->name == "FloatConstant") 
        {
            // 支持十进制和十六进制浮点数
            // 十六进制浮点数形如 0x1.921fb6p+1 或 0x.AP-3
            if ((value_str.find("0x") == 0 || value_str.find("0X") == 0) &&
                (value_str.find('p') != std::string::npos || value_str.find('P') != std::string::npos))
            {
                // C++17及以上的strtof支持十六进制浮点数
                return strtof(value_str.c_str(), nullptr);
            }
            else
            {
                // 普通十进制浮点数
                return std::stof(value_str);
            }
        } 
        else if(node.children[0]->name == "CharConstant") 
        {
            if (value_str.length() == 3 && value_str[0] == '\'' && value_str[2] == '\'') 
            {
                // 处理转义字符
                if (value_str[1] == 'n') return '\n';
                else if (value_str[1] == 't') return '\t';
                else if (value_str[1] == '\\') return '\\';
                else if (value_str[1] == '\'') return '\'';
                else if (value_str[1] == '"') return '"';
                else if (value_str[1] == '0') return '\0'; // 空字符
                else return value_str[1]; // 返回单个字符
            } 
            else if (value_str.length() == 2 && value_str[0] == '\'' && value_str[1] == '\'') 
            {
                return '\0'; // 空字符
            } 
            else 
            {
                throw std::runtime_error("Invalid character constant: " + value_str);
            }
        } 
        else {
            throw std::runtime_error("Unknown number type: " + node.cact_code);
        }

    }

    // 计算一个constant_expression的值的函数,除了单个number以外,这个常量表达式至多含有一个取反表达式
    // 传入一个constant_expression节点和该表达式应有的类型,返回表达式值
    std::variant<int, float, char> calculate_constant_expression_value(const ast_node &node, std::string type) 
    {
        if(node.name == "constant_expression") 
        {
            // 递归遍历所有子节点,如果找到一个Minus节点,则认为需要对number的值取反
            bool if_minus = false;
            //递归寻找子节点,直到找到number类型的节点
            ast_node* number_node = node.children.back().get(); // 获取子节点
            while(number_node->name != "number")
            {
                if(number_node->children.size() == 1)
                {
                    number_node = number_node->children.back().get(); // 继续向下查找
                }
                else if(number_node->children.size() == 2)
                {
                    if_minus = true; // 找到Minus节点
                    number_node = number_node->children.back().get(); // 继续向下查找
                }
                else
                {
                    throw std::runtime_error("Expected a number node for initialization on node"+ std::to_string(node.node_index));
                }
            }
            if(type == "int")
            {
                int init_value = std::get<int>(calculate_number_value(*number_node)); // 计算初始化值
                if(if_minus) {
                    init_value = -init_value; // 如果是取反表达式,则取反
                }
                return init_value; // 返回整数值
            }
            else if(type == "float")
            {
                float init_value = std::get<float>(calculate_number_value(*number_node)); // 计算初始化值
                if(if_minus) {
                    init_value = -init_value; // 如果是取反表达式,则取反
                }
                return init_value; // 返回浮点数值
            }
            else if(type == "char")
            {
                char init_value = std::get<char>(calculate_number_value(*number_node)); // 计算初始化值
                if(if_minus) {
                    throw std::runtime_error("Cannot negate a character constant: " + node.cact_code);
                }
                return init_value; // 返回字符值
            }
            else {
                throw std::runtime_error("Unsupported constant expression type: " + type);
            }
        }
        else {
            throw std::runtime_error("Invalid constant expression: " + node.name);
        }
    }

    // 计算一个任意的变量表达式的值,接受一个expression节点,将ir_code添加到节点的属性上同时返回
    // 每一个表达式类节点用于暂存结果的寄存器名称应当为"%node_index"
    // 这里因为比较繁琐,就不检查传入的节点类型是否正确了
    // 这个函数应当从expression或condition节点开始递归,当从expression开始时,type可能是int float char,当从condition开始时,type可能是bool
    // 但凡事也有例外(悲)
    std::string calculate_expression_value(ast_node &node, std::string type)
    {
        // 将当前节点的name及type打印在屏幕上
        // printf("Calculating expression for node %d: %s with type %s\n", node.node_index, node.name.c_str(), type.c_str());
        auto [reg_type, reg_align] = get_reg_type_and_align(type);
        std::string ir_code = ""; // 用于存储当前节点的IR代码
        if(node.name == "expression")
        {
            // 根据推导式 expression: additive_expression; 知,expression节点的子节点只有一个,即additive_expression
            ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        else if(node.name == "condition")
        {
            // 根据推导式 condition: logical_or_expression; 知,condition节点的子节点只有一个,即logical_or_expression
            ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        else if(node.name == "logical_or_expression")
        {
            // 根据推导式 logical_or_expression: logical_and_expression | logical_or_expression LogicalOr logical_and_expression;
            // 如果子节点只有logical_and_expression,则直接重用子节点的ir_code
            if(node.children.size() == 1 && node.children[0]->name == "logical_and_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 直接重用子节点的ir_code
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 logical_or_expression "||" logical_and_expression
            // 实现短路机制：如果左侧为真，则不计算右侧
            else
            {
                // 生成标签
                std::string left_label = "or_left_" + std::to_string(node.node_index);
                std::string right_label = "or_right_" + std::to_string(node.node_index);
                std::string end_label = "or_end_" + std::to_string(node.node_index);
                std::string current_reg_name = "%reg" + std::to_string(node.node_index);
                
                // 首先跳转到左侧计算块
                std::string initial_br = "br label %" + left_label + "\n";
                
                // 计算左侧逻辑表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type);
                std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index);
                
                // 创建左侧计算块
                std::string left_block = left_label + ":\n" + left_ir_code;
                
                // 如果左侧为真，直接跳到结束；否则计算右侧
                std::string br_inst = "br i1 " + left_reg_name + ", label %" + end_label + ", label %" + right_label + "\n";
                
                // 右侧计算块
                std::string right_ir_code = calculate_expression_value(*node.children[2], type);
                std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index);
                std::string right_block = right_label + ":\n" + right_ir_code + "br label %" + end_label + "\n";
                
                // 结束块，使用phi指令选择结果
                std::string phi_inst = end_label + ":\n" + current_reg_name + " = phi i1 [true, %" + left_label + "], [" + right_reg_name + ", %" + right_label + "]\n";
                
                ir_code = initial_br + left_block + br_inst + right_block + phi_inst;
                node.ir_code = ir_code;
                return ir_code;
            }
        }
        else if(node.name == "logical_and_expression")
        {
            // 根据推导式logical_and_expression: equal_expression | logical_and_expression LogicalAnd equal_expression;
            // 如果子节点只有equal_expression,则直接重用子节点的ir_code
            if(node.children.size() == 1 && node.children[0]->name == "equal_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 直接重用子节点的ir_code
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 logical_and_expression "&&" equal_expression
            // 实现短路机制：如果左侧为假，则不计算右侧
            else
            {
                // 生成标签
                std::string left_label = "and_left_" + std::to_string(node.node_index);
                std::string right_label = "and_right_" + std::to_string(node.node_index);
                std::string end_label = "and_end_" + std::to_string(node.node_index);
                std::string current_reg_name = "%reg" + std::to_string(node.node_index);
                
                // 首先跳转到左侧计算块
                std::string initial_br = "br label %" + left_label + "\n";
                
                // 计算左侧逻辑表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type);
                std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index);
                
                // 创建左侧计算块
                std::string left_block = left_label + ":\n" + left_ir_code;
                
                // 如果左侧为假，直接跳到结束；否则计算右侧
                std::string br_inst = "br i1 " + left_reg_name + ", label %" + right_label + ", label %" + end_label + "\n";
                
                // 右侧计算块
                std::string right_ir_code = calculate_expression_value(*node.children[2], type);
                std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index);
                std::string right_block = right_label + ":\n" + right_ir_code + "br label %" + end_label + "\n";
                
                // 结束块，使用phi指令选择结果
                std::string phi_inst = end_label + ":\n" + current_reg_name + " = phi i1 [false, %" + left_label + "], [" + right_reg_name + ", %" + right_label + "]\n";
                
                ir_code = initial_br + left_block + br_inst + right_block + phi_inst;
                node.ir_code = ir_code;
                return ir_code;
            }
        }
        else if(node.name == "equal_expression")
        {
            // 根据推导式equal_expression: relational_expression | equal_expression (LogicalEqual | NotEqual) relational_expression;
            // 如果子节点只有relational_expression,则直接重用子节点的ir_code
            if(node.children.size() == 1 && node.children[0]->name == "relational_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 直接重用子节点的ir_code
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 equal_expression (LogicalEqual | NotEqual) relational_expression
            // 此时,左右两个逻辑表达式都被直接看做算术表达式,因此传入的type应当是int float char之一
            else
            {
                // 首先检查左右两个关系表达式的类型
                std::string child_type_l = get_arithmetic_expression_type(*node.children[0]); // 获取左侧子节点的类型
                std::string child_type_r = get_arithmetic_expression_type(*node.children[2]); // 获取右侧子节点的类型
                if(child_type_l != child_type_r) // 如果左右子节点的类型不一致,则报错
                {
                    throw std::runtime_error("Type mismatch in equal_expression: " + child_type_l + " vs " + child_type_r);
                }
                // 分别计算前后两个关系表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], child_type_l); // 计算左侧关系表达式的值
                std::string right_ir_code = calculate_expression_value(*node.children[2], child_type_r); // 计算右侧关系表达式的值
                // 生成临时寄存器名称
                std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                auto [reg_type, reg_align] = get_reg_type_and_align(child_type_l); // 获取寄存器类型和对齐方式并覆盖上层变量
                // 根据操作符和左右子节点的数据类型生成对应的比较指令，直接使用子节点的值寄存器
                std::string cmp_inst;
                std::string op = node.children[1]->cact_code; // 获取操作符
                if(child_type_l == "int")
                {
                    if(op == "==") // 如果是等于操作符
                    {
                        cmp_inst = current_reg_name + " = icmp eq " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = current_reg_name + " = icmp ne " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成不等于比较指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in equal_expression: " + op);
                    }
                }
                else if(child_type_l == "float")
                {
                    if(op == "==") // 如果是等于操作符
                    {
                        cmp_inst = current_reg_name + " = fcmp oeq " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = current_reg_name + " = fcmp one " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成不等于比较指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in equal_expression: " + op);
                    }
                }
                else if(child_type_l == "char")
                {
                    if(op == "==") // 如果是等于操作符
                    {
                        cmp_inst = current_reg_name + " = icmp eq i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = current_reg_name + " = icmp ne i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成不等于比较指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in equal_expression: " + op);
                    }
                }
                else
                {
                    throw std::runtime_error("Unsupported type in equal_expression: " + child_type_l);
                }
                ir_code = left_ir_code + right_ir_code + cmp_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        else if(node.name == "relational_expression")
        {
            // 对于relational_expression节点 我们需要先获取其additive_expression子节点的数据类型,以便于求子节点的ir_code
            // 该节点中存储的指针有多种情况
            // 对于形如"a<b"的结点,我们存储bool类型(即i1) 同时其两个relational_expression子节点a和b均存储int类型
            // 如果是单独的一个"a"节点 我们将这里面存储的int类型转成bool类型后存储
            if(node.children.size() == 1 && node.children[0]->name == "additive_expression" && node.parent != nullptr && node.parent->name != "relational_expression")
            {
                std::string ir_code = ""; // 用于存储当前节点的IR代码
                std::string ir_code_from_child = calculate_expression_value(*node.children[0], "int"); // 先生成子节点的ir_code,子节点的数据类型为int
                // 将子节点临时寄存器中的表达式值转换为bool类型
                std::string child_reg_name = "%reg" + std::to_string(node.children[0]->node_index); // 子节点的临时寄存器名称
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                // 判断子节点的值是否不为0，直接使用子节点的值寄存器
                std::string cmp_inst = current_reg_name + " = icmp ne i32 " + child_reg_name + ", 0\n";
                ir_code = ir_code_from_child + cmp_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // // 否则 该relational_expression节点是作为某个relational_expression的子节点存在的
            else
            {
                // 如果只有一个additive_expression子节点,那么我们先确认子节点的类型,然后生成其IR代码并赋给当前节点
                if(node.children.size() == 1 && node.children[0]->name == "additive_expression")
                {
                    std::string child_type = get_arithmetic_expression_type(*node.children[0]); // 获取子节点的基本类型
                    ir_code = exp_gen_ir_code_from_child(node, child_type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
                // 否则,说明该节点有三个子节点,即 relational_expression (RelationalOp) additive_expression
                // 此时,左右两个算术表达式都被直接看做算术表达式,因此传入的type应当是int float char之一
                // 左子节点会自行判断其数据类型,我们此处需要找到右子节点该有的数据类型
                else
                {
                    std::string child_type_l = get_arithmetic_expression_type(*node.children[0]); // 获取左侧子节点的类型
                    std::string child_type_r = get_arithmetic_expression_type(*node.children[2]); // 获取右侧子节点的类型
                    // 分别计算前后两个算术表达式的值 对于左子结点,其会自行判断数据类型
                    std::string left_ir_code = calculate_expression_value(*node.children[0], child_type_l);
                    std::string right_ir_code = calculate_expression_value(*node.children[2], child_type_r);
                    // 生成临时寄存器名称
                    std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                    std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                    std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                    auto [reg_type, reg_align] = get_reg_type_and_align(child_type_r); // 获取寄存器类型和对齐方式并覆盖上层变量
                    // 根据操作符和左右子节点的数据类型生成对应的比较指令，直接使用子节点的值寄存器
                    std::string cmp_inst;
                    std::string op = node.children[1]->cact_code; // 获取操作符
                    if(child_type_r == "int")
                    {
                        if(op == "<") // 如果是小于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp slt " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于比较指令
                        }
                        else if(op == "<=") // 如果是小于等于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sle " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于等于比较指令
                        }
                        else if(op == ">") // 如果是大于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sgt " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于比较指令
                        }
                        else if(op == ">=") // 如果是大于等于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sge " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于等于比较指令
                        }
                        else
                        {
                            throw std::runtime_error("Unsupported operator in relational_expression: " + op);
                        }
                    }
                    else if(child_type_r == "float")
                    {
                        if(op == "<") // 如果是小于操作符
                        {
                            cmp_inst = current_reg_name + " = fcmp olt " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于比较指令
                        }
                        else if(op == "<=") // 如果是小于等于操作符
                        {
                            cmp_inst = current_reg_name + " = fcmp ole " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于等于比较指令
                        }
                        else if(op == ">") // 如果是大于操作符
                        {
                            cmp_inst = current_reg_name + " = fcmp ogt " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于比较指令
                        }
                        else if(op == ">=") // 如果是大于等于操作符
                        {
                            cmp_inst = current_reg_name + " = fcmp oge " + reg_type + " " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于等于比较指令
                        }
                        else
                        {
                            throw std::runtime_error("Unsupported operator in relational_expression: " + op);
                        }
                    }
                    else if(child_type_r == "char")
                    {
                        if(op == "<") // 如果是小于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp slt i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于比较指令
                        }
                        else if(op == "<=") // 如果是小于等于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sle i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成小于等于比较指令
                        }
                        else if(op == ">") // 如果是大于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sgt i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于比较指令
                        }
                        else if(op == ">=") // 如果是大于等于操作符
                        {
                            cmp_inst = current_reg_name + " = icmp sge i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成大于等于比较指令
                        }
                        else
                        {
                            throw std::runtime_error("Unsupported operator in relational_expression: " + op);
                        }
                    }
                    ir_code = left_ir_code + right_ir_code + cmp_inst; // 拼接IR代码
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
            }
        }
        else if(node.name == "additive_expression")
        {
            //加法表达式的生成式是additive_expression: multiplicative_expression | additive_expression (Plus | Minus) multiplicative_expression;
            // 如果只有一个multiplicative_expression子节点,那么将子节点的ir_code赋给当前节点
            if(node.children.size() == 1 && node.children[0]->name == "multiplicative_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 additive_expression (Plus | Minus) multiplicative_expression 直接根据已知type计算其值
            else
            {
                // 分别计算左右两个算术表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type); // 计算左侧算术表达式的值
                std::string right_ir_code = calculate_expression_value(*node.children[2], type); // 计算右侧算术表达式的值
                // 生成临时寄存器名称
                std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                // 根据操作符和左右子节点的数据类型生成对应的指令，直接使用子节点的值寄存器
                std::string cmp_inst;
                std::string op = node.children[1]->cact_code; // 获取操作符
                if(type == "int")
                {
                    if(op == "+") // 如果是加法操作符
                    {
                        cmp_inst = current_reg_name + " = add i32 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成加法指令
                    }
                    else if(op == "-") // 如果是减法操作符
                    {
                        cmp_inst = current_reg_name + " = sub i32 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成减法指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in additive_expression: " + op);
                    }
                }
                else if(type == "float")
                {
                    if(op == "+") // 如果是加法操作符
                    {
                        cmp_inst = current_reg_name + " = fadd float " + left_reg_name + ", " + right_reg_name + "\n"; // 生成加法指令
                    }
                    else if(op == "-") // 如果是减法操作符
                    {
                        cmp_inst = current_reg_name + " = fsub float " + left_reg_name + ", " + right_reg_name + "\n"; // 生成减法指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in additive_expression: " + op);
                    }
                }
                else if(type == "char")
                {
                    if(op == "+") // 如果是加法操作符
                    {
                        cmp_inst = current_reg_name + " = add i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成加法指令
                    }
                    else if(op == "-") // 如果是减法操作符
                    {
                        cmp_inst = current_reg_name + " = sub i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成减法指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in additive_expression: " + op);
                    }
                }
                else
                {
                    throw std::runtime_error("Unsupported type in additive_expression: " + type);
                }
                ir_code = left_ir_code + right_ir_code + cmp_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        else if(node.name == "multiplicative_expression")
        {
            //乘法表达式的生成式是multiplicative_expression: unary_expression | multiplicative_expression (Asterisk | Slash | Percent) unary_expression;
            // 如果只有一个unary_expression子节点,那么将子节点的ir_code赋给当前节点
            if(node.children.size() == 1 && node.children[0]->name == "unary_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 multiplicative_expression (Multiply | Divide | Mod) unary_expression 直接根据已知type计算其值
            else
            {
                // 分别计算左右两个算术表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type); // 计算左侧算术表达式的值
                std::string right_ir_code = calculate_expression_value(*node.children[2], type); // 计算右侧算术表达式的值
                // 生成临时寄存器名称
                std::string left_reg_name = "%reg" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                // 根据操作符和左右子节点的数据类型生成对应的指令，直接使用子节点的值寄存器
                std::string cmp_inst;
                std::string op = node.children[1]->cact_code; // 获取操作符
                if(type == "int")
                {
                    if(op == "*") // 如果是乘法操作符
                    {
                        cmp_inst = current_reg_name + " = mul i32 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成乘法指令
                    }
                    else if(op == "/") // 如果是除法操作符
                    {
                        cmp_inst = current_reg_name + " = sdiv i32 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成除法指令
                    }
                    else if(op == "%") // 如果是取模操作符
                    {
                        cmp_inst = current_reg_name + " = srem i32 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成取模指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in multiplicative_expression: " + op);
                    }
                }
                else if(type == "float")
                {
                    if(op == "*") // 如果是乘法操作符
                    {
                        cmp_inst = current_reg_name + " = fmul float " + left_reg_name + ", " + right_reg_name + "\n"; // 生成乘法指令
                    }
                    else if(op == "/") // 如果是除法操作符
                    {
                        cmp_inst = current_reg_name + " = fdiv float " + left_reg_name + ", " + right_reg_name + "\n"; // 生成除法指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in multiplicative_expression: " + op);
                    }
                }
                else if(type == "char")
                {
                    if(op == "*") // 如果是乘法操作符
                    {
                        cmp_inst = current_reg_name + " = mul i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成乘法指令
                    }
                    else if(op == "/") // 如果是除法操作符
                    {
                        cmp_inst = current_reg_name + " = sdiv i8 " + left_reg_name + ", " + right_reg_name + "\n"; // 生成除法指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in multiplicative_expression: " + op);
                    }
                }
                else
                {
                    throw std::runtime_error("Unsupported type in multiplicative_expression: " + type);
                }
                ir_code = left_ir_code + right_ir_code + cmp_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        else if(node.name == "unary_expression")
        {
            //一元表达式的生成式是unary_expression: primary_expression | (Plus | Minus | ExclamationMark) unary_expression | Identifier LeftParenthesis (function_real_params)? RightParenthesis;
            // 如果只有一个primary_expression子节点,那么将子节点的ir_code赋给当前节点
            if(node.children.size() == 1 && node.children[0]->name == "primary_expression")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 如果第一个子节点是Identifier 说明是函数调用
            else if(node.children.size() > 1 && node.children[0]->name == "Identifier")
            {
                // 生成函数调用的IR代码
                identifier* func_id = find_identifier_in_scope(node,node.children[0]->cact_code); // 在当前作用域中查找函数标识符
                auto [reg_type, reg_align] = get_reg_type_and_align(func_id->func_return_type); // 获取寄存器类型和对齐方式
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                // 如果函数不含有参数 则直接调用
                if(node.children[2]->name != "function_real_params")
                {
                    if(reg_type == "void"){ // 如果函数返回类型是void
                        ir_code = "call void @" + func_id->name + "()\n"; // 生成函数调用的IR代码
                    }
                    else{ // 如果函数返回类型不是void
                        ir_code = current_reg_name + " = call " + reg_type + " @" + func_id->name + "()\n"; // 生成函数调用的IR代码
                    }
                    ir_code = current_reg_name + " = call " + reg_type + " @" + func_id->name + "()\n"; // 生成函数调用的IR代码
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
                // 否则处理函数参数
                {
                    std::string call_ir_code;
                    if(reg_type == "void"){ // 如果函数返回类型是void
                        call_ir_code = "call void @" + func_id->name + "(";
                    }
                    else{
                        call_ir_code = current_reg_name + " = call " + reg_type + " @" + func_id->name + "(";
                    }
                    // 接下来,我们遍历function_real_params的子节点,每个找到的expression子节点对应一个函数实参
                    // 直接使用expression子节点的值寄存器作为函数参数
                    std::vector<std::string> func_param_regs; // 用于存储函数实参的寄存器名称
                    std::string func_params_ir_code = ""; // 用于存储函数实参的IR代码
                    for(auto &child:node.children[2]->children) // 遍历function_real_params的子节点
                    {
                        if(child->name == "expression") // 如果子节点是expression
                        {
                            std::string child_type = get_arithmetic_expression_type(*child); // 获取子节点的基本类型
                            std::string child_ir_code = calculate_expression_value(*child, child_type); // 计算子节点的值并生成IR代码
                            std::string child_reg_name = "%reg" + std::to_string(child->node_index); // 子节点的临时寄存器名称
                            func_params_ir_code += child_ir_code; // 拼接IR代码
                            // 直接使用子节点的值寄存器
                            func_param_regs.push_back(child_reg_name);
                        }
                    }
                    // 将函数实参的寄存器名称拼接到函数调用的IR代码中
                    // 这里我们期望func_param_regs中的每个寄存器都与func_id->func_params中的参数类型一一对应
                    // 如果func_params中的某个参数是数组类型,则在LLVMIR中解释为ptr类型
                    for(size_t i = 0; i < func_param_regs.size(); ++i)
                    {
                        if(i > 0) call_ir_code += ", "; // 如果不是第一个参数,则添加逗号分隔
                        if(func_id->func_params[i].type == "int")
                        {
                            call_ir_code += "i32 "; // 如果参数类型是int,则添加i32
                        }
                        else if(func_id->func_params[i].type == "float")
                        {
                            call_ir_code += "float "; // 如果参数类型是float,则添加float
                        }
                        else if(func_id->func_params[i].type == "char")
                        {
                            call_ir_code += "i8 "; // 如果参数类型是char,则添加i8
                        }
                        else
                        {
                            // 如果参数类型是数组,根据数组元素类型确定指针类型
                            std::string param_type = func_id->func_params[i].type;
                            if (param_type.find("int") != std::string::npos) 
                            {
                                call_ir_code += "i32* "; // int数组参数使用i32*
                            }
                            else if (param_type.find("float") != std::string::npos) 
                            {
                                call_ir_code += "float* "; // float数组参数使用float*
                            }
                            else if (param_type.find("char") != std::string::npos) 
                            {
                                call_ir_code += "i8* "; // char数组参数使用i8*
                            }
                            else 
                            {
                                call_ir_code += "ptr "; // 其他情况保持原样
                            }
                        }
                        call_ir_code += func_param_regs[i]; // 添加函数实参寄存器名称
                    }
                    call_ir_code += ")\n"; // 结束函数调用的IR代码
                    ir_code = func_params_ir_code + call_ir_code; // 拼接IR代码
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
            }
            // 其余情况下 说明该节点有两个子节点,即 (Plus | Minus | ExclamationMark) unary_expression
            else
            {
                std::string op = node.children[0]->cact_code; // 获取操作符
                // 如果op是"+" 则只当无事发生
                if(op == "+")
                {
                    ir_code = exp_gen_ir_code_from_child(node, type, 1); // 直接重用子节点的ir_code
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
                // 如果op是"-" 则需要根据子节点的数据类型,进行对应的取反操作后赋给当前节点
                else if(op == "-")
                {
                    std::string ir_code = ""; // 用于存储当前节点的IR代码
                    std::string ir_code_from_child = calculate_expression_value(*node.children[1], type); // 先生成子节点的ir_code
                    // 直接使用子节点的值寄存器进行取反操作
                    std::string child_reg_name = "%reg" + std::to_string(node.children[1]->node_index); // 子节点的临时寄存器名称
                    std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                    // 将子节点的值取反
                    std::string assign_ir_code;
                    if(type == "int") // 如果是整数类型
                    {
                        assign_ir_code = current_reg_name + " = sub i32 0, " + child_reg_name + "\n"; // 生成整数取反指令
                    }
                    else if(type == "float") // 如果是浮点数类型
                    {
                        assign_ir_code = current_reg_name + " = fsub float 0.0, " + child_reg_name + "\n"; // 生成浮点数取反指令
                    }
                    else if(type == "char") // 如果是字符类型
                    {
                        assign_ir_code = current_reg_name + " = sub i8 0, " + child_reg_name + "\n"; // 生成字符取反指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported type in unary_expression: " + type);
                    }
                    ir_code = ir_code_from_child + assign_ir_code; // 拼接IR代码
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
                // 如果op是"!" 那么我们默认子节点的数据类型是int 而当前节点的数据类型也设定为int
                // 直接使用子节点的值寄存器进行比较
                else if(op == "!")
                {
                    std::string ir_code = ""; // 用于存储当前节点的IR代码
                    std::string ir_code_from_child = calculate_expression_value(*node.children[1], "int"); // 先生成子节点的ir_code,子节点的数据类型为int
                    // 直接使用子节点的值寄存器
                    std::string child_reg_name = "%reg" + std::to_string(node.children[1]->node_index); // 子节点的临时寄存器名称
                    std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                    // 判断子节点的值是否为0，如果是0则为true,否则为false
                    std::string cmp_inst = current_reg_name + "_i1 = icmp eq i32 " + child_reg_name + ", 0\n";
                    // 将i1类型拓展为i32类型
                    std::string extend_inst = current_reg_name + " = zext i1 " + current_reg_name + "_i1 to i32\n"; // 将i1类型拓展为i32类型
                    ir_code = ir_code_from_child + cmp_inst + extend_inst; // 拼接IR代码
                    node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                    return ir_code; // 返回当前节点的IR代码
                }
                else
                {
                    throw std::runtime_error("Unsupported operator in unary_expression: " + op);
                }
            }
        }
        else if(node.name == "primary_expression")
        {
            // primary_expression的生成式是primary_expression: LeftParenthesis expression RightParenthesis | left_value | number;
            // 如果有三个子节点,则说明是左括号表达式,直接重用第二个子节点的ir_code
            if(node.children.size() == 3 && node.children[0]->name == "LeftParenthesis" && node.children[2]->name == "RightParenthesis")
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 1); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则 说明子节点是left_value或number 重用该节点的ir_code
            else if(node.children.size() == 1 && (node.children[0]->name == "left_value" || node.children[0]->name == "number"))
            {
                ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            else
            {
                throw std::runtime_error("Unsupported primary_expression structure");
            }
        }
        else if(node.name == "left_value")
        {
            // left_value的生成式是 left_value: Identifier (LeftBracket expression RightBracket)*;
            // 我们分别考虑id是不是数组的两种情况
            if(node.children.size() == 1 && node.children[0]->name == "Identifier")
            {
                // 如果只有一个子节点,则说明是标识符,直接从变量寄存器加载值到当前节点的值寄存器
                identifier* id = find_identifier_in_scope(*node.children[0], node.children[0]->cact_code); // 查找标识符节点
                auto [reg_type, reg_align] = get_reg_type_and_align(type);
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的寄存器名称
                // 从标识符的寄存器加载值到当前节点的值寄存器
                std::string assign_ir_code;
                if(id->is_global == false)
                {
                    // 如果这个id是函数参数,那么直接赋值,而不是用load指令
                    if(id->kind == IdKind::Param)
                    {
                        assign_ir_code = current_reg_name + " = add " + reg_type + " 0, %id_" + std::to_string(id->id_index) + "\n"; // 从局部标识符的寄存器加载值
                    }
                    else
                    {
                        // 根据类型选择具体的指针类型
                        std::string ptr_type;
                        if (reg_type == "i32") ptr_type = "i32*";
                        else if (reg_type == "float") ptr_type = "float*";
                        else if (reg_type == "i8") ptr_type = "i8*";
                        else ptr_type = "ptr"; // 其他情况保持原样
                        assign_ir_code = current_reg_name + " = load " + reg_type + ", " + ptr_type + " %id_" + std::to_string(id->id_index) + reg_align + "\n"; // 从局部标识符的寄存器加载值
                    }
                }
                else
                {
                    // 根据类型选择具体的指针类型
                    std::string ptr_type;
                    if (reg_type == "i32") ptr_type = "i32*";
                    else if (reg_type == "float") ptr_type = "float*";
                    else if (reg_type == "i8") ptr_type = "i8*";
                    else ptr_type = "ptr"; // 其他情况保持原样
                    assign_ir_code = current_reg_name + " = load " + reg_type + ", " + ptr_type + " @id_" + std::to_string(id->id_index) + reg_align + "\n"; // 从全局标识符的寄存器加载值
                }
                node.ir_code = assign_ir_code; // 设置IR代码
                return node.ir_code; // 返回当前节点的IR代码
            }
            else if(node.children.size() > 1)
            {
                // 如果有多个子节点,说明是数组访问
                identifier* id = find_identifier_in_scope(*node.children[0], node.children[0]->cact_code); // 查找标识符节点
                // 首先获取left_value节点的cact_code 并从中分离出数组名和索引
                std::string array_name = node.children[0]->cact_code; // 数组名 如"array"
                // 将cact_code减去开头的标识符部分得到剩余的索引部分 如"[2][3]""
                std::string index_string = node.cact_code.substr(array_name.length());
                // 直接将多维数组当成一维来做 在取数组 int a[n1][n2][n3]...[nk] 的 a[i1][i2][i3]...[ik] 的值时
                // 我们将其看成一维数组 a[i1*n2*n3*...*nk + i2*n3*...*nk + i3*...*nk + ... + ik] 的值
                // 先根据Identifier的type来获取数组各维度的大小 例如当type="int[2][3][4]"时 各维度分别为 n1=2, n2=3, n3=4
                // 如果n1不存在,即函数参数中数组的最外层维度被忽略,则将其置为0
                std::vector<int> array_sizes; // 用于存储数组各维度的大小
                std::string array_type = id->type; // 获取数组的类型
                // 解析数组类型字符串,提取各维度大小
                size_t pos = 0;
                while ((pos = array_type.find('[')) != std::string::npos) 
                {
                    size_t end_pos = array_type.find(']', pos);
                    if (end_pos == std::string::npos) 
                    {
                        throw std::runtime_error("Invalid array type format: " + array_type);
                    }
                    std::string size_str = array_type.substr(pos + 1, end_pos - pos - 1); // 提取维度大小
                    if (size_str.empty()) 
                    {
                        array_sizes.push_back(0); // 如果没有指定大小,则默认为0
                    } 
                    else 
                    {
                        array_sizes.push_back(std::stoi(size_str)); // 将字符串转换为整数
                    }
                    array_type.erase(0, end_pos + 1); // 移除已处理的部分
                }
                // 类似的 从index_string中提取i1 i2 i3 ... ik的值
                std::vector<int> indices; // 用于存储索引值
                pos = 0;
                while ((pos = index_string.find('[')) != std::string::npos) 
                {
                    size_t end_pos = index_string.find(']', pos);
                    if (end_pos == std::string::npos) 
                    {
                        throw std::runtime_error("Invalid index format: " + index_string);
                    }
                    std::string index_str = index_string.substr(pos + 1, end_pos - pos - 1); // 提取索引值
                    indices.push_back(std::stoi(index_str)); // 将字符串转换为整数
                    index_string.erase(0, end_pos + 1); // 移除已处理的部分
                }
                int true_index = 0; // 用于存储计算后的真实索引
                // 计算真实索引
                for (size_t i = 0; i < indices.size(); ++i) 
                {
                    int multiplier = 1; // 用于计算当前维度的乘数
                    for (size_t j = i + 1; j < array_sizes.size(); ++j) 
                    {
                        multiplier *= array_sizes[j]; // 计算当前维度的乘数
                    }
                    true_index += indices[i] * multiplier; // 累加到真实索引
                }
                // 现在我们已经得到了真实索引,接下来生成IR代码
                auto [reg_type, reg_align] = get_reg_type_and_align(type);
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的寄存器名称
                std::string tmp_reg_name_1 = "%tmp_reg_" + std::to_string(node.node_index) + "_1"; // 临时寄存器1

                // 获取我们需要的值的地址并存入临时寄存器1
                std::string ptr_ir_code;
                // 根据类型选择具体的指针类型
                std::string ptr_type;
                if (reg_type == "i32") ptr_type = "i32*";
                else if (reg_type == "float") ptr_type = "float*";
                else if (reg_type == "i8") ptr_type = "i8*";
                else ptr_type = "ptr"; // 其他情况保持原样
                
                if(id->is_global == false)
                {
                    ptr_ir_code = tmp_reg_name_1 + " = getelementptr " + reg_type + ", " + ptr_type + " %id_" + std::to_string(id->id_index) + ", i32 " + std::to_string(true_index) + "\n"; // 计算数组元素地址
                }
                else
                {
                    ptr_ir_code = tmp_reg_name_1 + " = getelementptr " + reg_type + ", " + ptr_type + " @id_" + std::to_string(id->id_index) + ", i32 " + std::to_string(true_index) + "\n"; // 计算数组元素地址
                }
                // 将该地址的值直接加载到当前节点的值寄存器
                std::string assign_ir_code = current_reg_name + " = load " + reg_type + ", " + ptr_type + " " + tmp_reg_name_1 + reg_align + "\n";
                node.ir_code = ptr_ir_code + assign_ir_code; // 拼接IR代码
                return node.ir_code; // 返回当前节点的IR代码
            }
            else
            {
                throw std::runtime_error("Unsupported left_value structure");
            }
        }
        else if(node.name == "number")
        {
            if(type == "int")
            {
                // 先获取number节点的值
                int value = std::get<int>(calculate_number_value(node));
                // 直接将常量作为当前节点的值寄存器
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的寄存器名称
                // 直接为整数常量创建值寄存器
                std::string assign_ir_code = current_reg_name + " = add i32 0, " + std::to_string(value) + "\n"; // 创建常量值
                node.ir_code = assign_ir_code; // 设置IR代码
                return node.ir_code; // 返回当前节点的IR代码
            }
            else if(type == "float")
            {
                // 先获取number节点的值
                float value = std::get<float>(calculate_number_value(node));
                // 直接将常量作为当前节点的值寄存器
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的寄存器名称
                // 直接为浮点数常量创建值寄存器
                std::string assign_ir_code = current_reg_name + " = fadd float 0.0, " + std::to_string(value) + "\n"; // 创建常量值
                node.ir_code = assign_ir_code; // 设置IR代码
                return node.ir_code; // 返回当前节点的IR代码
            }
            else if(type == "char")
            {
                // 先获取number节点的值
                char value = std::get<char>(calculate_number_value(node));
                // 直接将常量作为当前节点的值寄存器
                std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的寄存器名称
                // 直接为字符常量创建值寄存器
                std::string assign_ir_code = current_reg_name + " = add i8 0, " + std::to_string(static_cast<int>(value)) + "\n"; // 创建常量值
                node.ir_code = assign_ir_code; // 设置IR代码
                return node.ir_code; // 返回当前节点的IR代码
            }
            else
            {
                throw std::runtime_error("Unsupported type in number: " + type);
            }
        }
        else
        {
            return ""; //暂且返回空字符串喵
        }
    }

    // 根据特定子节点，生成一个exp的ir_code并返回
    // 对于某个exp节点,如果其ir_code只跟特定的子节点有关,则直接重用子节点的值寄存器
    std::string exp_gen_ir_code_from_child(ast_node &node, std::string type, int child_index)
    {
        std::string ir_code = ""; // 用于存储当前节点的IR代码
        std::string ir_code_from_child = calculate_expression_value(*node.children[child_index], type); // 先生成子节点的ir_code
        // 直接重用子节点的值寄存器，不需要额外的load/store操作
        std::string child_reg_name = "%reg" + std::to_string(node.children[child_index]->node_index); // 子节点的临时寄存器名称
        std::string current_reg_name = "%reg" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
        // 直接将子节点的寄存器赋给当前节点
        std::string assign_ir_code = current_reg_name + " = add ";
        if(type == "int") {
            assign_ir_code += "i32 0, " + child_reg_name + "\n";
        } else if(type == "float") {
            assign_ir_code += "float 0.0, " + child_reg_name + "\n";
        } else if(type == "char") {
            assign_ir_code += "i8 0, " + child_reg_name + "\n";
        } else if(type == "bool") {
            assign_ir_code = current_reg_name + " = or i1 false, " + child_reg_name + "\n";
        } else if(type == "void") {
            assign_ir_code = ""; // void类型不需要被转存
        } else {
            throw std::runtime_error("Unsupported type in exp_gen_ir_code_from_child: " + type);
        }
        ir_code = ir_code_from_child + assign_ir_code; // 拼接IR代码
        node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
        return ir_code; // 返回当前节点的IR代码
    }

    // 获取寄存器指针类型和对齐方式的函数
    std::pair<std::string, std::string> get_reg_type_and_align(const std::string& type) 
    {
        if(type == "int") {
            return {"i32", ", align 4"};
        } else if(type == "float") {
            return {"float", ", align 4"};
        } else if(type == "char") {
            return {"i8", ", align 1"};
        } else if(type == "bool") {
            return {"i1", ", align 1"};
        } else if(type == "void") {
            return {"void", ""}; // void类型没有寄存器
        } else {
            throw std::runtime_error("Unsupported type: " + type);
        }
    }

    // 获取一个算术表达式应该是什么数据类型的函数,我们的做法是递归下降
    // 算术表达式类型节点包括expression additive_expression multiplicative_expression unary_expression primary_expression
    // 对于数组类型来说,我们获取其基本类型
    std::string get_arithmetic_expression_type(ast_node &node)
    {
        // 遍历当前表达式的子节点
        for(auto &child : node.children)
        {
            if( child->name == "expression" ||
                child->name == "additive_expression" ||
                child->name == "multiplicative_expression" ||
                child->name == "primary_expression"||  //如果子节点也是算术表达式,那么递归调用函数
                child->name == "number" ||
                child->name == "left_value") //如果子节点是number或left_value,再递归一次,其第一个子节点的类型就是我们要找的
            {
                return get_arithmetic_expression_type(*child);
            }
            else if(child->name == "unary_expression")
            {
                // 如果子节点是unary_expression,需要详细判断这个节点的类型究竟是bool还是其他数值类型
                // 如果第一个子节点的cact_code是"!" 则将其视为bool类型 其余情况不变
                if(child->children.size() > 0 && child->children[0]->cact_code == "!")
                {
                    return "bool"; // 如果是逻辑非操作符,则返回bool类型
                }
                else
                {
                    return get_arithmetic_expression_type(*child); // 否则递归调用
                }
            }
            else if(child->name == "IntegerConstant")
            {
                return "int"; // 如果子节点是整数常量,则返回int类型
            }
            else if(child->name == "FloatConstant")
            {
                return "float"; // 如果子节点是浮点数常量,则返回float类型
            }
            else if(child->name == "CharConstant")
            {
                return "char"; // 如果子节点是字符常量,则返回char类型
            }
            else if(child->name == "Identifier")
            {
                // 如果子节点是标识符,则需要查找该标识符的类型
                identifier* id = find_identifier_in_scope(*child, child->cact_code); // 查找标识符
                if(id != nullptr) // 如果找到了标识符
                {
                    if(id->type == "int" || id->type == "float" || id->type == "char") // 如果是基本类型则直接返回
                    {
                        return id->type;
                    }
                    else if(id->kind == IdKind::Func) //如果是函数,返回其返回类型
                    {
                        return id->func_return_type;
                    }
                    else // 如果是数组类型,则返回其基本类型
                    {
                        return id->type.substr(0, id->type.find('['));
                    }
                }
                else // 如果没有找到标识符,则报错
                {
                    throw std::runtime_error("Identifier not found: " + child->cact_code);
                }
            }
            else if(node.name == "equal_expression" &&
                    node.children.size() == 1 && 
                    node.children[0]->name == "relational_expression" &&
                    node.children[0]->children.size() == 1 &&
                    node.children[0]->children[0]->name == "additive_expression"
                    ) //特别地,对于equal->relational->additive这种情况,我们将这个equal逻辑表达式看做算术表达式
            {
                return get_arithmetic_expression_type(*node.children[0]->children[0]); // 递归调用,获取additive_expression的类型
            }
            //剩余情况为需要跳过的字符,如'('节点
        }
        // 如果没有找到任何符合条件的子节点,则报错
        throw std::runtime_error("No valid arithmetic expression found in node: " + node.name);
    }

    // 传入一个ast_node节点和一个标识符名称,在节点所在的作用域中查找并返回标识符指针的函数
    // 如果未找到，则回到父作用域寻找,直至全局作用域,依旧未找到则报错
    identifier* find_identifier_in_scope(ast_node &node, std::string id_name)
    {
        scope_node* current_scope = node.scope_ptr; // 获取当前作用域指针
        while(current_scope != nullptr) // 如果当前作用域不为空
        {
            // 在当前作用域中查找标识符
            for(auto &id : current_scope->identifiers) // 遍历当前作用域中的所有标识符
            {
                if(id.name == id_name) // 如果找到了匹配的标识符
                {
                    return &id; // 返回该标识符的指针
                }
            }
            current_scope = current_scope->parent; // 否则回到父作用域继续查找
        }
        // 如果在所有作用域中都没有找到标识符,则抛出异常
        throw std::runtime_error("Identifier not found in scope: " + id_name);
    }

    // 生成一个函数定义结点的相关代码
    // 传入AST根节点给该函数,然后递归地遍历AST树,当找到一个函数定义时为对应的结点生成ir_code
    void ir_gen_func_definition(ast_node &node)
    {
        if(node.name == "function_definition")
        {
            // 先获取node对应的函数标识符
            identifier* func_id = find_identifier_in_scope(node, node.children[1]->cact_code); // 在当前作用域中查找函数标识符
            auto [func_return_reg_type, func_return_reg_align] = get_reg_type_and_align(func_id->func_return_type); // 获取寄存器类型和对齐方式
            // 先完成IR的第一部分
            std::string ir_code = "define " + func_return_reg_type + " @" + func_id->name + "(";
            // 接下来根据函数的每个参数,填入IR代码
            for(size_t i = 0; i < func_id->func_params.size(); ++i)
            {
                if(i > 0) ir_code += ", "; // 如果不是第一个参数,则添加逗号分隔
                // 处理基本类型的参数
                if(func_id->func_params[i].type == "int" || func_id->func_params[i].type == "float" || func_id->func_params[i].type == "char")
                {
                    auto [param_reg_type, param_reg_align] = get_reg_type_and_align(func_id->func_params[i].type); // 获取参数寄存器类型和对齐方式
                    ir_code += param_reg_type + " %id_" + std::to_string(func_id->func_params[i].id_index); // 添加参数寄存器名称
                }
                else
                {
                    // 如果是数组类型,则在LLVMIR中解释为ptr类型
                    ir_code += "ptr %id_" + std::to_string(func_id->func_params[i].id_index); // 添加参数寄存器名称
                }
            }
            ir_code += ")\n"; // 结束函数定义的IR代码
            // 接下来,我们需要处理函数体 由于函数体总是被一个block包围,且该block是函数定义的最后一个子节点 我们直接计算block的IR代码并将其添加到函数定义之后
            // 另外别忘了花括号
            std::string block_ir_code = ir_gen_block(*node.children.back()); // 生成block的IR代码
            ir_code += "{\n"; // 开启函数体
            ir_code += "entry:\n"; // 添加entry标签
            ir_code += block_ir_code + "\n}\n"; // 将block的IR代码添加到函数定义之后
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
        }
        else
        {
            // 如果不是函数定义结点,则递归处理子节点
            for (auto &child : node.children)
            {
                ir_gen_func_definition(*child); // 递归调用
            }
        }
    }

    // 生成一个block及其内部结点的相关代码
    std::string ir_gen_block(ast_node &node)
    {
        std::string ir_code = ""; // 用于存储当前节点的IR代码
        // 遍历block的子节点
        for(auto &child : node.children)
        {
            if(child->name == "LeftBrace" || child->name == "RightBrace")
            {
                continue; // 跳过左大括号和右大括号
            }
            else
            {
                if(child->ir_code.empty()) // 先生成子节点block_item内部的代码
                {
                    for(auto &grandchild : child->children) // 遍历block_item的子节点,其只有可能是declaration或statement
                    {
                        if(grandchild->name == "declaration")
                        {
                            child->ir_code = grandchild->ir_code; // 如果是declaration,则直接使用其IR代码
                        }
                        else if(grandchild->name == "statement")
                        {
                            child->ir_code = ir_gen_statement(*grandchild); // 如果是statement,则调用ir_gen_statement生成IR代码
                        }
                        else
                        {
                            throw std::runtime_error("Unsupported block_item type: " + grandchild->name);
                        }
                    }
                }
                ir_code += child->ir_code; // 将子节点的IR代码添加到当前节点的IR代码中
            }
        }
        node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
        return ir_code; // 返回当前节点的IR代码
    }

    // 生成一个statement结点的相关代码
    std::string ir_gen_statement(ast_node &node)
    {
        //std::cout << "Generating IR for statement: " << node.node_index << std::endl; // 输出当前生成的statement节点的索引和名称
        // if语句
        if(node.children[0]->name == "If" && node.children.size() == 5)
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            std::string condition_ir_code = calculate_expression_value(*node.children[2], "bool"); // 生成条件表达式的IR代码
            std::string then_statement_ir_code = ir_gen_statement(*node.children[4]); // 生成then块的IR代码
            // 生成跳转代码 为此我们需要先获得条件表达式节点的寄存器名称
            std::string condition_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 条件表达式的寄存器名称
            std::string then_label = "label_" + std::to_string(node.node_index) + "_then"; // then块的标签
            std::string else_label = "label_" + std::to_string(node.node_index) + "_else"; // else块的标签
            std::string br_ir_code = "br i1 " + condition_reg_name + ", label %" + then_label + ", label %" + else_label + "\n"; // 生成条件跳转代码
            ir_code += condition_ir_code + br_ir_code; // 拼接条件表达式的IR代码和跳转代码
            ir_code += "\n" + then_label + ":\n" + then_statement_ir_code; // 添加then块的IR代码
            ir_code += "\n" + else_label + ":\n"; // 添加else块的标签
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // if-else语句
        else if(node.children[0]->name == "If" && node.children.size() == 7)
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            std::string condition_ir_code = calculate_expression_value(*node.children[2], "bool"); // 生成条件表达式的IR代码
            std::string then_statement_ir_code = ir_gen_statement(*node.children[4]); // 生成then块的IR代码
            std::string else_statement_ir_code = ir_gen_statement(*node.children[6]); // 生成else块的IR代码
            // 生成跳转代码 为此我们需要先获得条件表达式节点的寄存器名称
            std::string condition_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 条件表达式的寄存器名称
            std::string then_label = "label_" + std::to_string(node.node_index) + "_then"; // then块的标签
            std::string else_label = "label_" + std::to_string(node.node_index) + "_else"; // else块的标签
            std::string end_label = "label_" + std::to_string(node.node_index) + "_end"; // end块的标签
            std::string br_ir_code = "br i1 " + condition_reg_name + ", label %" + then_label + ", label %" + else_label + "\n"; // 生成条件跳转代码
            ir_code += condition_ir_code + br_ir_code; // 拼接条件表达式的IR代码和跳转代码
            ir_code += "\n" + then_label + ":\n" + then_statement_ir_code; // 添加then块的IR代码
            ir_code += "br label %" + end_label + "\n"; // 添加跳转到end块的代码
            ir_code += "\n" + else_label + ":\n" + else_statement_ir_code; // 添加else块的IR代码
            ir_code += "br label %" + end_label + "\n"; // 添加跳转到end块的代码
            ir_code += "\n" + end_label + ":\n"; // 添加end块的标签
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // block
        else if(node.children[0]->name == "block")
        {
            // 直接调用ir_gen_block生成block的IR代码
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            ir_code = ir_gen_block(*node.children[0]); // 生成block的IR代码
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // 赋值语句
        else if(node.children[0]->name == "left_value")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            // 先生成等号右侧的表达式的IR代码
            std::string type = get_arithmetic_expression_type(*node.children[2]); // 获取等号右侧表达式的类型
            std::string expression_ir_code = calculate_expression_value(*node.children[2], type); // 生成等号右侧表达式的IR代码
            // 将其赋给等号左侧的left_value
            std::string expression_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 表达式的寄存器名称
            // 先确定left_value是否为数组 如果不是数组,则直接将寄存器中的值赋给left_value的寄存器
            if(node.children[0]->children.size() == 1 && node.children[0]->children[0]->name == "Identifier")
            {
                // 如果left_value只有一个子节点,则说明是标识符
                identifier* id = find_identifier_in_scope(*node.children[0]->children[0], node.children[0]->children[0]->cact_code); // 查找标识符节点
                std::string left_value_reg_name = "%id_" + std::to_string(id->id_index); // left_value的寄存器名称
                // 直接使用表达式的值寄存器
                auto [reg_type, reg_align] = get_reg_type_and_align(type); // 获取寄存器类型和对齐方式
                // 根据类型选择具体的指针类型
                std::string ptr_type;
                if (reg_type == "i32") ptr_type = "i32*";
                else if (reg_type == "float") ptr_type = "float*";
                else if (reg_type == "i8") ptr_type = "i8*";
                else ptr_type = "ptr"; // 其他情况保持原样
                
                // 将表达式的值直接存储到left_value的寄存器
                std::string assign_ir_code;
                if(id->is_global == false)
                {
                    assign_ir_code = "store " + reg_type + " " + expression_reg_name + ", " + ptr_type + " " + left_value_reg_name + reg_align + "\n"; // 将表达式的值存储到局部标识符的寄存器
                }
                else
                {
                    assign_ir_code = "store " + reg_type + " " + expression_reg_name + ", " + ptr_type + " @id_" + std::to_string(id->id_index) + reg_align + "\n"; // 将表达式的值存储到全局标识符的寄存器
                }
                ir_code = expression_ir_code + assign_ir_code; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            else if(node.children[0]->children.size() > 1)
            {
                auto [reg_type, reg_align] = get_reg_type_and_align(type); // 获取寄存器类型和对齐方式
                // 如果有多个子节点,说明是数组访问
                identifier* id = find_identifier_in_scope(*node.children[0]->children[0], node.children[0]->children[0]->cact_code); // 查找标识符节点
                // 首先获取left_value节点的cact_code 并从中分离出数组名和索引
                std::string array_name = node.children[0]->children[0]->cact_code; // 数组名 如"array"
                // 将cact_code减去开头的标识符部分得到剩余的索引部分 如"[2][3]""
                std::string index_string = node.children[0]->cact_code.substr(array_name.length());
                // 直接将多维数组当成一维来做 在取数组 int a[n1][n2][n3]...[nk] 的 a[i1][i2][i3]...[ik] 的值时
                // 我们将其看成一维数组 a[i1*n2*n3*...*nk + i2*n3*...*nk + i3*...*nk + ... + ik] 的值
                // 先根据Identifier的type来获取数组各维度的大小 例如当type="int[2][3][4]"时 各维度分别为 n1=2, n2=3, n3=4
                // 如果n1不存在,即函数参数中数组的最外层维度被忽略,则将其置为0
                std::vector<int> array_sizes; // 用于存储数组各维度的大小
                std::string array_type = id->type; // 获取数组的类型
                // 解析数组类型字符串,提取各维度大小
                size_t pos = 0;
                while ((pos = array_type.find('[')) != std::string::npos) 
                {
                    size_t end_pos = array_type.find(']', pos);
                    if (end_pos == std::string::npos) 
                    {
                        throw std::runtime_error("Invalid array type format: " + array_type);
                    }
                    std::string size_str = array_type.substr(pos + 1, end_pos - pos - 1); // 提取维度大小
                    if (size_str.empty()) 
                    {
                        array_sizes.push_back(0); // 如果没有指定大小,则默认为0
                    } 
                    else 
                    {
                        array_sizes.push_back(std::stoi(size_str)); // 将字符串转换为整数
                    }
                    array_type.erase(0, end_pos + 1); // 移除已处理的部分
                }
                // 类似的 从index_string中提取i1 i2 i3 ... ik的值
                std::vector<int> indices; // 用于存储索引值
                pos = 0;
                while ((pos = index_string.find('[')) != std::string::npos) 
                {
                    size_t end_pos = index_string.find(']', pos);
                    if (end_pos == std::string::npos) 
                    {
                        throw std::runtime_error("Invalid index format: " + index_string);
                    }
                    std::string index_str = index_string.substr(pos + 1, end_pos - pos - 1); // 提取索引值
                    indices.push_back(std::stoi(index_str)); // 将字符串转换为整数
                    index_string.erase(0, end_pos + 1); // 移除已处理的部分
                }
                int true_index = 0; // 用于存储计算后的真实索引
                // 计算真实索引
                for (size_t i = 0; i < indices.size(); ++i) 
                {
                    int multiplier = 1; // 用于计算当前维度的乘数
                    for (size_t j = i + 1; j < array_sizes.size(); ++j) 
                    {
                        multiplier *= array_sizes[j]; // 计算当前维度的乘数
                    }
                    true_index += indices[i] * multiplier; // 累加到真实索引
                }
                // 现在我们已经得到了真实索引,接下来生成IR代码
                std::string tmp_reg_name_1 = "%tmp_reg_" + std::to_string(node.node_index) + "_1"; // 临时寄存器1

                // 根据类型选择具体的指针类型
                std::string ptr_type;
                if (reg_type == "i32") ptr_type = "i32*";
                else if (reg_type == "float") ptr_type = "float*";
                else if (reg_type == "i8") ptr_type = "i8*";
                else ptr_type = "ptr"; // 其他情况保持原样

                // 获取我们需要的值的地址并存入临时寄存器1
                std::string ptr_ir_code;
                if(id->is_global == false)
                {
                    ptr_ir_code = tmp_reg_name_1 + " = getelementptr " + reg_type + ", " + ptr_type + " %id_" + std::to_string(id->id_index) + ", i32 " + std::to_string(true_index) + "\n"; // 计算数组元素地址
                }
                else
                {
                    ptr_ir_code = tmp_reg_name_1 + " = getelementptr " + reg_type + ", " + ptr_type + " @id_" + std::to_string(id->id_index) + ", i32 " + std::to_string(true_index) + "\n"; // 计算数组元素地址
                }
                // 将表达式的值直接存储到数组元素地址
                std::string assign_ir_code = "store " + reg_type + " " + expression_reg_name + ", " + ptr_type + " " + tmp_reg_name_1 + reg_align + "\n"; // 将表达式的值存储到数组元素地址
                ir_code = expression_ir_code + ptr_ir_code + assign_ir_code; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        // 只有分号
        else if(node.children[0]->name == "Semicolon")
        {
            return ""; // 如果是分号,则返回空字符串
        }
        // 悬空表达式
        else if(node.children[0]->name == "expression")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            std::string type = get_arithmetic_expression_type(*node.children[0]); // 获取表达式的类型
            ir_code = exp_gen_ir_code_from_child(node, type, 0); // 生成表达式的IR代码
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // while循环
        else if(node.children[0]->name == "While")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            std::string condition_ir_code = calculate_expression_value(*node.children[2], "bool"); // 生成条件表达式的IR代码
            std::string body_ir_code = ir_gen_statement(*node.children[4]); // 生成循环体的IR代码
            // 生成跳转代码 为此我们需要先获得条件表达式节点的寄存器名称
            std::string condition_reg_name = "%reg" + std::to_string(node.children[2]->node_index); // 条件表达式的寄存器名称
            std::string condition_label = "label_" + std::to_string(node.node_index) + "_condition"; // 条件表达式的标签
            std::string loop_start_label = "label_" + std::to_string(node.node_index) + "_loop_start"; // 循环开始标签
            std::string loop_end_label = "label_" + std::to_string(node.node_index) + "_loop_end"; // 循环结束标签
            std::string br_condition = "br label %" + condition_label + "\n"; // 跳转到条件表达式标签
            std::string condition_ir_code_with_label = "\n" + condition_label + ":\n" + condition_ir_code; // 条件表达式的IR代码
            std::string br_condition_true = "br i1 " + condition_reg_name + ", label %" + loop_start_label + ", label %" + loop_end_label + "\n"; // 条件跳转代码
            std::string loop_start_ir_code = "\n" + loop_start_label + ":\n" + body_ir_code; // 循环体的IR代码
            std::string br_loop_start = "br label %" + condition_label + "\n"; // 跳转回条件表达式的代码
            std::string loop_end_ir_code = "\n" + loop_end_label + ":\n"; // 循环结束标签的IR代码
            // 拼接所有IR代码
            ir_code = br_condition + condition_ir_code_with_label + br_condition_true + loop_start_ir_code + br_loop_start + loop_end_ir_code; // 拼接IR代码
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // break语句
        else if(node.children[0]->name == "Break")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            // 沿着ast向上查找直到找到最近的while循环节点,然后跳转到其结束标签
            ast_node* current_node = &node; // 从当前节点开始查找
            while(current_node != nullptr)
            {
                if(current_node->children.size() > 0 && current_node->children[0]->name == "While")
                {
                    // 找到了最近的while循环节点
                    std::string loop_end_label = std::to_string(current_node->node_index) + "_loop_end"; // 循环结束标签
                    ir_code = "br label %" + loop_end_label + "\n"; // 生成跳转到循环结束标签的代码
                    break; // 跳出循环
                }
                current_node = current_node->parent; // 向上查找父节点
            }
            if(ir_code.empty())
            {
                throw std::runtime_error("Break statement not inside a loop");
            }
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // continue语句
        else if(node.children[0]->name == "Continue")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            // 沿着ast向上查找直到找到最近的while循环节点,然后跳转到其条件标签
            ast_node* current_node = &node; // 从当前节点开始查找
            while(current_node != nullptr)
            {
                if(current_node->children.size() > 0 && current_node->children[0]->name == "While")
                {
                    // 找到了最近的while循环节点
                    std::string condition_label = std::to_string(current_node->node_index) + "_condition"; // 条件表达式的标签
                    ir_code = "br label %" + condition_label + "\n"; // 生成跳转到条件表达式标签的代码
                    break; // 跳出循环
                }
                current_node = current_node->parent; // 向上查找父节点
            }
            if(ir_code.empty())
            {
                throw std::runtime_error("Continue statement not inside a loop");
            }
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        // return语句
        else if(node.children[0]->name == "Return")
        {
            std::string ir_code = ""; // 用于存储当前节点的IR代码
            if(node.children.size() == 3) // 如果有返回值
            {
                std::string type = get_arithmetic_expression_type(*node.children[1]); // 获取返回值的类型
                std::string return_value_ir_code = calculate_expression_value(*node.children[1], type); // 生成返回值的IR代码
                std::string return_reg_name = "%reg" + std::to_string(node.children[1]->node_index); // 返回值的寄存器名称
                auto [reg_type, reg_align] = get_reg_type_and_align(type); // 获取寄存器类型和对齐方式
                // 直接返回表达式的值寄存器
                ir_code = return_value_ir_code + "ret " + reg_type + " " + return_reg_name + "\n"; // 拼接IR代码
            }
            else // 如果没有返回值
            {
                ir_code = "ret void\n"; // 返回void类型
            }
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        else
        {
            throw std::runtime_error("Unsupported statement type: " + node.children[0]->name);
        }
    }
}