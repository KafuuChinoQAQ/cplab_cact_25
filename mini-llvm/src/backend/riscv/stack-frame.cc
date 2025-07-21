//
// Created by creeper on 1/13/25.
//
#include <mini-llvm/backend/riscv/stack-frame.h>
#include <mini-llvm/backend/riscv/riscv-reg-alloc.h>
namespace llvm {

static RegisterConfig stdCfg = RegisterConfig::standardConfig();
static RegisterConfig fpCfg = RegisterConfig::floatingPointConfig();

bool isCalleeSavedReg(const std::string &pReg) {
  return stdCfg.isCalleeSaved(pReg) || fpCfg.isCalleeSaved(pReg);
}
bool isCallerSavedReg(const std::string &pReg) {
  return !stdCfg.isCalleeSaved(pReg) && !fpCfg.isCalleeSaved(pReg);
}
bool isFloatingPointReg(const std::string &pReg) {
  return pReg.starts_with('f');
}


} // namespace llvm