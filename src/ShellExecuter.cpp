#include "ShellExecuter.h"
#include "Model.h"
#include <iostream>

void ShellExecuter::run(const std::string& input)
{
    // add to history
    ShellModel::getInstance().addToHistory(input);

    // parse input
    ParsedCommand parsed = Parser::parse(input);

    if (parsed.args.empty()) return;

    // try built-in first
    if (m_container.executeInternalCommand(parsed.args)) return;

    // not built-in - run externally
    ExternalExecutor::execute(parsed.args, parsed.isBackground);
}