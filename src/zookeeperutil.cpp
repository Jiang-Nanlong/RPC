#include "../include/zookeeperutil.h"
#include "zookeeperutil.h"
#include "../include/MprpcApplication.h"

void watcherFunc(zhandle_t* zh, int type,
    int state, const char* path, void* watcherCtx) {
    if (type == ZOO_SESSION_EVENT) {
        if (state == ZOO_CONNECTED_STATE) {
            sem_t* sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

ZKClient::ZKClient() :zh_(nullptr) {}

ZKClient::~ZKClient() {
    if (zh_)
        zookeeper_close(zh_);
}

void ZKClient::Start() {
    std::string zookeeper_ip = MprpcApplication::getInstance().getConfig().Load("zookeeper_ip");
    std::string zookeeper_port = MprpcApplication::getInstance().getConfig().Load("zookeeper_port");
    std::string ip_port = zookeeper_ip + ":" + zookeeper_port;

    zh_ = zookeeper_init(ip_port.c_str(), watcherFunc, 30000, nullptr, nullptr, 0);
    if (zh_ == nullptr) {
        std::cerr << "zookeeper_init_error" << std::endl;
        exit(1);
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(zh_, &sem);

    sem_wait(&sem);
    std::cout << "zookeeper init success" << std::endl;
}

void ZKClient::Create(const char* path, const char* data, int datalen, int state) {
    char buf[128];
    int len = sizeof(buf);
    int flag = zoo_exists(zh_, path, 0, nullptr);
    if (ZNONODE == flag) {
        flag = zoo_create(zh_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE, state, buf, len);
        if (flag == ZOK)
        {
            std::cout << "znode create success... path:" << path << std::endl;
        }
        else
        {
            std::cerr << "znode create error... path:" << path << std::endl;
            exit(1);
        }
    }
}

std::string ZKClient::Get(const char* path)
{
    char buf[64];
    int len = sizeof(buf);
    int flag = zoo_get(zh_, path, 0, buf, &len, nullptr);
    if (flag != ZOK)
    {
        std::cout << "get znode error... path:" << path << std::endl;
        return std::string();
    }
    else
    {
        return buf;
    }
}
