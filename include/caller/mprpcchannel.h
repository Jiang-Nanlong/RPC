#pragma once

#include "../rpcheader.pb.h"
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../MprpcApplication.h"
#include "mprpccontroller.h"
#include "../zookeeperutil.h"

// _stub::func(controller, request, response, done) => channel::callmethod(method, controller, request, response, done)
// caller在调用func之前会把参数写入到request中，并设置好response，
// 所以在callmethod中只需要设置好消息头，序列化消息头和参数列表，然后发送出去即可

// 消息头：header_size + service_name + method_name + args_size

// 后续可以在服务中多定义几个函数，看看对应的stub类中的每个函数的区别

class MprpcChannel :public google::protobuf::RpcChannel {
public:
    void CallMethod(const google::protobuf::MethodDescriptor* method,
        google::protobuf::RpcController* controller,
        const google::protobuf::Message* request,
        google::protobuf::Message* response,
        google::protobuf::Closure* done);
};

