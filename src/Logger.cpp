#include "../include/Logger.h"

Logger::Logger() {
    std::thread writeLogTask([&]() {
        for (;;) {
            time_t now = time(nullptr);
            tm* nowtm = localtime(&now);
            char filename[128];
            sprintf(filename, "%d-%d-%d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);

            std::fstream file(filename, std::ios::out | std::ios::app);
            if (!file.is_open()) {
                std::cout << "log file: " << filename << "open error" << std::endl;
                exit(1);
            }
            std::string msg = logqueue.Pop();

            char time_buf[128] = { 0 };
            sprintf(time_buf, "%d:%d:%d ==> ", nowtm->tm_hour, nowtm->tm_min, nowtm->tm_sec);
            msg.insert(0, time_buf);
            msg.append("\n");

            file << msg;
            file.close();
        }
        });
    writeLogTask.detach();
}

void Logger::SetLogLevel(int level) {
    this->loglevel = level;
}

void Logger::Log(const std::string& str) {
    logqueue.Push(str);
}

Logger& Logger::getLoggerInstance() {
    static Logger log;
    return log;
}