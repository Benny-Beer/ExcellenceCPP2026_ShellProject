#include "../../include/commands/CdCommand.h"
#include <iostream>
#include <unistd.h>

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<CdCommand>());

void CdCommand::execute(const std::vector<std::string>& args)
{
    std::string path;

    if (args.size() < 2) {
        // no argument - go to $HOME
        const char* home = getenv("HOME");
        if (home == nullptr) {
            std::cerr << "cd: HOME not set\n";
            return;
        }
        path = std::string(home);
    } else {
        path = args[1];
    }

    if (chdir(path.c_str()) != 0) {
        perror("cd failed");
    }
}