//
// Created by creeper on 11/16/24.
//
#include <mini-llvm/executor.h>
#include <mini-llvm/constant.h>
#include <mini-llvm/constant-scalar.h>
namespace llvm {
llvm::Result &llvm::Executor::reg(CRef<Value> value) {
  if (auto constant = cast<Constant>(value)) {
    if (auto constantScalar = cast<ConstantScalar>(constant)) {

    } else
      throw std::runtime_error("constant pointer or array cannot be stored in a register");
  }
  return callFrames.back().regs.at(value->name());
}
}
