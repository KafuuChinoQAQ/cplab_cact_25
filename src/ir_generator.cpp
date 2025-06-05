#include "i,_generator.h"
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
            std::string ir_code_2=""; // 用于存储IR代码的第二部分 即初始化部分
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
                // 首先检查是否有初始化值,如果最后一个子节点不是constant_initial_value,则说明该变量没有初始化值,但常量一定有
                if (node.children.size() > 0 && node.children.back()->name == "constant_initial_value")
                {
                    // 如果有显式初始化,则计算初始化表达式值,然后将该值赋给id
                    // 根据助教的说法,此处的常量表达式只会是立即数,不需要递归计算表达式的值
                    if(current_id->type == "int")
                    {
                        int init_value = std::get<int>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        ir_code_2 = "store i32 " + std::to_string(init_value) + ", ptr %" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为init_value
                        if(current_id->kind == IdKind::Const) // 对于常量,我们同时修改identifier的const_value字段,以便后续使用
                        {
                            current_id->const_value = init_value;
                        }
                    }
                    else if(current_id->type == "float")
                    {
                        float init_value = std::get<float>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        ir_code_2 = "store float " + std::to_string(init_value) + ", ptr %" + std::to_string(current_id->id_index) + ", align 4\n"; // 初始化为init_value
                        if(current_id->kind == IdKind::Const)
                        {
                            current_id->const_value = init_value;
                        }
                    }
                    else if(current_id->type == "char")
                    {
                        char init_value = std::get<char>(calculate_constant_expression_value(*node.children.back()->children.back(), current_id->type)); // 计算初始化值
                        // 注意:这里的char类型在LLVM中是i8类型,需要转换为整数
                        ir_code_2 = "store i8 " + std::to_string(static_cast<int>(init_value)) + ", ptr %" + std::to_string(current_id->id_index) + ", align 1\n"; // 初始化为init_value
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
                                    std::get<std::vector<float>>(init_values).push_back(std::get<int>(calculate_constant_expression_value(*n,base_type))); // 将值存入float类型的vector
                                }
                                else if(base_type == "char")
                                {
                                    std::get<std::vector<char>>(init_values).push_back(std::get<int>(calculate_constant_expression_value(*n,base_type))); // 将值存入char类型的vector
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
                                // %tmp = getelementptr <array_type>, ptr %id, i32 0, i32 i
                                std::string gep = "%tmp" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                    " = getelementptr inbounds " + to_llvm_array_type(current_id->type).substr(0, to_llvm_array_type(current_id->type).find(',')) +
                                    ", ptr %" + std::to_string(current_id->id_index) + ", i32 0, i32 " + std::to_string(i) + "\n";
                                std::string store = "store i32 " + std::to_string(vec[i]) + ", ptr %tmp" +
                                    std::to_string(current_id->id_index) + "_" + std::to_string(i) + ", align 4\n";
                                ir_code_2 += gep + store;
                            }
                        }
                        else if(base_type == "float")
                        {
                            auto &vec = std::get<std::vector<float>>(init_values);
                            for(size_t i = 0; i < vec.size(); ++i)
                            {
                                // %tmp = getelementptr <array_type>, ptr %id, i32 0, i32 i
                                std::string gep = "%tmp" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                    " = getelementptr inbounds " + to_llvm_array_type(current_id->type).substr(0, to_llvm_array_type(current_id->type).find(',')) +
                                    ", ptr %" + std::to_string(current_id->id_index) + ", i32 0, i32 " + std::to_string(i) + "\n";
                                std::string store = "store float " + std::to_string(vec[i]) + ", ptr %tmp" +
                                    std::to_string(current_id->id_index) + "_" + std::to_string(i) + ", align 4\n";
                                ir_code_2 += gep + store;
                            }
                        }
                        else if(base_type == "char")
                        {
                            auto &vec = std::get<std::vector<char>>(init_values);
                            for(size_t i = 0; i < vec.size(); ++i)
                            {
                                // %tmp = getelementptr <array_type>, ptr %id, i32 0, i32 i
                                std::string gep = "%tmp" + std::to_string(current_id->id_index) + "_" + std::to_string(i) +
                                    " = getelementptr inbounds " + to_llvm_array_type(current_id->type).substr(0, to_llvm_array_type(current_id->type).find(',')) +
                                    ", ptr %" + std::to_string(current_id->id_index) + ", i32 0, i32 " + std::to_string(i) + "\n";
                                std::string store = "store i8 " + std::to_string(static_cast<int>(vec[i])) + ", ptr %tmp" +
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
    std::string to_llvm_array_type(const std::string& type_str)
    {
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


    // 计算单个number的值的函数,接受一个number节点,返回该节点的值
    // 对于char类型,支持转义字符'\n' '\t' '\\' ''' '"' '\0'
    std::variant<int, float, char> calculate_number_value(const ast_node &node) 
    {
        std::string value_str = node.cact_code; // 获取节点的cact代码片段
        if(node.children[0]->name == "IntegerConstant") 
        {
            return std::stoi(value_str); // 直接转换为整数
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

    // 计算一个任意的变量表达式的值,接受一个expression节点,将ir_code添加到节点的属性上
    // 每一个表达式类节点用于暂存结果的寄存器名称应当为"%exp_node.node_index"
    // 这里因为比较繁琐,就不检查传入的节点类型是否正确了
    std::string calculate_expression_value(ast_node &node, std::string type)
    {
        if(node.name == "expression")
        {
            // 根据推导式ConstExp → AddExp 
        }
    }
}