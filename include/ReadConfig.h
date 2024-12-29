//
// Created by cml on 24-12-26.
//

#ifndef READCONFIG_H
#define READCONFIG_H
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class ReadConfig {
private:
    std::unordered_map<std::string, std::string> configMap;

public:
    void LoadConfigFile(const char* filename);

    std::string Load(const std::string key);
};
#endif //READCONFIG_H
