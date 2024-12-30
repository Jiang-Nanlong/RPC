/// 创建一个rpcserver，允许callee在server上发布服务
/// 接收caller的调用请求，反序列化请求，找到caller想调用的函数，并调用本地函数，然后序列化结果发送回去
///
#pragma once

#include "../rpcheader.pb.h"
#include "../muduo/EventLoop.h"
#include "../muduo/InetAddress.h"
#include "../muduo/TcpServer.h"
#include "../MprpcApplication.h"
#include <google/protobuf/service.h>
#include <functional>
#include <google/protobuf/descriptor.h>
#include <string>
#include <unordered_map>
#include "../muduo/Connection.h"
#include "../muduo/Buffer.h"
#include <google/protobuf/stubs/callback.h>
#include "../zookeeperutil.h"

// protobuf实现数据序列化和反序列化，发布

class RpcProvider {
private:
public:
    void NotifyService(google::protobuf::Service* service);

    // 启动一个tcpserver
    void Run();

private:
    struct ServiceInfo
    {
        // 保存服务指针
        google::protobuf::Service* service;
        // methodMap保存服务中的函数名和函数指针
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> methodMap;
    };

    // 保存注册成功的服务名和对应服务的信息
    std::unordered_map<std::string, struct ServiceInfo> serviceMap;

    void onConnection(const ConnectionPtr& conn);

    void onMessage(const ConnectionPtr& conn, Buffer* buf);

    // Closure的回调操作，用于rpc调用结果的序列化和网络发送
    void sendRpcResponse(const ConnectionPtr& conn, google::protobuf::Message*);
};