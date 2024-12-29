#pragma once

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

class LogQueue
{
private:
    std::queue<std::string> logqueue;
    std::mutex mtx;
    std::condition_variable conditionVar_;
public:
    LogQueue() = default;

    void Push(const std::string& str);

    std::string Pop();
};
