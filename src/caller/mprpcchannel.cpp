#include "../../include/caller/mprpcchannel.h"

void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
    google::protobuf::RpcController* controller,
    const google::protobuf::Message* request,
    google::protobuf::Message* response,
    google::protobuf::Closure* done) {

    const google::protobuf::ServiceDescriptor* serviceDesc = method->service();
    std::string service_name = serviceDesc->name();
    std::string method_name = method->name();

    uint32_t args_size = 0;
    std::string args_str;
    if (request->SerializeToString(&args_str)) {
        args_size = args_str.size();
    }
    else {
        controller->SetFailed("request serialize to string failed");
        return;
    }
    rpc::RpcHeader rpcheader;
    rpcheader.set_service_name(service_name);
    rpcheader.set_method_name(method_name);
    rpcheader.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string header_str;
    if (rpcheader.SerializeToString(&header_str)) {
        header_size = header_str.size();
    }
    else {
        controller->SetFailed("rpcheader serialize to string failed");
        return;
    }

    // header_size + header_str + args_str 构成完整的客户端发送数据包
    std::string send_str;
    send_str.insert(0, std::string((char*)&header_size, 4));
    send_str += header_str;
    send_str += args_str;

    // 简单的TCP编程，像rpcserver发送请求
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        char errbuf[100] = { 0 };
        sprintf(errbuf, "create socket failed, errno:%d", errno);
        controller->SetFailed(errbuf);
        return;
    }

    std::string ip =
        MprpcApplication::getInstance().getConfig().Load("rpcserver_ip");
    uint16_t port = atoi(MprpcApplication::getInstance()
        .getConfig()
        .Load("rpcserver_port")
        .c_str());

    struct sockaddr_in server_addr;
    memset((void*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        char errbuf[100] = { 0 };
        sprintf(errbuf, "client connect to server failed, errno:%d", errno);
        controller->SetFailed(errbuf);
        close(sockfd);
        return;
    }
    if (send(sockfd, (void*)send_str.c_str(), send_str.size(), 0) < 0) {
        char errbuf[100] = { 0 };
        sprintf(errbuf, "client send data failed, errno:%d", errno);
        controller->SetFailed(errbuf);
        close(sockfd);
        return;
    }

    char buf[1024];
    int recv_size = 0;
    memset((void*)buf, '\0', sizeof(buf));
    // 阻塞等待服务器返回调用结果
    if ((recv_size = recv(sockfd, (void*)buf, sizeof(buf), 0)) < 0) {
        char errbuf[100] = { 0 };
        sprintf(errbuf, "client recv data failed, errno:%d", errno);
        controller->SetFailed(errbuf);
        close(sockfd);
        return;
    }
    // std::cout << recv_size << std::endl;
    // for (int i = 0;i < recv_size;i++)
    //     std::cout << buf[i] << "  ";
    // std::string str;
    // str.append(buf, recv_size);
    // std::cout << str << std::endl;

    // 这里不能用ParseFromString，因为buf接收到的内容不确定，可能第一个字符就是'\0'，然后就导致string内容为空
    if (!response->ParseFromArray((void*)buf, recv_size)) {
        char errbuf[100] = { 0 };
        sprintf(errbuf, "response parse failed, errno:%d", errno);
        controller->SetFailed(errbuf);
        close(sockfd);
        return;
    }
    close(sockfd);
}