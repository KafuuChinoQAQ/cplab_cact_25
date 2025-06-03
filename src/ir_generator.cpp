#include "ir_generator.h"
namespace cplab_ir_generator
{
    // 生成declaration相关结点的IR代码
    // 传入AST根节点给该函数,然后递归地遍历AST树,当找到一个变量/常量声明时,为对应的AST结点生成ir_code属性
    void ir_gen_declaration(ast_node &node)
    {
        if(node.name == "declaration")
        {
            // declaration只有一个子节点,即变量声明或常量声明节点,先生成子节点的ir_code,然后赋给父节点
            ir_gen_declaration(*node.children[0]);
            node.ir_code = node.children[0]->ir_code; // 将子节点的ir_code赋给当前节点
        }
        else if(node.name == "variable_declaration") //生成变量声明节点的ir_code
        {
            
        }
        else
        {
            // 如果不是declaration相关结点,则递归处理子节点
            for (const auto &child : node.children)
            {
                ir_gen_declaration(*child); // 递归调用
            }
        }
    }


}