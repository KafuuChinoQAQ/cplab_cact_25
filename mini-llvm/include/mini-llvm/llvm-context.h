//
// Created by creeper on 9/23/24.
//

#ifndef CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_LLVM_CONTEXT_H
#define CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_LLVM_CONTEXT_H

#include <mini-llvm/array-type.h>
#include <mini-llvm/constant-scalar.h>
#include <mini-llvm/constant.h>
#include <mini-llvm/function-type.h>
#include <mini-llvm/integer-type.h>
#include <mini-llvm/pointer-type.h>
#include <mini-llvm/type.h>
#include <memory>
#include <string_view>
namespace llvm {

struct Type;
struct ArrayType;
struct PointerType;
struct TypeSystem;
struct ConstantPool;
struct IntegerType;
uint8_t stoinst(const std::string &str);
std::string inst2String(uint8_t opCode);
struct LLVMContext {
  LLVMContext();
  ~LLVMContext();
  // String to Basic Type
  [[nodiscard]] CRef<Type> stobt(const std::string &str) const;
  [[nodiscard]] CRef<ArrayType> arrayType(CRef<Type> elementType,
                                          size_t size) const;
  [[nodiscard]] CRef<PointerType> pointerType(CRef<Type> elementType) const;
  [[nodiscard]] CRef<FunctionType>
  functionType(const std::vector<CRef<Type>> &containedTypes) const;
  [[nodiscard]] CRef<Type> voidType() const;
  [[nodiscard]] CRef<Type> floatType() const;
  [[nodiscard]] CRef<Type> doubleType() const;
  [[nodiscard]] CRef<IntegerType> boolType() const;
  [[nodiscard]] CRef<IntegerType> intType() const;
  [[nodiscard]] CRef<IntegerType> longType() const;
  [[nodiscard]] CRef<Type> labelType() const;
  // for constant scalar, str should be the corresponding string of the number
  // for constant array, str should be the name of the array
  // all global array that are marked const should be stored in the constant
  // pool
  [[nodiscard]] Ref<Constant> constant(CRef<Type> type,
                                       const std::string &str) const;
  [[nodiscard]] Ref<Constant>
  createConstantArray(const std::string &name, CRef<ArrayType> arrayType,
                      std::vector<CRef<Constant>> &&elements) const;
  [[nodiscard]] CRef<PointerType>
  castFromArrayType(CRef<ArrayType> arrayType) const;
  [[nodiscard]] CRef<Constant> constantZero(CRef<Type> type) const;
  [[nodiscard]] Scalar evalConstScalar(CRef<ConstantScalar> constScalar) const;
  [[nodiscard]] CRef<Constant> builtinVoidValue() const;

private:
  std::unique_ptr<TypeSystem> typeSystem{};
  std::unique_ptr<ConstantPool> constantPool{};
};

} // namespace llvm
#endif // CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_LLVM_CONTEXT_H
