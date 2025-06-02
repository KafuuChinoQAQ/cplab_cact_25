//本文件中的代码用于将antlr4生成的ParserTree转换为自定义的AST结构
#include "ast_generator.h"
namespace cplab_ast_generator 
{
    // AST生成器函数 返回AST根节点
    int ast_node_index = 0; // 全局变量，用于跟踪AST节点索引
    ast_node ast_generator(antlr4::tree::ParseTree *tree, antlr4::Parser *parser)
    {
        ast_node node; // 创建AST节点
        node.node_index = ast_node_index; // 设置当前节点索引
        ast_node_index++; // 增加全局节点索引
        // 设置当前AST节点属性
        // 如果当前ParseTree节点是非终结符节点
        if (auto *ctx = dynamic_cast<antlr4::ParserRuleContext *>(tree)) {
            node.name = parser->getRuleNames()[ctx->getRuleIndex()]; // 设置节点名称为规则名称
            node.cact_code = ctx->getText(); // 设置节点对应的cact代码片段
        }
        // 如果当前ParseTree节点是终结符节点
        else if (auto *terminalNode = dynamic_cast<antlr4::tree::TerminalNode *>(tree)) {
            int lexeme_type = terminalNode->getSymbol()->getType(); // 获取终结符的token类型
            node.name = parser->getVocabulary().getSymbolicName(lexeme_type); // 设置节点名称为token类型名称
            node.cact_code = terminalNode->getText(); // 设置节点对应的cact代码片段
        } 

        // 递归处理子节点
        for (auto *child : tree->children) {
            if (child) { // 确保子节点不为空
                ast_node child_node = ast_generator(child, parser); // 递归调用生成子节点的AST
                node.children.push_back(child_node); // 将子节点添加到当前节点的子节点列表中
                child_node.parent = &node; // 设置子节点的父节点为当前节点
            }
        }

        return node; // 返回AST节点
    }

    // AST打印函数,以先序遍历的顺序打印AST的每一个结点及其成员到给定的文本文件中
    void ast_printer(ast_node node, std::ostream &out)
    {
        // 打印当前节点
        out << node.node_index << ". " << node.name << std::endl; // 打印节点索引和名称
        if (!node.cact_code.empty()) {
            out << "cact_code: " << node.cact_code << std::endl; // 打印cact源码
        }
        if (!node.ir_code.empty()) {
            out << "ir_code: " << node.ir_code << std::endl; // 打印IR代码
        }
        if( node.children.empty()) {
            out << "children: []" << std::endl; // 如果没有子节点，打印空列表
        } 
        else 
        {
            out << "children: [" << std::endl; // 打印子节点列表开始
            for (const auto &child : node.children) 
            {
                out << "  " << child.node_index << ". " << child.name << std::endl; // 打印每个子节点的索引和名称
            }
            out << "]" << std::endl; // 打印子节点列表结束
        }
        out << std::endl; // 打印空行分隔节点
        // 递归打印子节点
        for (const auto &child : node.children) {
            ast_printer(child, out);
        }
        return ;
    }
}