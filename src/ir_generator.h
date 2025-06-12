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
    // 根据特定子节点，生成一个exp的ir_code并返回
    std::string exp_gen_ir_code_from_child(ast_node &node, std::string type, int child_index);
    // 获取寄存器类型和对齐方式的函数
    std::pair<std::string, std::string> get_reg_type_and_align(const std::string& type);
    // 获取一个算术表达式应该是什么数据类型的函数,由于我们仅允许相同类型的数据进行算术运算,只需要遍历到第一个终结符节点即可
    std::string get_arithmetic_expression_type(ast_node &node);
    // 传入一个ast_node节点和一个标识符名称,递归向上查找并返回标识符指针的函数
    identifier* find_identifier_in_scope(ast_node &node, std::string id_name);
}
#endif // CPLAB_IR_GENERATOR_H