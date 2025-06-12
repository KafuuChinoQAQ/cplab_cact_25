// 该头文件定义了我们接下来需要用到的各种基本数据类型
#ifndef BASIC_TYPE_H
#define BASIC_TYPE_H
#include "antlr4-runtime.h"
#include <list>
#include <variant>

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
    std::vector<std::unique_ptr<ast_node>> children; // 子节点向量
    //↑不要修改这些属性
};

// 存储单个标识符的数据结构
enum class IdKind {
    Func = 1, // 函数
    Var = 2,  // 变量
    Const = 3, // 常量
    Param = 4 // 函数参数
};

struct identifier {
    IdKind kind; // 表示该结点是否为函数/变量/常量
    std::string type; // 变量/常量类型 仅非Func类
    std::string func_return_type; // 函数返回类型 仅Func类
    std::string name; // 变量/常量/函数名称
    std::vector<identifier> func_params; // 函数参数列表 仅Func类
    int line_number; // 该标识符所在的行号,用于错误提示和静态检查
    int id_index; //该id的全局索引,用于确定IR代码生成时的唯一符号
    std::variant<int, float, char,std::vector<int>, std::vector<float>, std::vector<char>> const_value; // 常量初始值,仅Const类

    bool is_global; // 是否为全局变量
};

// 自定义作用域节点类型
struct scope_node {
    std::string name; // 节点名称
    scope_node *parent; // 父作用域指针
    std::list<scope_node> children; // 子节点列表 使用list防止在增加子节点时已有节点的地址发生变化
    std::vector<identifier> identifiers; // 该作用域下的标识符
};

#endif