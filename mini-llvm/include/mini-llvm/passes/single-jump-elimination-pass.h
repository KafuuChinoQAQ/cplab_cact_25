//
// Created by creeper on 12/15/24.
//
#ifndef SINGLE_JUMP_ELIMINATION_PASS_H
#define SINGLE_JUMP_ELIMINATION_PASS_H
#include <mini-llvm/function.h>
#include <mini-llvm/instructions.h>
#include <minilog/logger.h>
#include <queue>
namespace llvm {

// for those basic blocks with only one unconditional jump, we remove them
struct SingleJumpEliminationPass {
  explicit SingleJumpEliminationPass()
      : logger(minilog::createFileLogger("single-jump-elimination.log")) {}
  void runOnFunction(Function &func) const {
    bool isChanged = false;
    std::vector<Ref<BasicBlock>> toBeRemoved{};
    do {
      isChanged = false;
      toBeRemoved.clear();
      for (auto bb : func.basicBlockRefs()) {
        assert(!bb->instructions.empty());
        if (bb->instructions.size() > 1)
          continue;
        if (bb->successors.size() > 1)
          continue;

        bool canBeEliminated = false;
        Ref<BasicBlock> jumpDest{};

        if (auto onlyInst = makeRef(bb->instructions.front());
            isa<BrInst>(onlyInst)) {
          if (auto brInst = cast<BrInst>(onlyInst); !brInst->isConditional()) {
            jumpDest = makeRef(brInst->thenBranch());
            canBeEliminated = true;
          }
        }

        if (!canBeEliminated)
          continue;
        assert(jumpDest != bb);
        logger->info("SingleJumpEliminationPass: "
                     "basic block {} can be eliminated",
                     bb->name());
        for (auto pred : bb->predecessors) {
          for (auto &block : pred->successors) {
            if (block == bb) {
              block = jumpDest;
              break;
            }
          }
        }

        if (auto succ = bb->successors.front()) {
          for (auto pred : succ->predecessors) {
            if (pred != bb)
              continue;
            for (auto bbPred : bb->predecessors) {
              if (std::ranges::find(succ->predecessors,
                            bbPred) != succ->predecessors.end())
                continue;
              succ->predecessors.emplace_back(bbPred);
            }
          }
          succ->predecessors.remove(bb);
        }

        bb->replaceAllUsesWith(jumpDest);

        toBeRemoved.emplace_back(bb);
        logger->info("SingleJumpEliminationPass: "
                     "basic block {} has been replaced by basic block {}",
                     bb->name(), jumpDest->name());
        isChanged = true;
      }
      for (auto bb : toBeRemoved)
        func.removeBasicBlock(bb);
      logger->outStream().flush();
    } while (isChanged);
  }
  std::unique_ptr<minilog::Logger> logger{};
};
} // namespace llvm
#endif // SINGLE_JUMP_ELIMINATION_PASS_H
