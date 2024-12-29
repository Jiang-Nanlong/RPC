//
// Created by cml on 24-12-28.
//
#include "../include/LogQueue.h"

void LogQueue::Push(const std::string& str) {
    std::lock_guard<std::mutex> lock(mtx);
    logqueue.push(str);
    conditionVar_.notify_one();
}

std::string LogQueue::Pop() {
    std::unique_lock<std::mutex> lock(mtx);
    conditionVar_.wait(lock, [&]() { return !logqueue.empty(); });
    std::string str = logqueue.front();
    logqueue.pop();
    return str;
}

