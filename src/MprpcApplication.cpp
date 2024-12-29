#include "../include/MprpcApplication.h"

ReadConfig MprpcApplication::readconfig;

void MprpcApplication::Init(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "format: command -i <configfile>" << std::endl;
        exit(1);
    }
    int c = 0;
    std::string filename;
    while ((c = getopt(argc, argv, "i:")) != -1) {
        switch (c) {
        case 'i':
            filename = optarg;
            break;
        case '?':
            std::cout << "invalid args" << std::endl;
            std::cout << "format: command -i configfile" << std::endl;
            exit(1);
        case ':':
            std::cout << "invalid args" << std::endl;
            std::cout << "format: command -i configfile" << std::endl;
            exit(1);
        default:
            break;
        }
    }
    readconfig.LoadConfigFile(filename.c_str());

    // 从配置文件读rpcserver_ip, rpcserver_port, zookeeper_ip, zookeeper_port
}

MprpcApplication& MprpcApplication::getInstance() {
    static MprpcApplication app;
    return app;
}

ReadConfig& MprpcApplication::getConfig() { return readconfig; }