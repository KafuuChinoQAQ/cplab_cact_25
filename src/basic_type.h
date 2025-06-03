// 该头文件定义了我们接下来需要用到的各种基本数据类型
#ifndef BASIC_TYPE_H
#define BASIC_TYPE_H
#include "antlr4-runtime.h"
#include <list>
struct ast_node; // 前向声明ast_node结构体
struct identifier; // 前向声明identifier结构体
struct scope_node; // 前向声明scope_node结构体

// 自定义AST节点类型
struct ast_node {
    int node_index; // 节点索引
    std::string name; // 节点名称
    std::string cact_code; // 当前节点对应的cact源代码片段
    std::string ir_code; // 当前节点对应的IR代码片段
    scope_node* scope_ptr; // 当前节点所处作用域
    
    ast_node* parent; // 父节点指针
    std::vector<std::unique_ptr<ast_node>> children; // 子节点列表
};

// 存储单个标识符的数据结构
struct identifier {
    bool is_func; // 表示该结点是否为func
    std::string type; // 变量/常量类型 仅非func类
    std::string func_return_type; // 函数返回类型 仅func类
    std::string name; // 变量/常量/函数名称
    std::vector<identifier> func_params; // 函数参数列表 仅func类

};

// 自定义作用域节点类型
struct scope_node {
    std::string name; // 节点名称
    scope_node *parent; // 父作用域指针
    std::list<scope_node> children; // 子节点列表 使用list防止在增加子节点时已有节点的地址发生变化
    std::vector<identifier> identifiers; // 该作用域下的标识符
};
#endif