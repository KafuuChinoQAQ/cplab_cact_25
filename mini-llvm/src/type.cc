//
// Created by creeper on 9/23/24.
//
#include <mini-llvm/array-type.h>
#include <mini-llvm/llvm-context.h>
#include <mini-llvm/ref.h>
#include <mini-llvm/type.h>
namespace llvm {

CRef<Type> Type::voidType(const LLVMContext &ctx) { return ctx.voidType(); }
CRef<Type> Type::floatType(const LLVMContext &ctx) { return ctx.floatType(); }
CRef<Type> Type::doubleType(const LLVMContext &ctx) { return ctx.doubleType(); }
CRef<IntegerType> Type::boolType(const LLVMContext &ctx) {
  return ctx.boolType();
}
CRef<IntegerType> Type::intType(const llvm::LLVMContext &ctx) {
  return ctx.intType();
}
CRef<IntegerType> Type::longType(const llvm::LLVMContext &ctx) {
  return ctx.longType();
}
CRef<Type> Type::labelType(const LLVMContext &ctx) { return ctx.labelType(); }
std::string Type::toString() const {
  switch (type) {
  case TypeEnum::Void:
    return "void";
  case TypeEnum::Float:
    return "float";
  case TypeEnum::Double:
    return "double";
  case TypeEnum::Label:
    return "label";
  case TypeEnum::Function:
    return "function";
  default:
    throw std::runtime_error("toString() should not reach here");
  }
}
} // namespace llvm