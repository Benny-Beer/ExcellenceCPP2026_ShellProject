#include "ExternalExecutor.h"
#include "Model.h"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <filesystem>

namespace fs = std::filesystem;

std::string ExternalExecutor::findInPath(const std::string& command)
{
    // if full path given (e.g. /usr/bin/echo) check directly
    if (command[0] == '/') {
        if (fs::exists(command)) return command;
        return "";
    }

    // get PATH environment variable and split by :
    const char* pathEnv = getenv("PATH");
    if (pathEnv == nullptr) return "";

    std::istringstream iss(pathEnv);
    std::string dir;
    while (std::getline(iss, dir, ':')) {
        std::string fullPath = dir + "/" + command;
        if (fs::exists(fullPath)) return fullPath;
    }

    return "";
}

void ExternalExecutor::execute(const std::vector<std::string>& args, bool isBackground)
{
    std::string fullPath = findInPath(args[0]);
    if (fullPath.empty()) {
        std::cerr << args[0] << ": command not found\n";
        return;
    }

    // prepare C-style args for execv
    std::vector<char*> c_args;
    for (const auto& arg : args) {
        c_args.push_back(const_cast<char*>(arg.c_str()));
    }
    c_args.push_back(nullptr);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    }
    if (pid == 0) {
        // child process
        execv(fullPath.c_str(), c_args.data());
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    // parent process
    if (isBackground) {
        ShellModel::getInstance().addJob(pid, args[0]);
    } else {
        waitpid(pid, nullptr, 0);
    }
}