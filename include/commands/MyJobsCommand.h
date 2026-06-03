#pragma once
#include "../BuiltInCommand.h"

class MyJobsCommand : public BuiltInCommand {
public:
    std::string getName() const override { return "myjobs"; }
    void execute(const std::vector<std::string>& args) override;
};