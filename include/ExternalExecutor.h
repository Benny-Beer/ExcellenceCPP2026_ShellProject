#pragma once
#include <vector>
#include <string>

class ExternalExecutor {
public:
    static void execute(const std::vector<std::string>& args, bool isBackground);

private:
    static std::string findInPath(const std::string& command);
};