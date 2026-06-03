#pragma once
#include <vector>
#include <string>

struct ParsedCommand {
    std::vector<std::string> args;
    bool isBackground;
};

class Parser {
public:
    static ParsedCommand parse(const std::string& input);
};