#pragma once
#include "../BuiltInCommand.h"

class ExitCommand : public BuiltInCommand {
public:
    std::string getName() const override { return "exit"; }
    void execute(const std::vector<std::string>& args) override;
};