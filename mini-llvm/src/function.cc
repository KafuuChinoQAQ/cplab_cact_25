//
// Created by creeper on 11/3/24.
//
#include <mini-llvm/basic-block.h>
#include <mini-llvm/executor.h>
#include <mini-llvm/function.h>
#include <iostream>

namespace llvm {

void Function::accept(Executor &executor) {
  auto &entry = *impl->m_basicBlocks.front();
  executor.execute(entry);
  while (!executor.returnFlag) {
    const auto &nxt = executor.nxtBasicBlock;
    executor.execute(basicBlock(nxt));
  }
}

void Function::addBasicBlock(std::unique_ptr<BasicBlock> &&bb) {
  if (!impl)
    impl.emplace();
  auto bbRef = makeRef(*bb);
  impl->basicBlockMap.insert({bb->name(), bbRef});
  impl->m_basicBlocks.emplace_back(std::move(bb));
  impl->basicBlockIterMap.insert({bbRef, --impl->m_basicBlocks.end()});
}

bool Function::hasIdentifier(const std::string &name) const {
  assert(impl.has_value());
  for (auto arg : m_args)
    if (arg->name() == name)
      return true;
  for (const auto &bb : basicBlocks())
    if (bb.hasIdentifier(name))
      return true;
  return false;
}

void Function::removeBasicBlock(Ref<BasicBlock> bb) {
  assert(impl);
  assert(!bb->isUsed());
  impl->basicBlockMap.erase(bb->name());
  auto it = impl->basicBlockIterMap[bb];
  impl->basicBlockIterMap.erase(bb);
  impl->m_basicBlocks.erase(it);
}

Value &Function::identifier(const std::string &name) {
  for (const auto &arg : m_args)
    if (arg->name() == name)
      return *arg;
  for (const auto &bb : basicBlocks())
    if (bb.hasIdentifier(name))
      return bb.identifier(name);
  throw std::runtime_error("identifier not found");
}

const Value &Function::identifier(const std::string &name) const {
  for (const auto &arg : m_args)
    if (arg->name() == name)
      return *arg;
  for (const auto &bb : basicBlocks())
    if (bb.hasIdentifier(name))
      return bb.identifier(name);
  throw std::runtime_error("identifier not found");
}
} // namespace llvm