//本文件中的代码用于将antlr4生成的ParserTree转换为自定义的AST结构
#include "ast_generator.h"
namespace cplab_ast_generator 
{
    // AST生成器函数 返回AST根节点
    int ast_node_index = 0; // 全局变量，用于跟踪AST节点索引
    ast_node ast_generator(antlr4::tree::ParseTree *tree, antlr4::Parser *parser)
    {
        ast_node node; // 创建AST节点
        node.node_index = ast_node_index++; // 设置当前节点索引并自增
        node.parent = nullptr; // 初始化父节点为nullptr
        node.ir_code = ""; // 初始化IR代码为空
        node.scope_ptr = nullptr; // 初始化作用域指针为nullptr
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
        for (auto *parsetree_child : tree->children) {
            if (parsetree_child) {
                auto child_ast = ast_generator(parsetree_child, parser);
                node.children.push_back(std::make_unique<ast_node>(std::move(child_ast)));
            }
        }

        return node; // 返回AST节点
    }
    // 父节点指针重定向函数,遍历AST树并将每个节点的父节点指针设置为其父节点
    void set_parent_pointers(ast_node &node, ast_node *parent)
    {
        node.parent = parent; // 设置当前节点的父节点指针
        for (auto &child : node.children) {
            set_parent_pointers(*child, &node); // 递归设置子节点的父节点指针
        }
    }

    // AST打印函数,以先序遍历的顺序打印AST的每一个结点及其成员到给定的文本文件中
    void ast_printer(const ast_node& node, std::ostream &out)
    {
        // 打印当前节点
        out << node.node_index << ". " << node.name << std::endl; // 打印节点索引和名称
        if (!node.cact_code.empty()) {
            out << "cact_code: " << node.cact_code << std::endl; // 打印cact源码
        }
        if (!node.ir_code.empty()) {
            out << "ir_code: " << std::endl; // 打印IR代码
            out << "--------------------" << std::endl;
            out << node.ir_code << "--------------------" << std::endl;
        }
        if (node.scope_ptr != nullptr) {
            out << "scope: " << node.scope_ptr->name << std::endl; // 打印作用域名称
        }
        else 
        {
            out << "scope: null" << std::endl; // 如果没有作用域，打印null
        }
        if (node.parent!=nullptr){
            out << "parent: " << node.parent->node_index << ". " << node.parent->name << std::endl; // 打印父节点索引和名称
        }
        else 
        {
            out << "parent: null" << std::endl; // 如果没有父节点，打印null
        }
        if(node.children.empty()) {
            out << "children: []" << std::endl; // 如果没有子节点，打印空列表
        }
        else 
        {
            out << "children: [" << std::endl; // 打印子节点列表开始
            for (const auto &child : node.children) 
            {
                out << "  " << child->node_index << ". " << child->name << std::endl; // 打印每个子节点的索引和名称
            }
            out << "]" << std::endl; // 打印子节点列表结束
        }
        out << std::endl; // 打印空行分隔节点
        // 递归打印子节点
        for (const auto &child : node.children) {
            ast_printer(*child, out);
        }
        return ;
    }
}