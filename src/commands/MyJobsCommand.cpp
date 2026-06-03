#include "../../include/commands/MyJobsCommand.h"
#include "../../include/Model.h"
#include <iostream>
#include <sys/wait.h>

static bool registered = BuiltInCommandContainer::registerCommand(
    std::make_unique<MyJobsCommand>());

void MyJobsCommand::execute(const std::vector<std::string>& args)
{
    ShellModel& model = ShellModel::getInstance();
    const std::vector<BackgroundJob>& jobs = model.getJobs();

    for (int i = 0; i < jobs.size(); i++) {
        if (waitpid(jobs[i].pid, nullptr, WNOHANG) > 0) {
            model.updateJob(i);
            std::cout << "[" << jobs[i].pid << "] " << jobs[i].command << " DONE\n";
        } else {
            std::cout << "[" << jobs[i].pid << "] " << jobs[i].command << " RUNNING\n";
        }
    }

    model.removeDoneJobs();
}