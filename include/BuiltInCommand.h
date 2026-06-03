#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>

class BuiltInCommand {
public:
    virtual ~BuiltInCommand() = default;
    virtual std::string getName() const = 0;
    virtual void execute(const std::vector<std::string>& args) = 0;
};

class BuiltInCommandContainer {
public:
    static bool registerCommand(std::unique_ptr<BuiltInCommand> cmd);
    bool executeInternalCommand(const std::vector<std::string>& args);
    std::unique_ptr<BuiltInCommand>* findCommand(const std::string& name);

private:
    static std::map<std::string, std::unique_ptr<BuiltInCommand>>& getRegistry();
};