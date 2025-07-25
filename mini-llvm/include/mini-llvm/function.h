//
// Created by creeper on 9/23/24.
//

#ifndef CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_FUNCTION_H
#define CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_FUNCTION_H
#include <mystl/manager_vector.h>
#include <mini-llvm/argument.h>
#include <mini-llvm/function-type.h>
#include <mini-llvm/basic-block.h>
#include <ranges>

namespace llvm {
struct Module;

struct FunctionInfo {
  std::string name;
  CRef<FunctionType> functionType;
  std::vector<std::string> &&argNames;
  const Module &module;
  bool isImplemented = false;
};

struct BasicBlock;
struct Function final : Value {
  explicit Function(const FunctionInfo &info)
      : Value(info.name, info.functionType), m_module(info.module) {
    for (size_t i = 0; i < info.argNames.size(); ++i)
      addArgument(info.argNames[i], info.functionType->argType(i));
    if (info.isImplemented)
      impl.emplace();
  }

  Function &addArgument(const std::string &name, CRef<Type> type) {
    m_args.emplace_back(name, type);
    m_argMap[name] = m_args.back();
    return *this;
  }

  [[nodiscard]] CRef<Type> returnType() const {
    assert(isa<FunctionType>(type()));
    return cast<FunctionType>(type())->returnValueType();
  }

  [[nodiscard]]
  Argument &arg(const std::string &name) {
    if (m_argMap.contains(name))
      return *m_argMap[name];
    throw std::runtime_error("argument not found");
  }

  const Argument &arg(const std::string &name) const {
    if (m_argMap.contains(name))
      return *m_argMap.at(name);
    throw std::runtime_error("argument not found");
  }

  [[nodiscard]]
  bool isImplemented() const { return impl.has_value(); }

  [[nodiscard]] bool hasArg(const std::string &name) const {
    return m_argMap.contains(name);
  }

  [[nodiscard]] bool hasBasicBlock(const std::string &name) const {
    assert(impl.has_value());
    return impl->basicBlockMap.contains(name);
  }

  auto basicBlocks() const {
    assert(impl);
    return impl->m_basicBlocks |
           std::views::transform([](const std::unique_ptr<BasicBlock> &bb) -> const BasicBlock& {
             return *bb;
           });
  }

  auto basicBlocks() {
    assert(impl);
    return impl->m_basicBlocks |
           std::views::transform([](std::unique_ptr<BasicBlock> &bb) -> BasicBlock& {
             return *bb;
           });
  }

  [[nodiscard]]
  auto basicBlockRefs() {
    assert(impl);
    return impl->m_basicBlocks |
           std::views::transform([](auto &bb) { return makeRef(*bb); });
  }
  auto basicBlockRefs() const {
    assert(impl);
    return impl->m_basicBlocks |
           std::views::transform([](const auto &bb) { return makeRef(*bb); });
  }

  [[nodiscard]] bool hasIdentifier(const std::string &name) const;

  BasicBlock &basicBlock(const std::string &name) {
    assert(impl);
    if (impl->basicBlockMap.contains(name))
      return *impl->basicBlockMap[name];
    throw std::runtime_error("basic block not found in function");
  }

  const BasicBlock &basicBlock(const std::string &name) const {
    assert(impl);
    if (impl->basicBlockMap.contains(name))
      return *impl->basicBlockMap.at(name);
    throw std::runtime_error("basic block not found in function");
  }

  void removeBasicBlock(Ref<BasicBlock> bb);

  [[nodiscard]] Value &identifier(const std::string &name);
  [[nodiscard]] const Value& identifier(const std::string &name) const;
  [[nodiscard]] const mystl::manager_vector<Argument> &args() const {
    return m_args;
  }
  Module &module() { return const_cast<Module &>(m_module); }
  [[nodiscard]] const Module &module() const { return m_module; }
  void accept(Executor &executor) override;

  void addBasicBlock(std::unique_ptr<BasicBlock> &&bb);

private:
  mystl::manager_vector<Argument> m_args{};
  const Module &m_module;
  std::unordered_map<std::string, Ref<Argument>> m_argMap{};
  struct FunctionImpl {
    std::list<std::unique_ptr<BasicBlock>> m_basicBlocks{};
    std::unordered_map<Ref<BasicBlock>, std::list<std::unique_ptr<BasicBlock>>::iterator>
        basicBlockIterMap{};
    std::unordered_map<std::string, Ref<BasicBlock>> basicBlockMap{};
  };
  std::optional<FunctionImpl> impl{};
};
} // namespace llvm
#endif // CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_FUNCTION_H
