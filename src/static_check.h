#ifndef CPLAB_STATIC_CHECK_H
#define CPLAB_STATIC_CHECK_H
#include "basic_type.h" // 引入基本数据类型定义
namespace cplab_static_check
{
    // 辅助函数：在作用域链中查找标识符
    const identifier* find_identifier_in_scopes(const std::string& name, const scope_node* current_scope);
    // 辅助函数：在当前作用域中查找标识符
    const identifier* find_identifier_in_current_scope(const std::string& name, const scope_node* current_scope);
    //检查变量被使用时是否已被定义，若有定义返回0,未定义返回1
    int declaration_check(ast_node& node);
    //检查变量定义时是否被重复定义，若无重复返回0,有重复返回1
    int redeclaration_check(ast_node& node);
    //检查变量定义时是否等号左右两侧匹配，若匹配返回0,不匹配返回1
    int declaration_match(ast_node& node);
    //检查常量值是否被修改，若无返回0,有返回1
    int const_change(ast_node& node);
    // 检查函数调用参数匹配
    int function_param_check(ast_node& node);
    //辅助函数：检查left_value中是否包含常量修改
    bool check_left_value_for_constants(ast_node& left_value_node);
    // 辅助函数：计算初始化列表中的元素数量
    int count_array_elements(const ast_node& init_value_node);
    // 辅助函数：打印AST节点结构
    void print_detailed_ast(const ast_node& node, int indent);
}
#endif