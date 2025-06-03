#ifndef CPLAB_AST_GENERATOR
#define CPLAB_AST_GENERATOR
#include "basic_type.h"
namespace cplab_ast_generator
{
    // AST生成器函数 返回AST根节点
    ast_node ast_generator(antlr4::tree::ParseTree *tree, antlr4::Parser *parser);
    // 父节点指针重定向函数,遍历AST树并将每个节点的父节点指针设置为其父节点
    void set_parent_pointers(ast_node &node, ast_node *parent = nullptr);
    // AST打印函数,以先序遍历的顺序打印AST的每一个结点及其成员到给定的文本文件中
    void ast_printer(const ast_node& node, std::ostream &out);
}
#endif