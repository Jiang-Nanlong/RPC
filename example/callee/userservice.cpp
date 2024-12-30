#include "../../include/user.pb.h"
#include "../../include/MprpcApplication.h"
#include "../../include/callee/RpcProvider.h"
#include "../../include/friend.pb.h"

#include <iostream>
#include <string>
#include <vector>


// 本地服务
class UserService : public fixbug::UserServiceRpc {
public:
    bool Login(std::string name, std::string pwd) {
        std::cout << "doing local service: login" << std::endl;
        std::cout << "name: " << name << "  pwd: " << pwd << std::endl;
        return true;
    }

    void Login(::google::protobuf::RpcController* controller,
        const ::fixbug::LoginRequest* request,
        ::fixbug::LoginResponse* response,
        ::google::protobuf::Closure* done) {
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool login_result = Login(name, pwd);

        // std::cout << "login_result: " << login_result << std::endl;

        fixbug::ResultCode* resultcode = response->mutable_result();
        resultcode->set_errcode(0);
        resultcode->set_errmsg("");
        response->set_success(login_result);

        // 执行回调操作，函数返回值序列化，然后网络发送给客户端（由框架来完成）
        done->Run();
    }

    bool Register(uint32_t id, const std::string& name, const std::string& pwd) {
        std::cout << "doing local service: register" << std::endl;
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "pwd: " << pwd << std::endl;
        return true;
    }

    void Register(::google::protobuf::RpcController* controller,
        const ::fixbug::RegisterRequest* request,
        ::fixbug::RegisterResponse* response,
        ::google::protobuf::Closure* done) {
        uint32_t id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool register_result = Register(id, name, pwd);

        fixbug::ResultCode* res = response->release_result();
        res->set_errcode(0);
        res->set_errmsg("");
        response->set_success(register_result);

        done->Run();
    }

    void Query(::google::protobuf::RpcController* controller,
        const ::fixbug::QueryRequest* request,
        ::fixbug::QueryResponse* response,
        ::google::protobuf::Closure* done) {
        uint32_t id = request->id();

        std::cout << "query id: " << id << std::endl;

        response->set_name("cml");

        done->Run();
    }
};

class FriendService :public fixbug::FriendServiceRpc {
public:
    std::vector<std::string> getfriendlist() {
        std::vector<std::string> res;
        res.push_back("abc");
        res.push_back("def");
        res.push_back("hij");
        return res;
    }

    void GetFriendList(::google::protobuf::RpcController* controller,
        const ::fixbug::FriendRequest* request,
        ::fixbug::FriendResponse* response,
        ::google::protobuf::Closure* done) {
        uint32_t id = request->id();
        std::cout << "id: " << id << std::endl;

        std::vector<std::string> res = getfriendlist();

        fixbug::ResultCode1* result_code = response->mutable_result();
        result_code->set_errcode(0);
        result_code->set_errmsg("");
        for (auto& str : res) {
            std::string* pstr = response->add_friends();
            *pstr = str;
        }

        done->Run();
    }
};

int main(int argc, char** argv) {
    MprpcApplication::Init(argc, argv);

    // 专门用来在框架上发布服务
    RpcProvider provider;
    provider.NotifyService(new UserService());
    provider.NotifyService(new FriendService());
    provider.Run();   // 启动了一个rpc server

    return 0;
}