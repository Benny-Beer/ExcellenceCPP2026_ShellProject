#include "../../include/commands/ExitCommand.h"
#include <iostream>

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<ExitCommand>());

void ExitCommand::execute(const std::vector<std::string>& args)
{
    std::cout << "Exiting shell...\n";
    exit(0);
}