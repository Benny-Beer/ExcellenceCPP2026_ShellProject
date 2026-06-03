#pragma once
#include "../BuiltInCommand.h"

class CdCommand : public BuiltInCommand {
public:
    std::string getName() const override { return "cd"; }
    void execute(const std::vector<std::string>& args) override;
};