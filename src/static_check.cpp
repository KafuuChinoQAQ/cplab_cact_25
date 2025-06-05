#include "static_check.h"
namespace cplab_static_check
{
    // 辅助函数：在作用域链中查找标识符
    const identifier* find_identifier_in_scopes(const std::string& name, const scope_node* current_scope) {
        while (current_scope != nullptr) {
            for (const auto& id : current_scope->identifiers) {
                if (id.name == name) {
                    return &id;
                }
            }
            current_scope = current_scope->parent;
        }
        return nullptr;
    }

const identifier* find_identifier_in_current_scope(const std::string& name, const scope_node* current_scope) {
    if (current_scope != nullptr) {
        std::cout << "Searching in scope: " << current_scope->name << std::endl;  // 调试输出当前作用域名称
        for (const auto& id : current_scope->identifiers) {
            std::cout << "  Checking identifier: " << id.name << std::endl;  // 调试输出正在检查的标识符名称
            if (id.name == name) {
                std::cout << "  Found identifier: " << id.name << " at line " << id.line_number << std::endl;  // 调试输出找到的标识符
                return &id;
            }
        }
    }
    std::cout << "  Identifier '" << name << "' not found in current scope" << std::endl;  // 调试输出未找到的信息
    return nullptr;
}
int count_identifiers_in_current_scope(const std::string& name, const scope_node* current_scope) {
    int count = 0;    
    if (current_scope != nullptr) {
        std::cout << "Counting in scope: " << current_scope->name << std::endl;  // 调试输出当前作用域名称
        
        for (const auto& id : current_scope->identifiers) {
            std::cout << "  Checking identifier: " << id.name << std::endl;  // 调试输出正在检查的标识符名称
            
            if (id.name == name) {
                std::cout << "  Found matching identifier: " << id.name << " at line " << id.line_number << std::endl;  // 调试输出找到的标识符
                count++;  // 同名定义计数增加
            }
        }
    }
    
    std::cout << "Total identifiers named '" << name << "' in current scope: " << count << std::endl;  // 调试输出总数
    return count;  // 返回同名定义的总数
}
    
