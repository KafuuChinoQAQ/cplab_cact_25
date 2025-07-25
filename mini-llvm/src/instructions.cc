//
// Created by creeper on 12/31/24.
//
#include <mini-llvm/executor.h>
#include <mini-llvm/function.h>
#include <mini-llvm/instructions.h>
#include <mini-llvm/module.h>
#include <functional>
#include <numeric>
namespace llvm {

void BinaryInst::accept(Executor &executor) {
  const auto &lhsReg = executor.reg(lhs());
  const auto &rhsReg = executor.reg(rhs());
  if (!lhsReg.canOperateWith(rhsReg))
    throw std::runtime_error("Binary instruction operands must have the same "
                             "type and cannot be an address or a boolean");

  static std::unordered_map<BinaryOps, std::function<Result::Integer(
                                           Result::Integer, Result::Integer)>>
      intOps = {
          {Add,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 + arg2);
                 },
                 lhs, rhs);
           }},
          {Sub,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 - arg2);
                 },
                 lhs, rhs);
           }},
          {Mul,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 * arg2);
                 },
                 lhs, rhs);
           }},
          {SDiv,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 / arg2);
                 },
                 lhs, rhs);
           }},
          {SRem,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 % arg2);
                 },
                 lhs, rhs);
           }},
          {Xor,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 ^ arg2);
                 },
                 lhs, rhs);
           }},
          {Shl,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 << arg2);
                 },
                 lhs, rhs);
           }},
          {LShr,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 >> arg2);
                 },
                 lhs, rhs);
           }},
          {AShr,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Integer(arg1 >> arg2);
                 },
                 lhs, rhs);
           }},
      };

  static std::unordered_map<BinaryOps, std::function<Result::Floating(
                                           Result::Floating, Result::Floating)>>
      floatOps = {
          {FAdd,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Floating(arg1 + arg2);
                 },
                 lhs, rhs);
           }},
          {FSub,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Floating(arg1 - arg2);
                 },
                 lhs, rhs);
           }},
          {FMul,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Floating(arg1 * arg2);
                 },
                 lhs, rhs);
           }},
          {FDiv,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(
                 [](auto arg1, auto arg2) {
                   return Result::Floating(arg1 / arg2);
                 },
                 lhs, rhs);
           }},
      };

  if (isIntBinary())
    executor.reg(name()) = Result::fromInteger(intOps.at(static_cast<BinaryOps>(
        opCode))(lhsReg.toInteger(), rhsReg.toInteger()));
  else if (isFloatBinary())
    executor.reg(name()) =
        Result::fromFloating(floatOps.at(static_cast<BinaryOps>(opCode))(
            lhsReg.toFloating(), rhsReg.toFloating()));
  else
    throw std::runtime_error("What the fucking binary instruction is this?");
}

void StoreInst::accept(Executor &executor) {
  auto dest = executor.reg(pointer());
  if (dest.isPointer())
    throw std::runtime_error("Store instruction cannot store a pointer");
  auto span = std::get<SpanAddress>(dest.value);
  executor.store(span, executor.reg(value()));
}

void LoadInst::accept(Executor &executor) {
  auto src = executor.reg(pointer());
  if (!src.isPointer())
    throw std::runtime_error(
        "Load instruction must have a pointer as its source");
  auto span = std::get<SpanAddress>(src.value);
  executor.reg(name()) = executor.load(span);
}

void CallInst::accept(Executor &executor) {
  auto func = executor.module.function(function()->name());
  executor.pushFrame();
  for (auto arg : func->args())
    executor.reg(arg) = executor.reg(arg);
  executor.execute(func);
  executor.returnFlag = false;
  executor.reg(name()) = executor.returnReg.value();
}

std::string CallInst::toString() const {
  std::string args{};
  for (const auto &arg : realArgs())
    args += arg->type()->toString() + " " + arg->name() + ", ";
  if (!args.empty()) {
    assert(args.ends_with(", "));
    args.pop_back();
    args.pop_back();
  }
  if (type()->isVoid())
    return std::format("call {} {}({})", type()->toString(), function()->name(),
                       args);
  return std::format("{} = call {} {}({})", name(), type()->toString(),
                     function()->name(), args);
}

