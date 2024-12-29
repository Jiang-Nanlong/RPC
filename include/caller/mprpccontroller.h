#pragma once

#include <google/protobuf/service.h>
#include <google/protobuf/stubs/callback.h>
#include <string>

// 调用方使用，保存rpc方法调用失败的错误信息

class MprpcController :public google::protobuf::RpcController {
private:
    // 是否失败
    bool isFailed;
    // 失败后的错误信息
    std::string errText;
public:
    MprpcController();

    void Reset() override;

    bool Failed() const override;

    std::string ErrorText() const override;

    void SetFailed(const std::string& reason) override;

    void StartCancel() override;

    bool IsCanceled() const override;

    void NotifyOnCancel(google::protobuf::Closure* callback);
};