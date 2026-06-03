#include "ShellExecuter.h"
#include <iostream>
#include <string>

int main()
{
    ShellExecuter shell;
    std::string line;

    while (true) {
        std::cout << "$ ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;
        shell.run(line);
    }
    return 0;
}