void CmpInst::accept(Executor &executor) {
  static std::unordered_map<
      Predicate, std::function<bool(Result::Integer, Result::Integer)>>
      intPredicates = {
          {Predicate::EQ,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::equal_to(), lhs, rhs);
           }},
          {Predicate::NE,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::not_equal_to(), lhs, rhs);
           }},
          {Predicate::OGT,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::greater(), lhs, rhs);
           }},
          {Predicate::OGE,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::greater_equal(), lhs, rhs);
           }},
          {Predicate::OLT,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::less(), lhs, rhs);
           }},
          {Predicate::OLE,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::less_equal(), lhs, rhs);
           }},
          {Predicate::SGT,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::greater(), lhs, rhs);
           }},
          {Predicate::SGE,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::greater_equal(), lhs, rhs);
           }},
          {Predicate::SLT,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::less(), lhs, rhs);
           }},
          {Predicate::SLE,
           [](Result::Integer lhs, Result::Integer rhs) {
             return std::visit(std::less_equal(), lhs, rhs);
           }},
      };

  static std::unordered_map<
      Predicate, std::function<bool(Result::Floating, Result::Floating)>>
      floatPredicates = {
          {Predicate::EQ,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::equal_to(), lhs, rhs);
           }},
          {Predicate::NE,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::not_equal_to(), lhs, rhs);
           }},
          {Predicate::OGT,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::greater(), lhs, rhs);
           }},
          {Predicate::OGE,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::greater_equal(), lhs, rhs);
           }},
          {Predicate::OLT,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::less(), lhs, rhs);
           }},
          {Predicate::OLE,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::less_equal(), lhs, rhs);
           }},
          {Predicate::SGT,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::greater(), lhs, rhs);
           }},
          {Predicate::SGE,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::greater_equal(), lhs, rhs);
           }},
          {Predicate::SLT,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::less(), lhs, rhs);
           }},
          {Predicate::SLE,
           [](Result::Floating lhs, Result::Floating rhs) {
             return std::visit(std::less_equal(), lhs, rhs);
           }},
      };

  const auto &lhsReg = executor.reg(lhs());
  const auto &rhsReg = executor.reg(rhs());

  if (!lhsReg.canOperateWith(rhsReg))
    throw std::runtime_error("Binary instruction operands must have the same "
                             "type and cannot be an address or a boolean");

  if (isIntBinary())
    executor.reg(name()) = Result{
        intPredicates[predicate](lhsReg.toInteger(), rhsReg.toInteger())};
  else if (isFloatBinary())
    executor.reg(name()) = Result{
        floatPredicates[predicate](lhsReg.toFloating(), rhsReg.toFloating())};
  else
    throw std::runtime_error(
        "What the fucking comparison instruction is this?");
}
std::string CmpInst::toString() const {
  return std::format("{} = {}cmp {} {}, {}", name(),
                     lhs()->type()->isInteger() ? "i" : "f",
                     llvm::toString(predicate), lhs()->name(), rhs()->name());
}
std::string genBrInstName() {
  static int id{};
  return std::format("__br_{}", id++);
}

void PhiInst::accept(Executor &executor) {
  const auto &incoming = executor.prvBasicBlock;
  for (auto i = 0; i < incomingValues.size(); ++i) {
    if (incomingBlocks[i]->name() == incoming) {
      executor.reg(name()) = executor.reg(incomingValues[i]->name());
      return;
    }
  }
}

std::string PhiInst::toString() const {
  std::string phiVals{};
  for (auto i = 0; i < incomingValues.size(); ++i) {
    phiVals += std::format("[{}, {}], ", incomingBlocks[i]->name(),
                           incomingValues[i]->name());
  }
  return std::format("{} = phi {} {}", name(), type()->toString(), phiVals);
}

void BrInst::accept(Executor &executor) {
  if (isConditional()) {
    if (executor.reg(cond().name()).isBool()) {
      if (std::get<bool>(executor.reg(cond().name()).value))
        executor.nxtBasicBlock = thenBranch().name();
      else
        executor.nxtBasicBlock = elseBranch().name();
    } else
      throw std::runtime_error("Branch condition must be a boolean");
  } else
    executor.nxtBasicBlock = thenBranch().name();
  executor.prvBasicBlock = basicBlock.name();
}
std::string BrInst::toString() const {
  if (isConditional())
    return std::format("br i1 {}, label %{}, label %{}", cond().name(),
                       thenBranch().name(), elseBranch().name());
  return std::format("br label %{}", thenBranch().name());
}

void GepInst::accept(Executor &executor) {
  if (!pointer()->type()->isPointer())
    throw std::runtime_error(
        "GEP instruction must have a pointer as its source");

  // if (!index)
  // executor.reg(name()) = Result(SpanAddress{.begin =
  // RuntimeVar(makeCRef(pointer)), 0});
  // else
  // executor.reg(name()) = Result(SpanAddress{.begin =
  // RuntimeVar(makeCRef(pointer)), executor.reg(index).as<size_t>()});
}

std::string genReturnInstName() {
  static int id{};
  return std::format("__ret_{}", id++);
}
void RetInst::accept(Executor &executor) {
  executor.returnReg = m_ret == nullptr
                           ? std::nullopt
                           : std::make_optional(executor.reg(ret()->name()));
  executor.returnFlag = true;
  executor.popFrame();
}

void AllocaInst::accept(Executor &executor) {
  if (!size)
    throw std::runtime_error("Alloca instruction must have a size");
  executor.allocate(name(), size);
}
} // namespace llvm