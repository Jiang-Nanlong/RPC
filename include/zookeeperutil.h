#pragma once

#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>
#include <iostream>

class ZKClient {
public:
    ZKClient();

    ~ZKClient();

    void Start();

    void Create(const char* path, const char* data, int datalen, int state = 0);

    std::string Get(const char* path);

private:
    zhandle_t* zh_;
};