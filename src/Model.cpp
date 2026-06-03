#include "Model.h"
#include <fstream>


void ShellModel::addToHistory(const std::string& command)
{
    std::ofstream file(m_historyFilePath, std::ios::app);
    file << command << "\n";
}

void ShellModel::addJob(pid_t pid, const std::string& command)
{
    m_jobs.push_back({pid, command, false});
}

void ShellModel::updateJob(int index)
{
    m_jobs[index].isDone = true;
}

void ShellModel::removeDoneJobs()
{
    m_jobs.erase(
        std::remove_if(m_jobs.begin(), m_jobs.end(),
            [](const BackgroundJob& job) { return job.isDone; }),
        m_jobs.end()
    );
}

const std::vector<BackgroundJob>& ShellModel::getJobs() const
{
    return m_jobs;
}