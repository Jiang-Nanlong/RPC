//
// Created by cml on 24-12-26.
//
#include "../../include/callee/RpcProvider.h"


void RpcProvider::NotifyService(google::protobuf::Service* service) {
    ServiceInfo service_info;

    const google::protobuf::ServiceDescriptor* pserviceDesc = service->GetDescriptor();
    // 获取服务名称
    const std::string service_name = pserviceDesc->name();
    int method_num = pserviceDesc->method_count();
    for (int i = 0;i < method_num;i++) {
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        service_info.methodMap[method_name] = pmethodDesc;
    }
    service_info.service = service;
    serviceMap[service_name] = service_info;
}

void RpcProvider::Run() {
    std::string ip =
        MprpcApplication::getInstance().getConfig().Load("rpcserver_ip");

    uint16_t port = atoi(MprpcApplication::getInstance()
        .getConfig()
        .Load("rpcserver_port")
        .c_str());
    InetAddress addr(ip, port);
    EventLoop mainloop;
    TcpServer server(&mainloop, addr, "rpcserver");
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this, std::placeholders::_1, std::placeholders::_2));

    server.setThreadNum(1);

    server.start();
    mainloop.loop();
}

void RpcProvider::onConnection(const ConnectionPtr& conn) {
    if (!conn->isConnected()) {
        conn->shutdown();
    }
}

// 如果客户端有一个rpc服务的调用请求，那么onMessage函数就会调用
// 客户端发送过来的一个数据包包含：服务名，函数名和函数的参数列表。
// 为了区分这几个部分以及为了防止tcp数据包的粘包问题，加入一个消息头，即RpcHeader

void RpcProvider::onMessage(const ConnectionPtr& conn, Buffer* buf) {
    uint64_t len = buf->readAbleSize();
    // 客户端传递过来的rpc调用请求
    std::string str = buf->readAsStringAndPop(len);

    // 反序列化用户调用请求
    uint32_t header_size = 0;
    str.copy((char*)&header_size, 4, 0);  // 前四个字节表示数据头的长度，而且这里的长度应该是转成二进制以后再保存为字符串，而不是字面转成字符串
    std::string header_str = str.substr(4, header_size);  // 数据头部分

    rpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    // 数据头反序列化
    if (rpcHeader.ParseFromString(header_str)) {
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else {
        std::cout << "header_str deserialization failed" << std::endl;
        return;
    }

    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    // std::cout << "args_size: " << args_size << std::endl;

    std::string args_str = str.substr(4 + header_size, args_size);

    const auto it = serviceMap.find(service_name);
    if (it == serviceMap.end()) {
        std::cout << "can't find " << service_name << std::endl;
        return;
    }

    const auto it_method = it->second.methodMap.find(method_name);
    if (it_method == it->second.methodMap.end()) {
        std::cout << "can't find method " << method_name << std::endl;
        return;
    }

    // 服务的指针
    google::protobuf::Service* pservice = it->second.service;
    // 函数的指针
    const google::protobuf::MethodDescriptor* pmethodDesc = it_method->second;

    // 通过服务和函数，确定对应的函数参数列表
    google::protobuf::Message* request = pservice->GetRequestPrototype(pmethodDesc).New();
    // 反序列化参数列表
    if (!request->ParseFromString(args_str)) {
        std::cout << "request ParseFromString failed" << std::endl;
        return;
    }

    google::protobuf::Message* response = pservice->GetResponsePrototype(pmethodDesc).New();

    google::protobuf::Closure* done =
        google::protobuf::NewCallback<RpcProvider, const ConnectionPtr&, google::protobuf::Message*>(
            this,
            &RpcProvider::sendRpcResponse,
            conn,
            response
        );

    // 我知道了
    // 现在有三个类A,B,C,A是最开始的::google::protobuf::Service类，其中生命了纯虚函数callmethod，
    // 我们通过protobuf文件定义了服务，然后该服务生成类B继承自类A，并把服务中的函数都声明成虚函数，同时B类实现callmethod方法，根据参数调用服务中的函数
    // 而这些函数都没有实现功能，所以现在声明了类C继承自B，实现每个函数的功能。
    // 当把服务发布在rpcserver上时，其是serviceMap中保存的服务地址都是类C的地址，然后类C调用callmethod时调用对应服务中的函数，
    // 这个过程就发生了多态，因为用类C的指针去调用类B中的虚函数，然后就会调用到我们类C中覆盖的函数。
    pservice->CallMethod(pmethodDesc, nullptr, request, response, done);
}

void RpcProvider::sendRpcResponse(const ConnectionPtr& conn, google::protobuf::Message* response) {
    std::cout << "---sendRpcResponse---" << std::endl;

    std::string response_str;
    if (response->SerializeToString(&response_str)) {
        // 把结果序列化，并通过网络把结果发送到调用方
        conn->send(response_str);
    }
    else {
        std::cout << "serialize response_str error" << std::endl;
    }
    // conn->shutdown();   // rpc服务方主动断开连接
}