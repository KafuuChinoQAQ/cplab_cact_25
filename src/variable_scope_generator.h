#ifndef VARIABLE_SCOPE_GENERATOR
#define VARIABLE_SCOPE_GENERATOR
#include "basic_type.h" // 引入AST生成器头文件

namespace cplab_variable_scope_generator 
{
    // 作用域生成器函数 传入一颗AST的根节点,返回生成的作用域树根节点
    scope_node variable_scope_generator(ast_node &ast_root);
    void process_ast_node(ast_node &node, scope_node* current_scope);
    // 作用域打印函数,以先序遍历的顺序打印作用域树的每一个结点及其成员到给定的文本文件中
    void variable_scope_printer(scope_node &node, std::ostream &out);

}
#endif