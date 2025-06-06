#include "ir_generator.h"
#include <regex>
#include <string>,
#include <vector>
namespace cplab_ir_generator
{
    // 总入口
    void ir_generator(ast_node &node)
    {
        // 先生成declaration相关结点的IR代码
        ir_gen_declaration(node);
        // 然后遍历所有节点,依次生成所有expression和condition结点的IR代码
        for (auto &child : node.children)
        {
            if (child->name == "condition")
            {
                // 计算表达式的值,并将IR代码添加到节点的ir_code属性上
                calculate_expression_value(*child,"bool"); // 传入子节点的类型
            }
            else
            {
                ir_generator(*child); // 递归调用
            }
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

    // 计算一个任意的变量表达式的值,接受一个expression节点,将ir_code添加到节点的属性上同时返回
    // 每一个表达式类节点用于暂存结果的寄存器名称应当为"%node_index"
    // 这里因为比较繁琐,就不检查传入的节点类型是否正确了
    // 这个函数应当从expression或condition节点开始递归,当从expression开始时,type可能是int float char,当从condition开始时,type可能是bool
    // 但凡事也有例外(悲)
    std::string calculate_expression_value(ast_node &node, std::string type)
    {
        auto [reg_type, reg_align] = get_reg_type_and_align(type);
        std::string ir_code = ""; // 用于存储当前节点的IR代码
        if(node.name == "expression")
        {
            // 根据推导式 expression: additive_expression; 知,expression节点的子节点只有一个,即additive_expression
            ir_code = exp_gen_ir_code_from_only_child(node, type); // 生成只有一个子节点的exp节点的IR代码并将其返回
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        else if(node.name == "condition")
        {
            // 根据推导式 condition: logical_or_expression; 知,condition节点的子节点只有一个,即logical_or_expression
            ir_code = exp_gen_ir_code_from_only_child(node, type); // 生成只有一个子节点的exp节点的IR代码并将其返回
            node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
            return ir_code; // 返回当前节点的IR代码
        }
        else if(node.name == "logical_or_expression")
        {
            // 根据推导式 logical_or_expression: logical_and_expression | logical_or_expression LogicalOr logical_and_expression;
            // 如果子节点只有logical_and_expression,则直接重用子节点的ir_code
            if(node.children.size() == 1 && node.children[0]->name == "logical_and_expression")
            {
                ir_code = exp_gen_ir_code_from_only_child(node, type); // 直接重用子节点的ir_code
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 logical_or_expression "||" logical_and_expression
            else
            {
                // 分别计算前后两个逻辑表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type); // 计算左侧逻辑表达式的值
                std::string right_ir_code = calculate_expression_value(*node.children[2], type); // 计算右侧逻辑表达式的值
                // 生成临时寄存器名称
                std::string left_reg_name = "%" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                std::string tmp_reg_name = "%tmp_" + std::to_string(node.children[0]->node_index) + "_to_" + std::to_string(node.node_index); // 临时寄存器名称
                // 加载子节点临时寄存器的值 对于lor节点来说,子节点临时寄存器都应该是指向i1的指针类
                std::string left_load = tmp_reg_name + "_l = load i1, ptr " + left_reg_name + ", align 1\n";
                std::string right_load = tmp_reg_name + "_r = load i1, ptr " + right_reg_name + ", align 1\n";
                // 进行lor运算后赋给当前节点的临时寄存器
                std::string or_inst = tmp_reg_name + "_or = or i1 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n";
                std::string store_inst = "store i1 " + tmp_reg_name + "_or, ptr " + current_reg_name + ", align 1\n";
                ir_code = left_ir_code + right_ir_code + left_load + right_load + or_inst + store_inst;
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
                ir_code = exp_gen_ir_code_from_only_child(node, type); // 直接重用子节点的ir_code
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 logical_and_expression "&&" equal_expression
            else
            {
                // 分别计算前后两个逻辑表达式的值
                std::string left_ir_code = calculate_expression_value(*node.children[0], type); // 计算左侧逻辑表达式的值
                std::string right_ir_code = calculate_expression_value(*node.children[2], type); // 计算右侧逻辑表达式的值
                // 生成临时寄存器名称
                std::string left_reg_name = "%" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                std::string tmp_reg_name = "%tmp_" + std::to_string(node.children[0]->node_index) + "_to_" + std::to_string(node.node_index); // 临时寄存器名称
                // 加载子节点临时寄存器的值 对于land节点来说,子节点临时寄存器都应该是指向i1的指针类
                std::string left_load = tmp_reg_name + "_l = load i1, ptr " + left_reg_name + ", align 1\n";
                std::string right_load = tmp_reg_name + "_r = load i1, ptr " + right_reg_name + ", align 1\n";
                // 进行land运算后赋给当前节点的临时寄存器
                std::string and_inst = tmp_reg_name + "_and = and i1 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n";
                std::string store_inst = "store i1 " + tmp_reg_name + "_and, ptr " + current_reg_name + ", align 1\n";
                ir_code = left_ir_code + right_ir_code + left_load + right_load + and_inst + store_inst;
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
                ir_code = exp_gen_ir_code_from_only_child(node, type); // 直接重用子节点的ir_code
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
                std::string left_reg_name = "%" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                std::string tmp_reg_name = "%tmp_" + std::to_string(node.children[0]->node_index) + "_to_" + std::to_string(node.node_index); // 临时寄存器名称
                auto [reg_type, reg_align] = get_reg_type_and_align(child_type_l); // 获取寄存器类型和对齐方式并覆盖上层变量
                // 加载子节点临时寄存器的值 对于equal_expression节点来说,子节点临时寄存器指向的数据类型由child_type决定
                std::string left_load;
                std::string right_load;
                if(child_type_l == "int") // 如果是整数类型
                {
                    left_load = tmp_reg_name + "_l = load i32, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load i32, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                else if(child_type_l == "float") // 如果是浮点数类型
                {
                    left_load = tmp_reg_name + "_l = load float, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load float, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                else if(child_type_l == "char") // 如果是字符类型
                {
                    left_load = tmp_reg_name + "_l = load i8, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load i8, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                // 根据操作符和左右子节点的数据类型生成对应的比较指令. 例如当数据类型为int时,我们需要生成i32类型的比较指令
                std::string cmp_inst;
                std::string op = node.children[1]->cact_code; // 获取操作符
                if(child_type_l == "int")
                {
                    if(op == "==") // 如果是等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp eq " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp ne " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成不等于比较指令
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
                        cmp_inst = tmp_reg_name + "_cmp = fcmp oeq " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = fcmp one " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成不等于比较指令
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
                        cmp_inst = tmp_reg_name + "_cmp = icmp eq i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成等于比较指令
                    }
                    else if(op == "!=") // 如果是不等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp ne i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成不等于比较指令
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
                // 将运算后结果赋值给当前节点的临时寄存器
                std::string store_inst = "store i1 " + tmp_reg_name + "_cmp, ptr " + current_reg_name + ", align 1\n"; // 将比较结果存储到当前节点的寄存器
                ir_code = left_ir_code + right_ir_code + left_load + right_load + cmp_inst + store_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        else if(node.name == "relational_expression")
        {
            // 对于relational_expression节点 我们需要先获取其additive_expression子节点的数据类型,以便于求子节点的ir_code
            // 该节点中存储的指针可能有两种类型
            // 对于形如"a"的结点,我们存储int float char类型的指针
            // 对于形如"a<b"的结点,我们存储bool类型的指针(即i8)

            // 如果只有一个additive_expression子节点,那么我们先确认子节点的类型,然后生成其IR代码并赋给当前节点
            if(node.children.size() == 1 && node.children[0]->name == "additive_expression")
            {
                std::string child_type = get_arithmetic_expression_type(*node.children[0]); // 获取子节点的基本类型
                ir_code = exp_gen_ir_code_from_only_child(node, child_type); // 生成只有一个子节点的exp节点的IR代码并将其返回
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
            // 否则,说明该节点有三个子节点,即 relational_expression (RelationalOp) additive_expression
            // 此时,左右两个算术表达式都被直接看做算术表达式,因此传入的type应当是int float char之一
            // 左子节点会自行判断其数据类型,我们此处需要找到右子节点该有的数据类型
            else
            {
                std::string child_type_r = get_arithmetic_expression_type(*node.children[2]); // 获取右侧子节点的类型
                // 分别计算前后两个算术表达式的值 对于左子结点,其会自行判断数据类型
                std::string left_ir_code = calculate_expression_value(*node.children[0], type);
                std::string right_ir_code = calculate_expression_value(*node.children[2], child_type_r);
                // 生成临时寄存器名称
                std::string left_reg_name = "%" + std::to_string(node.children[0]->node_index); // 左侧子节点的临时寄存器名称
                std::string right_reg_name = "%" + std::to_string(node.children[2]->node_index); // 右侧子节点的临时寄存器名称
                std::string current_reg_name = "%" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
                std::string tmp_reg_name = "%tmp_" + std::to_string(node.children[0]->node_index) + "_to_" + std::to_string(node.node_index); // 临时寄存器名称
                auto [reg_type, reg_align] = get_reg_type_and_align(child_type_r); // 获取寄存器类型和对齐方式并覆盖上层变量
                // 加载子寄存器的值
                std::string left_load;
                std::string right_load;
                if(child_type_r == "int") // 如果是整数类型
                {
                    left_load = tmp_reg_name + "_l = load i32, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load i32, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                else if(child_type_r == "float") // 如果是浮点数类型
                {
                    left_load = tmp_reg_name + "_l = load float, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load float, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                else if(child_type_r == "char") // 如果是字符类型
                {
                    left_load = tmp_reg_name + "_l = load i8, ptr " + left_reg_name + reg_align + "\n"; // 从左侧子节点的寄存器加载值到临时寄存器
                    right_load = tmp_reg_name + "_r = load i8, ptr " + right_reg_name + reg_align + "\n"; // 从右侧子节点的寄存器加载值到临时寄存器
                }
                // 根据操作符和左右子节点的数据类型生成对应的比较指令. 例如当数据类型为int时,我们需要生成i32类型的比较指令
                std::string cmp_inst;
                std::string op = node.children[1]->cact_code; // 获取操作符
                if(child_type_r == "int")
                {
                    if(op == "<") // 如果是小于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp slt " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于比较指令
                    }
                    else if(op == "<=") // 如果是小于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sle " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于等于比较指令
                    }
                    else if(op == ">") // 如果是大于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sgt " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于比较指令
                    }
                    else if(op == ">=") // 如果是大于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sge " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于等于比较指令
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
                        cmp_inst = tmp_reg_name + "_cmp = fcmp olt " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于比较指令
                    }
                    else if(op == "<=") // 如果是小于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = fcmp ole " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于等于比较指令
                    }
                    else if(op == ">") // 如果是大于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = fcmp ogt " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于比较指令
                    }
                    else if(op == ">=") // 如果是大于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = fcmp oge " + reg_type + " " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于等于比较指令
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
                        cmp_inst = tmp_reg_name + "_cmp = icmp slt i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于比较指令
                    }
                    else if(op == "<=") // 如果是小于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sle i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成小于等于比较指令
                    }
                    else if(op == ">") // 如果是大于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sgt i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于比较指令
                    }
                    else if(op == ">=") // 如果是大于等于操作符
                    {
                        cmp_inst = tmp_reg_name + "_cmp = icmp sge i8 " + tmp_reg_name + "_l, " + tmp_reg_name + "_r\n"; // 生成大于等于比较指令
                    }
                    else
                    {
                        throw std::runtime_error("Unsupported operator in relational_expression: " + op);
                    }
                }
                // 将运算结果存储到当前节点临时寄存器中,这里数据类型要改回bool 即i8
                std::string store_inst = "store i1 " + tmp_reg_name + "_cmp, ptr " + current_reg_name + ", align 1\n"; // 将比较结果存储到当前节点的寄存器
                ir_code = left_ir_code + right_ir_code + left_load + right_load + cmp_inst + store_inst; // 拼接IR代码
                node.ir_code = ir_code; // 将生成的IR代码赋给当前节点
                return ir_code; // 返回当前节点的IR代码
            }
        }
        else
        {
            return ""; //暂且返回空字符串喵
        }
    }

    // 生成只有一个子节点的exp节点的IR代码并将其返回
    // 对于某个exp节点,如果其只有一个子节点,则该节点的代码由两部分组成
    // 第一部分是将子节点的ir_code赋给当前节点,第二部分是将子节点的临时寄存器中的值赋给当前节点的临时寄存器
    // 这里的临时寄存器名称为"%node_index",即当前节点的索引
    std::string exp_gen_ir_code_from_only_child(ast_node &node, std::string type)
    {
        auto [reg_type, reg_align] = get_reg_type_and_align(type);
        std::string ir_code = ""; // 用于存储当前节点的IR代码
        std::string ir_code_from_child = calculate_expression_value(*node.children[0], type); // 先生成子节点的ir_code
        // 将子节点临时寄存器中的表达式值赋给当前节点的临时寄存器
        std::string child_reg_name = "%" + std::to_string(node.children[0]->node_index); // 子节点的临时寄存器名称
        std::string current_reg_name = "%" + std::to_string(node.node_index); // 当前节点的临时寄存器名称
        std::string tmp_reg_name = "%tmp_" + std::to_string(node.children[0]->node_index) + "_to_" + std::to_string(node.node_index); // 临时寄存器名称
        // 生成赋值代码
        std::string assign_ir_code_1 = tmp_reg_name + " = load " + reg_type + ", ptr " + child_reg_name + reg_align + "\n"; // 从子节点的寄存器加载值到临时寄存器 
        std::string assign_ir_code_2 = "store" + reg_type + " " + tmp_reg_name + ", ptr " + current_reg_name + reg_align + "\n"; // 将临时寄存器的值存储到当前节点的寄存器
        ir_code = ir_code_from_child + assign_ir_code_1 + assign_ir_code_2; // 拼接IR代码
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
                child->name == "unary_expression" ||
                child->name == "primary_expression"||  //如果子节点也是算术表达式,那么递归调用函数
                child->name == "number" ||
                child->name == "left_value") //如果子节点是number或left_value,再递归一次,其第一个子节点的类型就是我们要找的
            {
                return get_arithmetic_expression_type(*child);
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

    }
}