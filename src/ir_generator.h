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

}
#endif // CPLAB_IR_GENERATOR_H