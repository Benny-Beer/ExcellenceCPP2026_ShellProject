#include "../../include/commands/PwdCommand.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<PwdCommand>());

void PwdCommand::execute(const std::vector<std::string>& args)
{
    std::cout << fs::current_path().string() << "\n";
}