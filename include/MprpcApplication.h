#pragma once

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
