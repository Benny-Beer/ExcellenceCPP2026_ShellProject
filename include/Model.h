#pragma once
#include <vector>
#include <string>
#include <sys/types.h>
#include <algorithm>

const std::string HISTORY_FILE_PATH = "history.txt";
struct BackgroundJob {
    pid_t pid;
    std::string command;
    bool isDone;
};

class ShellModel {
public:
    static ShellModel& getInstance() {
        static ShellModel instance;
        return instance;
    }

    // delete copy constructor and assignment operator
    ShellModel(const ShellModel&) = delete;
    ShellModel& operator=(const ShellModel&) = delete;

    void addToHistory(const std::string& command);
    void addJob(pid_t pid, const std::string& command);
    void updateJob(int index);
    void removeDoneJobs();
    const std::vector<BackgroundJob>& getJobs() const;

private:
    ShellModel() : m_historyFilePath(HISTORY_FILE_PATH) {}

    std::string m_historyFilePath;
    std::vector<BackgroundJob> m_jobs;
};