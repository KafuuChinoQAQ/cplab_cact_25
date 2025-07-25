//
// Created by creeper on 10/14/24.
//
#include <mini-llvm/user.h>
#include <minilog/logger.h>

namespace llvm {
void addUse(Ref<User> user, Ref<Value> value) {
  static auto useDefLogger = createFileLogger("useDef.log", minilog::LogLevel::debug);
  if (user == nullptr)
    throw std::runtime_error("user is nullptr");
  if (value == nullptr)
    throw std::runtime_error("value is nullptr");
  user->usedValues.push_back(value);
  value->users.push_back(user);
  useDefLogger->debug("add use: {} -> {}", user->name(), value->name());
}
}