#include "Parser.h"
#include <sstream>
#include <cstdlib>

ParsedCommand Parser::parse(const std::string& input)
{
    ParsedCommand result;
    result.isBackground = false;

    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token[0] == '$') {
            const char* value = getenv(token.substr(1).c_str());
            if (value != nullptr) token = std::string(value);
        }
        result.args.push_back(token);
    }

    if (result.args.empty()) return result;

    if (result.args.back() == "&") {
        result.isBackground = true;
        result.args.pop_back();
    }

    return result;
}