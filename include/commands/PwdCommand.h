#pragma once
#include "../BuiltInCommand.h"

class PwdCommand : public BuiltInCommand {
public:
    std::string getName() const override { return "pwd"; }
    void execute(const std::vector<std::string>& args) override;
};