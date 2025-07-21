// 本文件中代码用于生成A,T对应的各标识符定义域
#include "variable_scope_generator.h"
namespace cplab_variable_scope_generator 
{
    // 标识符声明处理函数 传入AST节点,为AST各节点设置作用域信息,并返回生成的作用域树根节点
    // 基本的思想是,对AST进行先序遍历,每当遇到"{"时,创建一个新的子节点并进入
    //                              每当遇到id的声明时,在当前节点创建对应条目
    //                              每当遇到"}"时,返回上一级作用域
    int id_index = 1; // 全局标识符索引,用于为每个标识符分配唯一的id_index
    scope_node variable_scope_generator(ast_node &ast_node)
    {
        // 创建作用域树根节点
        scope_node root_scope;
        root_scope.parent = nullptr; // 根节点没有父节点
        root_scope.children.clear(); // 清空子节点列表
        root_scope.name = "global"; // 设置根节点名称为"global"

        scope_node* current_scope = &root_scope; // 初始化当前作用域为根节点

        // 预先在全局作用域中添加6个标准库函数
        {
            identifier print_int, print_float, print_char, get_int, get_float, get_char;
            // 添加print_int函数
            print_int.id_index = id_index++;
            print_int.kind = IdKind::Func;
            print_int.func_return_type = "void";
            print_int.name = "print_int";
            print_int.type = "";
            print_int.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_int.func_params.clear();
            // 添加一个int类型的标识符作为其参数
            identifier int_param;
            int_param.id_index = id_index++;
            int_param.kind = IdKind::Param;
            int_param.name = "external_func_print_int_param";
            int_param.type = "int";
            int_param.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_int.func_params.push_back(int_param); // 添加参数到函数参数列表
            print_int.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(print_int); // 将print_int添加到全局作用域的标识符列表中

            // 添加print_float函数
            print_float.id_index = id_index++;
            print_float.kind = IdKind::Func;
            print_float.func_return_type = "void";
            print_float.name = "print_float";
            print_float.type = "";
            print_float.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_float.func_params.clear();
            // 添加一个float类型的标识符作为其参数
            identifier float_param;
            float_param.id_index = id_index++;
            float_param.kind = IdKind::Param;
            float_param.name = "external_func_print_float_param";
            float_param.type = "float";
            float_param.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_float.func_params.push_back(float_param); // 添加参数到函数参数列表
            print_float.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(print_float); // 将print_float添加到全局作用域的标识符列表中
            
            // 添加print_char函数
            print_char.id_index = id_index++;
            print_char.kind = IdKind::Func;
            print_char.func_return_type = "void";
            print_char.name = "print_char";
            print_char.type = "";
            print_char.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_char.func_params.clear();
            // 添加一个char类型的标识符作为其参数
            identifier char_param;
            char_param.id_index = id_index++;
            char_param.kind = IdKind::Param;
            char_param.name = "external_func_print_char_param";
            char_param.type = "char";
            char_param.line_number = -1; // 行号为-1表示非当前文件中的标识符
            print_char.func_params.push_back(char_param); // 添加参数到函数参数列表
            print_char.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(print_char); // 将print_char添加到全局作用域的标识符列表中

            // 添加get_int函数
            get_int.id_index = id_index++;
            get_int.kind = IdKind::Func;
            get_int.func_return_type = "int";
            get_int.name = "get_int";
            get_int.type = "";
            get_int.line_number = -1; // 行号为-1表示非当前文件中的标识符
            get_int.func_params.clear(); // 无参数
            get_int.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(get_int); // 将get_int添加到全局作用域的标识符列表中

            // 添加get_float函数
            get_float.id_index = id_index++;
            get_float.kind = IdKind::Func;
            get_float.func_return_type = "float";
            get_float.name = "get_float";
            get_float.type = "";
            get_float.line_number = -1; // 行号为-1表示非当前文件中的标识符
            get_float.func_params.clear(); // 无参数
            get_float.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(get_float); // 将get_float添加到全局作用域的标识符列表中

            // 添加get_char函数
            get_char.id_index = id_index++;
            get_char.kind = IdKind::Func;
            get_char.func_return_type = "char";
            get_char.name = "get_char";
            get_char.type = "";
            get_char.line_number = -1; // 行号为-1表示非当前文件中的标识符
            get_char.func_params.clear(); // 无参数
            get_char.is_global = true; // 标记为全局函数
            current_scope->identifiers.push_back(get_char); // 将get_char添加到全局作用域的标识符列表中
        }
        // 递归处理AST节点
        for (auto &child : ast_node.children) {
            process_ast_node(*child,current_scope);
        }

        return root_scope; // 返回生成的作用域树根节点
    }
    // 处理AST节点的函数
    void process_ast_node(ast_node &node, scope_node* current_scope)
    {
        // 如果当前AST节点是一个语句块节点,那么在当前作用域下创建一个子作用域并进入,然后递归处理AST子节点
        if (node.name == "block")
        {
            // 创建新的作用域节点
            scope_node new_scope;
            new_scope.parent = current_scope; // 设置新作用域的父节点为当前作用域
            // 设置新作用域名称
            if(current_scope->name == "global")
            {
                new_scope.name = "Block_" + std::to_string(current_scope->children.size()); // 如果当前作用域是全局作用域,则新作用域名称为"Block_X"
            }
            else
            {
                // 否则新作用域名称为"Block_X_Y",其中X为当前作用域名称, Y为当前作用域子节点数量
                new_scope.name = current_scope->name + "_" + std::to_string(current_scope->children.size());
            }
            
            new_scope.children.clear(); // 清空子节点列表
            new_scope.identifiers.clear(); // 清空标识符列表

            current_scope->children.push_back(new_scope); // 将新作用域添加到当前作用域的子节点列表中
            current_scope = &current_scope->children.back(); // 将当前作用域指向vector中的副本
            // 将当前AST节点的作用域设置为当前作用域
            node.scope_ptr = current_scope;

            // 新添加内容 如果block节点的父节点是一个函数定义节点,则将函数参数添加到当前作用域的标识符列表中
            if (node.parent && node.parent->name == "function_definition") {
                // 获取函数定义节点的标识符
                identifier func_id;
                for(const auto &id : current_scope->parent->identifiers) {
                    if (id.line_number == node.parent->node_index) { // 通过行号匹配标识符
                        func_id = id; // 找到函数标识符
                        break;
                    }
                }
                // 将函数参数添加到当前作用域的标识符列表中
                for (const auto &param : func_id.func_params) {
                    current_scope->identifiers.push_back(param);
                }
            }
            // 递归处理子节点
            for (auto &child : node.children) {
                process_ast_node(*child,current_scope);
            }

            current_scope = current_scope->parent; // 处理完后返回上一级作用域
        }
        // 否则如果该结点是一个常量或变量定义结点,我们需要找到其父声明节点来获取该常量的类型
        else if (node.name == "constant_definition" || node.name == "variable_definition")
        {
            // 创建一个新的标识符
            identifier id;
            id.id_index = id_index++; // 为标识符分配唯一的id_index
            id.name = node.children[0]->cact_code; // 获取标识符名称,源自第一个子节点Identifier
            id.func_return_type = ""; // func_return_type字段不使用
            id.func_params.clear(); // 清空函数参数列表
            id.line_number = node.node_index; // 设置标识符所在的行号,用于错误提示和静态检查
            // 获取标识符的基本类型,来源于其兄弟节点
            std::string basic_type; // 基本类型字符串  
            // 由于常量声明的第一个子节点是"const",所以我们取第二个子节点basic_type的cact_code作为基本类型,而变量声明则该取第一个子节点 
            if(node.name == "constant_definition")
            {
                id.kind = IdKind::Const; // 标识符是一个常量
                basic_type = node.parent->children[1]->cact_code;
            }
            else if(node.name == "variable_definition")
            {
                id.kind = IdKind::Var; // 标识符是一个变量
                basic_type = node.parent->children[0]->cact_code; // 获取基本类型
            }
            // 为这个标识符的类型添加上可能存在的数组后缀
            std::string temp_string = node.cact_code; // 获取当前节点的cact代码片段
            //先去除temp_string中与id.name相同的开头部分
            size_t pos = temp_string.find(id.name);
            if (pos != std::string::npos) {
                temp_string.erase(pos, id.name.length());
            }
            // 然后检查是否出现了"="符号,如果有,则去除"="符号及其后面的部分
            pos = temp_string.find("=");
            if (pos != std::string::npos) {
                temp_string.erase(pos);
            }
            // 最后将剩余的部分作为数组后缀
            std::string array_suffix = temp_string;
            // 如果数组后缀不为空,则将其添加到标识符类型中
            if (!array_suffix.empty()) {
                id.type = basic_type + array_suffix; // 设置标识符类型为基本类型加上数组后缀
            } else {
                id.type = basic_type; // 否则仅设置为基本类型
            }
            // 将标识符添加到当前作用域的标识符列表中
            current_scope->identifiers.push_back(id);
            //打印当前作用域的全部标识符

            // 将当前AST节点的作用域设置为当前作用域
            node.scope_ptr = current_scope;
            // 递归处理子节点
            for (auto &child : node.children) {
                process_ast_node(*child,current_scope);
            }
        }
        // 否则如果该结点是一个函数定义结点
        else if (node.name == "function_definition")
        {
            // 创建一个新的标识符
            identifier id;
            id.id_index = id_index++; // 为标识符分配唯一的id_index
            id.kind = IdKind::Func; // 标识符是一个函数
            id.func_return_type = node.children[0]->cact_code; // 获取函数返回类型,源自第一个子节点function_type
            id.name = node.children[1]->cact_code; // 获取函数名称,源自第二个子节点Identifier
            id.type = ""; //type字段不使用
            id.line_number = node.node_index; // 设置标识符所在的行号,用于错误提示和静态检查
            // 获取函数形参列表
            id.func_params.clear(); // 清空函数参数列表
            ast_node* formal_params_node = node.children[3].get(); // 获取函数形参列表节点
            // 遍历函数形参列表的子节点,如果遇到function_formal_param节点,则将其名称和类型添加到函数参数列表中
            for(auto &param_node : formal_params_node->children)
            {
                if (param_node->name == "function_formal_param")
                {
                    identifier param_id;
                    param_id.id_index = id_index++; // 为参数分配唯一的id_index
                    param_id.kind = IdKind::Param; // 标识符是一个函数参数
                    param_id.line_number = param_node->node_index; // 设置参数所在的行号,用于错误提示和静态检查
                    param_id.name = param_node->children[1]->cact_code; // 获取参数名称,源自第二个子节点Identifier
                    param_id.func_return_type = ""; // func_return_type字段不使用
                    param_id.is_global = false; // 函数参数不是全局变量
                    param_id.func_params.clear(); // 清空函数参数列表
                    std::string param_basic_type = param_node->children[0]->cact_code; // 获取参数的基本类型
                    // 为这个参数的类型添加上可能存在的数组后缀
                    std::string temp_string = param_node->cact_code; // 获取当前节点的cact代码片段
                    //去除temp_string中与param_basic_type+param_id.name相同的开头部分
                    size_t pos = temp_string.find(param_basic_type + param_id.name);
                    if (pos != std::string::npos) {
                        temp_string.erase(pos, param_basic_type.length() + param_id.name.length());
                    }
                    // 剩余部分作为数组后缀
                    std::string param_array_suffix = temp_string;
                    // 如果数组后缀不为空,则将其添加到参数类型中
                    if (!param_array_suffix.empty()) {
                        param_id.type = param_basic_type + param_array_suffix; // 设置参数类型为基本类型加上数组后缀
                    } else {
                        param_id.type = param_basic_type; // 否则仅设置为基本类型
                    }
                    // 将参数标识符添加到函数参数列表中
                    id.func_params.push_back(param_id);
                }
            }
            // 将标识符添加到当前作用域的标识符列表中
            current_scope->identifiers.push_back(id);

            // 将当前AST节点的作用域设置为当前作用域
            node.scope_ptr = current_scope;
            // 递归处理子节点
            for (auto &child : node.children) {
                process_ast_node(*child,current_scope);
            }
        }
        // 其余情况不改变作用域,只将当前AST结点指向当前作用域
        else
        {
            // 将当前AST节点的作用域设置为当前作用域
            node.scope_ptr = current_scope;
            // 递归处理子节点
            for (auto &child : node.children) {
                process_ast_node(*child,current_scope);
            }
        }
    }


