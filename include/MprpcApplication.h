//
// Created by cml on 24-12-26.
//

#ifndef MPRPCAPPLICATION_H
#define MPRPCAPPLICATION_H
#include "ReadConfig.h"
#include <unistd.h>

class MprpcApplication {
private:
    static ReadConfig readconfig;

public:
    static void Init(int argc, char** argv);

    static MprpcApplication& getInstance();

    static ReadConfig& getConfig();

private:
    MprpcApplication() {}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&&) = delete;
};

#endif //MPRPCAPPLICATION_H
