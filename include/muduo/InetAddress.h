#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <strings.h>
#include <string.h>

using namespace std;

// 封装sockaddr_in
class InetAddress {
private:
    struct sockaddr_in addr_;
public:
    explicit InetAddress(string ip = "127.0.0.1", uint16_t port = 0);

    explicit InetAddress(const sockaddr_in& addr) : addr_(addr) {}

    ~InetAddress() = default;

    string getIp() const;

    uint16_t getPort() const;

    string getIpPort() const;

    const sockaddr_in* getSockAddr() const { return &addr_; }

    void setSockAddr(const sockaddr_in& addr) { addr_ = addr; }

};