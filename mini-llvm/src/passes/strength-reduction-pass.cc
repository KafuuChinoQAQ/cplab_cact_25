//
// Created by creeper on 12/18/24.
//
#include <mini-llvm/passes/strength-reduction-pass.h>

namespace llvm {

bool StrengthReductionPass::runOnBasicBlock(BasicBlock &block) {
  for (auto inst : block.instructions) {

  }
  return {};
}
} // namespace llvm