    void variable_scope_printer(scope_node &node, std::ostream &out)
    {
        // 打印当前作用域节点信息
        out << "Scope: " << node.name << std::endl; // 打印作用域名称
        out << "Identifiers: " << std::endl; // 打印标识符列表标题

        // 遍历并打印当前作用域的标识符
        for (const auto &id : node.identifiers) {
            out << "  %" << id.id_index << ": "; // 打印标识符的全局索引
            if(id.kind == IdKind::Func) {
                out << "Func "; // 如果是函数,打印Func
            }
            else if(id.kind == IdKind::Var) {
                out << "Var "; // 如果是变量,打印Var
            }
            else if(id.kind == IdKind::Const) {
                out << "Const "; // 如果是常量,打印Const
            }
            out << id.name; // 打印标识符名称
            out << " (position: " << id.line_number << ")"; // 打印标识符所对应的结AST结点的位置,和行号本身不太一样
            if (id.kind == IdKind::Func) {
                out << " (Return Type: " << id.func_return_type << ")"; // 如果是函数,打印返回类型
                // 打印函数参数列表
                if (!id.func_params.empty()) {
                    out << " [Params: ";
                    for (const auto &param : id.func_params) {
                        out << param.name << " (" << param.type << "), "; // 打印每个参数的名称和类型
                    }
                    out.seekp(-2, std::ios_base::end); // 去掉最后一个逗号和空格
                    out << "]";
                }
            }
            else {
                out << " (Type: " << id.type << ")"; // 否则打印类型
                if(id.kind == IdKind::Const) {
                    // 如果是常量,打印初始值
                    out << " (Initial Value: ";
                    if (std::holds_alternative<int>(id.const_value)) {
                        out << std::get<int>(id.const_value);
                    } else if (std::holds_alternative<float>(id.const_value)) {
                        out << std::get<float>(id.const_value);
                    } else if (std::holds_alternative<char>(id.const_value)) {
                        out << "'" << std::get<char>(id.const_value) << "'";
                    } else if (std::holds_alternative<std::vector<int>>(id.const_value)) {
                        out << "[";
                        for (const auto &val : std::get<std::vector<int>>(id.const_value)) {
                            out << val << " ";
                        }
                        out << "]";
                    } else if (std::holds_alternative<std::vector<float>>(id.const_value)) {
                        out << "[";
                        for (const auto &val : std::get<std::vector<float>>(id.const_value)) {
                            out << val << " ";
                        }
                        out << "]";
                    } else if (std::holds_alternative<std::vector<char>>(id.const_value)) {
                        out << "[";
                        for (const auto &val : std::get<std::vector<char>>(id.const_value)) {
                            out << "'" << val << "' ";
                        }
                        out << "]";
                    }
                    out << ")";
                }
            }
            out << std::endl; // 换行
        }

        out << "Children Scopes: " << std::endl; // 打印子作用域标题
        for (const auto &child : node.children) {
            out << "  - " << child.name << std::endl; // 打印子作用域名称
        }
        out << std::endl; // 换行分隔作用域
        // 递归打印子作用域
        for (auto &child : node.children) {
            variable_scope_printer(child, out);
        }
    }
}