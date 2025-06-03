#ifndef CPLAB_IR_GENERATOR_H
#define CPLAB_IR_GENERATOR_H
#include "basic_type.h" // 引入基本数据类型定义
namespace cplab_ir_generator
{
    // 生成declaration相关结点的IR代码
    void ir_gen_declaration(ast_node &node);


}
#endif // CPLAB_IR_GENERATOR_H