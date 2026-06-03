#include "../../include/commands/MyHistoryCommand.h"
#include "../../include/Model.h"
#include <iostream>
#include <fstream>

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<MyHistoryCommand>());

void MyHistoryCommand::execute(const std::vector<std::string>& args)
{
    std::ifstream file("history.txt");
    if (!file.is_open()) {
        std::cerr << "myhistory: could not open history file\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}