    int declaration_check(ast_node& node) {
    // 情况1: 直接标识符作为左值(如a=2中的a)
    if (node.name == "Identifier") {
        // 检查父节点是否是left_value(直接变量使用)
        if (node.parent && node.parent->name == "left_value") {
            const identifier* id = find_identifier_in_scopes(node.cact_code, node.scope_ptr);
            if (id == nullptr) {
                std::cerr << "Error: Variable '" << node.cact_code << "' used before declaration\n";
                return 1;
            }
        }
        
        // 检查父节点是否是function_call(函数调用)
        if (node.parent && node.parent->name == "function_call") {
            const identifier* id = find_identifier_in_scopes(node.cact_code, node.scope_ptr);
            if (id == nullptr) {
                std::cerr << "Error: Function '" << node.cact_code << "' used before declaration\n";
                return 1;
            }
            if (id->kind != IdKind::Func) {
                std::cerr << "Error: '" << node.cact_code << "' is not a function (defined at line " 
                          << id->line_number << ")\n";
                return 1;
            }
        }
    }
    
    // 情况2: 赋值表达式中的左侧(如a=2中的a)
    if (node.name == "assignment_expression") {
        // 赋值表达式的左侧应该是left_value
        if (node.children.size() > 0) {
            ast_node* left_side = node.children[0].get();
            if (left_side && left_side->name == "left_value") {
                // left_value的第一个子节点应该是Identifier
                if (left_side->children.size() > 0 && left_side->children[0]->name == "Identifier") {
                    const identifier* id = find_identifier_in_scopes(left_side->children[0]->cact_code, left_side->children[0]->scope_ptr);
                    if (id == nullptr) {
                        std::cerr << "Error: Variable '" << left_side->children[0]->cact_code << "' used before declaration in assignment\n";
                        return 1;
                    }
                }
            }
        }
    }
    
    // 情况3: 函数调用参数中的变量(如func(a)中的a)
    if (node.name == "function_real_params") {
        for (auto& child : node.children) {
            if (child && child->name == "expression") {
                // 递归检查表达式中的变量使用
                if (declaration_check(*child) != 0) {
                    return 1;
                }
            }
        }
    }
    
    // 情况4: 表达式中的变量使用(如a+b中的a和b)
    if (node.name == "expression" || node.name == "primary_expression") {
        // 递归检查子节点
        for (auto& child : node.children) {
            if (child && declaration_check(*child) != 0) {
                return 1;
            }
        }
    }
    
    // 递归检查所有子节点
    for (auto& child : node.children) {
        if (child && declaration_check(*child) != 0) {
            return 1;
        }
    }
    
    return 0;
}


// 重定义检查函数 - 最终实现
int redeclaration_check(ast_node& node) {
    // 变量定义检查
    if (node.name == "variable_definition") {
        if (node.children.size() >= 1 && node.children[0] && node.children[0]->name == "Identifier") {
            std::string var_name = node.children[0]->cact_code;
            
            // 在当前作用域查找标识符
            int count = 0;
            const identifier* existing_id = find_identifier_in_current_scope(var_name, node.scope_ptr);
            if (existing_id != nullptr) 
            {
                count = count_identifiers_in_current_scope(var_name, node.scope_ptr);
            }
            if (count >= 2 && existing_id->kind == IdKind::Var) 
            {
                std::cerr << "Error: Redefinition of variable '" << var_name 
                          << "' (first defined at line " << existing_id->line_number << ")\n";
                return 1;  // 发现错误，立即返回
            }
        }
    }
    // 函数定义检查
    else if (node.name == "function_definition") {
        if (node.children.size() >= 2 && node.children[1] && node.children[1]->name == "Identifier") {
            std::string func_name = node.children[1]->cact_code;
            
            const identifier* existing_func = find_identifier_in_scopes(func_name, node.scope_ptr);
            int def_count = 0;
            if (existing_func != nullptr && existing_func->kind == IdKind::Func) {
                {
                    def_count++;                    
                }
                
            }
            if (def_count>=2)
            {
                std::cerr << "Error: Redefinition of function '" << func_name 
                              << "' (first defined at line " << existing_func->line_number << ")\n";
                return 1;  // 发现错误，立即返回
            }
            
        }
    }
    
    // 递归检查子节点
    for (auto& child : node.children) {
        if (child && redeclaration_check(*child) != 0) {
            return 1;
        }
    }
    return 0;
}
// 检查变量定义时是否等号左右两侧类型匹配，以及数组初始化是否溢出或不完全
int declaration_match(ast_node& node) {
    // 1. 首先检查类型和初始值匹配(原有功能)
    bool is_type_check_done = false;
    
    if (node.name == "variable_definition" && node.children.size() >= 3) {
        if (node.children[1]->name == "Equal" && node.children[2]->name == "constant_initial_value") {
            if (node.parent && node.parent->name == "variable_declaration" && !node.parent->children.empty() && node.parent->children[0]) {
                std::string var_type = node.parent->children[0]->cact_code;
                std::string init_value = node.children[2]->cact_code;
                
                if (var_type == "int") {
                    if (init_value.find('.') != std::string::npos) {
                        std::cerr << "Error: Cannot assign float value to int variable\n";
                        return 1;
                    }
                }
                else if (var_type == "float") {
                    try {
                        std::stof(init_value);
                    } catch (...) {
                        std::cerr << "Error: Invalid float value '" << init_value << "'\n";
                        return 1;
                    }
                }
                is_type_check_done = true;
            }
        }
    }

    // 2. 检查数组初始化
    if (node.name == "variable_definition") {
        // 2.1 检测数组声明
        bool is_array = false;
        int array_size = 0;
        size_t id_index = -1;
        
        for (size_t i = 0; i < node.children.size(); ++i) {
            if (node.children[i] && node.children[i]->name == "Identifier") {
                id_index = i;
                if (i + 2 < node.children.size() && 
                    node.children[i+1] && node.children[i+1]->name == "LeftBracket" &&
                    node.children[i+2] && node.children[i+2]->name == "IntegerConstant") {
                    
                    is_array = true;
                    array_size = std::stoi(node.children[i+2]->cact_code);
                    std::cout << "[Array Check] Found array declaration: " 
                              << node.children[i]->cact_code << "[" << array_size << "]" 
                              << std::endl;
                    break;
                }
            }
        }
        
        if (!is_array) {
            // 不是数组定义，跳过数组检查
            if (!is_type_check_done) {
                // 如果类型检查还没做，这里可以添加其他检查
                // 目前根据上下文，似乎不需要额外检查
            }
            return 0;
        }

        // 2.2 查找初始化列表
        const ast_node* init_list = nullptr;
        if (node.children.size() >= 3 && 
            node.children[1] && node.children[1]->name == "Equal" &&
            node.children[2] && node.children[2]->name == "constant_initial_value") {
            
            init_list = node.children[2].get();
            std::cout << "[Array Check] Found initialization list node" << std::endl;
            print_detailed_ast(*init_list, 1);
        }

        // 2.3 计算元素数量
        if (init_list) {
            int element_count = count_array_elements(*init_list);
            std::cout << "[Array Check] Element count: " << element_count 
                      << ", Array size: " << array_size << std::endl;
            
            if (element_count > array_size) {
                std::cerr << "Error: Array initialization overflow: " 
                          << element_count << " elements for size " 
                          << array_size << "\n";
                return 1;
            }
            else if (element_count < array_size) {
                std::cerr << "Error: Array initialization incomplete: " 
                          << element_count << " elements for size " 
                          << array_size << "\n";
                return 1;
            }
        }
        
        // 数组检查完成后，不需要再做其他检查
        return 0;
    }
    
    // 如果不是数组定义，且类型检查也没做(虽然根据当前逻辑不太可能)
    // 这里可以添加其他检查
    // 目前根据上下文，似乎不需要额外检查
    
    // 递归检查子节点
    for (auto& child : node.children) {
        if (child && declaration_match(*child) != 0) {
            return 1;
        }
    }
    return 0;
}
// 改进的初始化列表元素计数函数
int count_array_elements(const ast_node& init_value_node) {
    int count = 0;
    
    // 查找花括号节点
    for (const auto& child : init_value_node.children) {
        if (child && child->name == "LeftBrace") {
            // 遍历花括号内的所有子节点
            for (const auto& grandchild : child->children) {
                if (grandchild && grandchild->name != "Comma") {
                    // 每个非逗号节点算一个元素
                    count++;
                    
                    // 如果是嵌套的初始化列表(如多维数组)，递归处理
                    if (grandchild->name == "constant_initial_value") {
                        count--;  // 减去外层计数
                        count += count_array_elements(*grandchild);  // 加上内层计数
                    }
                }
            }
            break;  // 只处理最外层的LeftBrace
        }
    }
    
    // 如果没有找到花括号，可能是单个值(非标准情况)
    if (count == 0) {
        if (init_value_node.name == "IntegerConstant" || 
            init_value_node.name == "FloatConstant" || 
            init_value_node.name == "CharConstant") {
            return 1;
        }
    }
    
    return count;
}

// 更详细的AST打印函数
void print_detailed_ast(const ast_node& node, int indent) {
    for (int i = 0; i < indent; ++i) std::cout << "  ";
    std::cout << node.name;
    if (!node.cact_code.empty()) {
        std::cout << " (" << node.cact_code << ")";
    }
    std::cout << std::endl;
    
    for (const auto& child : node.children) {
        if (child) {
            print_detailed_ast(*child, indent + 1);
        }
    }
}    
    // 检查常量值是否被修改
int const_change(ast_node& node) {
    // 情况1: 直接赋值表达式(如a=2)
    if (node.name == "assignment_expression") {
        // 确保赋值表达式有子节点
        if (!node.children.empty()) {
            // 获取赋值表达式的左侧(left_value)
            ast_node* left_side = node.children[0].get();
            
            // 检查left_value情况(如a=2或a[0]=2)
            if (left_side && left_side->name == "left_value") {
                // 递归检查left_value中的所有Identifier
                // 因为left_value可能包含嵌套的Identifier(如数组访问中的a)
                if (!check_left_value_for_constants(*left_side)) {
                    return 1;  // 如果发现常量修改，直接返回
                }
            }
        }
    }
    
    // 情况2: 递归检查所有子节点
    // 这样可以捕获嵌套的赋值表达式中的常量修改
    for (auto& child : node.children) {
        if (child && const_change(*child) != 0) {
            return 1;
        }
    }
    
    return 0;
}

// 辅助函数：检查left_value中是否包含常量修改
bool check_left_value_for_constants(ast_node& left_value_node) {
    // 遍历left_value的所有子节点
    for (auto& child : left_value_node.children) {
        if (!child) continue;
        
        // 如果子节点是Identifier，检查是否是常量
        if (child->name == "Identifier") {
            std::string var_name = child->cact_code;
            const identifier* id = find_identifier_in_scopes(var_name, child->scope_ptr);
            
            if (id != nullptr && id->kind == IdKind::Const) {
                std::cerr << "Error: Cannot modify constant variable '" << var_name 
                          << "' (defined at line " << id->line_number << ")\n";
                return false;  // 发现常量修改
            }
        }
        
        // 如果子节点是其他left_value(如数组访问中的a[0]中的a)
        // 递归检查
        if (!check_left_value_for_constants(*child)) {
            return false;
        }
    }
    
    return true;  // 没有发现常量修改
}
    // 检查函数调用参数匹配
    int function_param_check(ast_node& node) {
        if (node.name == "function_call") {
            // 获取函数名 - 假设第一个子节点是标识符
            if (!node.children.empty() && node.children[0] && node.children[0]->name == "Identifier") {  // 添加空指针检查
                std::string func_name = node.children[0]->cact_code;
                const identifier* func_id = find_identifier_in_scopes(func_name, node.scope_ptr);
                
                if (func_id == nullptr) {
                    std::cerr << "Error: Function '" << func_name << "' not declared\n";
                    return 1;
                }
                
                if (func_id->kind != IdKind::Func) {
                    std::cerr << "Error: '" << func_name << "' is not a function (defined at line " 
                              << func_id->line_number << ")\n";  // 使用func_id->line_number
                    return 1;
                }
                
                // 检查参数个数和类型
                size_t expected_params = func_id->func_params.size();
                size_t actual_params = 0;
                
                // 计算实际参数个数
                for (size_t i = 1; i < node.children.size(); ++i) {
                    if (node.children[i] && node.children[i]->name != "Comma") {  // 添加空指针检查
                        actual_params++;
                    }
                }
                
                if (expected_params != actual_params) {
                    std::cerr << "Error: Function '" << func_name << "' (defined at line " 
                              << func_id->line_number << ") expects " << expected_params 
                              << " arguments but " << actual_params << " were provided\n";  // 使用func_id->line_number
                    return 1;
                }
                
                // 这里可以添加更详细的参数类型检查
            }
        }
        
        // 递归检查子节点
        for (auto& child : node.children) {
            if (child && function_param_check(*child) != 0) {  // 添加空指针检查
                return 1;
            }
        }
        return 0;
    }
}