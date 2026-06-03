#include "../../include/commands/CdCommand.h"
#include <iostream>
#include <unistd.h>

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<CdCommand>());

void CdCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() < 2) {
        std::cerr << "cd: missing argument\n";
        return;
    }
    if (chdir(args[1].c_str()) != 0) {
        perror("cd failed");
    }
}