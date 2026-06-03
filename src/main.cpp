#include "BuiltInCommand.h"
#include "commands/CdCommand.h"
#include "commands/ExitCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
    BuiltInCommandContainer container;
    std::string line;

    while (true) {
        std::cout << "$ ";
        if (!std::getline(std::cin, line)) break;
        // split into args
        std::vector<std::string> args;
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) args.push_back(token);
        if (args.empty()) continue;
        if (!container.executeInternalCommand(args))
            std::cout << "unknown command\n";
    }
    return 0;
}