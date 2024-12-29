//
// Created by cml on 24-12-26.
//
#include "../include/ReadConfig.h"

void ReadConfig::LoadConfigFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "can't open configfile" << std::endl;
        exit(1);
    }
    std::string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == ';')
            continue;

        auto pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            value.erase(remove(value.begin(), value.end(), ' '), value.end());
            configMap[key] = value;
        }
    }

    for (auto& it : configMap) {
        std::cout << it.first << " : " << it.second << std::endl;
    }
    file.close();
}

std::string ReadConfig::Load(const std::string key) {
    auto it = configMap.find(key);
    if (it != configMap.end())
        return it->second;
    return std::string();
}