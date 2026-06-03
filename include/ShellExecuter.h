#pragma once
#include "BuiltInCommand.h"
#include "Parser.h"
#include "ExternalExecutor.h"
#include <string>

class ShellExecuter {
public:
    void run(const std::string& input);

private:
    BuiltInCommandContainer m_container;
};