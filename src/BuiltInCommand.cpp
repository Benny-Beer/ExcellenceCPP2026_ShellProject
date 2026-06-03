#include "BuiltInCommand.h"

std::map<std::string, std::unique_ptr<BuiltInCommand>>& BuiltInCommandContainer::getRegistry()
{
    static std::map<std::string, std::unique_ptr<BuiltInCommand>> registry;
    return registry;
}

bool BuiltInCommandContainer::registerCommand(std::unique_ptr<BuiltInCommand> cmd)
{
    getRegistry()[cmd->getName()] = std::move(cmd);
    return true;
}

std::unique_ptr<BuiltInCommand>* BuiltInCommandContainer::findCommand(const std::string& name)
{
    auto it = getRegistry().find(name);
    if (it == getRegistry().end()) return nullptr;
    return &it->second;
}

bool BuiltInCommandContainer::executeInternalCommand(const std::vector<std::string>& args)
{
    auto cmd = findCommand(args[0]);
    if (cmd == nullptr) return false;
    (*cmd)->execute(args);
    return true;
}