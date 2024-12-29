//
// Created by cml on 24-12-26.
//
#include "../../include/user.pb.h"
#include "../../include/MprpcApplication.h"
#include "../../include/caller/mprpcchannel.h"
#include "../../include/caller/mprpccontroller.h"

int main(int argc, char** argv) {
    MprpcApplication::Init(argc, argv);

    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    fixbug::LoginRequest request;
    request.set_name("abc");
    request.set_pwd("123");

    fixbug::LoginResponse response;
    MprpcController controller;
    // 同步rpc调用
    stub.Login(&controller, &request, &response, nullptr);
    if (controller.Failed()) {
        std::cout << controller.ErrorText() << std::endl;
    }
    else {
        if (response.result().errcode() == 0) {
            std::cout << std::boolalpha << "rpc login response: " << response.success() << std::noboolalpha << std::endl;
        }
        else {
            std::cout << "rpc response error: " << response.result().errcode() << std::endl;
        }
    }


    fixbug::RegisterRequest register_request;
    register_request.set_id(1);
    register_request.set_name("cml");
    register_request.set_pwd("111");

    MprpcController controller1;
    fixbug::RegisterResponse register_response;
    stub.Register(&controller1, &register_request, &register_response, nullptr);
    if (controller1.Failed()) {
        std::cout << controller1.ErrorText() << std::endl;
    }
    else {
        if (register_response.result().errcode() == 0) {
            std::cout << std::boolalpha << "rpc register response: " << register_response.success() << std::noboolalpha << std::endl;
        }
        else {
            std::cout << "rpc register error: " << register_response.result().errcode() << std::endl;
        }
    }


    fixbug::QueryRequest query_request;
    query_request.set_id(1);

    MprpcController controller2;
    fixbug::QueryResponse query_response;
    stub.Query(&controller2, &query_request, &query_response, nullptr);
    if (controller2.Failed()) {
        std::cout << controller1.ErrorText() << std::endl;
    }
    else {
        std::cout << query_response.name() << std::endl;
    }
    return 0;
}