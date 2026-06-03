#pragma once
#include "../BuiltInCommand.h"

class MyHistoryCommand : public BuiltInCommand {
public:
    std::string getName() const override { return "myhistory"; }
    void execute(const std::vector<std::string>& args) override;
};