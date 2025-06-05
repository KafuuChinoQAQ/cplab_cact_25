#ifndef CPLAB_IR_GENERATOR_H
#define CPLAB_IR_GENERATOR_H
#include "basic_type.h" // 引入基本数据类型定义
namespace cplab_ir_generator
{
    // 总入口
    void ir_generator(ast_node &ast_root);
    // 生成declaration相关结点的IR代码
    void ir_gen_declaration(ast_node &node);
    // 将Cact类型转换为LLVM数组类型 用于数组变量的声明
    std::string to_llvm_array_type(const std::string& type_str);
    // 计算单个number的值的函数,接受一个number节点,返回该节点的值
    std::variant<int, float, char> calculate_number_value(const ast_node &node);
    //计算一个constant_expression的值的函数,除了单个number以外,这个常量表达式至多含有一个取反表达式
    std::variant<int, float, char> calculate_constant_expression_value(const ast_node &node, std::string type);
    // 计算一个任意的变量表达式的值,接受一个expression节点,将ir_code添加到节点的属性上,并返回在IR中暂存了该值的寄存器%n
    std::string calculate_expression_value(ast_node &node, std::string type);
}
#endif // CPLAB_IR_GENERATOR_H