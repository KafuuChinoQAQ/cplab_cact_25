//
// Created by creeper on 9/29/24.
//

#ifndef CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_MODULE_H
#define CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_MODULE_H

#include <string>
#include <mystl/manager_vector.h>
#include <mini-llvm/ref.h>
#include <mini-llvm/global-variable.h>
namespace llvm {
struct GlobalVariable;
struct Function;

struct Module final : Executable {
  [[nodiscard]] const std::string &name() const {
    return m_name;
  }
  mystl::manager_vector<GlobalVariable> globalVariables;
  mystl::manager_vector<Function> functions;
  Ref<GlobalVariable> globalVariable(const std::string& name) const {
    return m_globalVariableMap.at(name);
  }
  Ref<Function> function(const std::string& name) const {
    return m_functionMap.at(name);
  }
  bool hasFunction(const std::string& name) const {
    return m_functionMap.contains(name);
  }
  bool hasGlobalVar(const std::string& name) const {
    return m_globalVariableMap.contains(name);
  }
  std::unordered_map<CRef<Function>, std::vector<CRef<Function>>> callGraph() const;
  std::unordered_map<CRef<Function>, std::vector<CRef<Function>>> reverseCallGraph() const;
  Module& addFunction(std::unique_ptr<Function>&& function);
  Module& addGlobalVariable(std::unique_ptr<GlobalVariable>&& globalVariable);
  void accept(Executor &executor) override;

private:
  std::unordered_map<std::string, Ref<GlobalVariable>> m_globalVariableMap;
  std::unordered_map<std::string, Ref<Function>> m_functionMap;
  std::string m_name;
};

}
#endif //CACTRIE_CHIISAI_LLVM_INCLUDE_CHIISAI_LLVM_MODULE_H
