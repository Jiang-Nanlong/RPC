#pragma once

#include "LogQueue.h"
#include <thread>
#include <stdio.h>
#include <iostream>
#include <fstream>


enum LogLevel {
    INFO, ERROR
};

class Logger {
private:
    LogQueue logqueue;
    int loglevel;

    Logger();
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
public:
    void SetLogLevel(int loglevel);

    void Log(const std::string& str);

    static Logger& getLoggerInstance();
};

#define LOG_INFO(str,...) \
do{\
Logger &logger=Logger::getLoggerInstance();\
logger.SetLogLevel(INFO);\
char c[1024]={0};\
snprintf(c,1024,str,##__VA_ARGS__);\
logger.Log(c);\
}while(0);\

#define LOG_ERROR(str,...) \
do{\
Logger& logger = Logger::getLoggerInstance();\
logger.SetLogLevel(ERROR);\
char c[1024] = { 0 };\
snprintf(c, 1024, str, ##__VA_ARGS__);\
logger.Log(c);\
} while (0);\

