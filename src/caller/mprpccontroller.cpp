//
// Created by cml on 24-12-26.
//
#include "../../include/caller/mprpccontroller.h"

MprpcController::MprpcController() {
    isFailed = false;
    errText = "";
}

void MprpcController::Reset() {
    isFailed = false;
    errText = "";
}

bool MprpcController::Failed() const {

    return isFailed;
}

std::string MprpcController::ErrorText() const
{
    return errText;
}

void MprpcController::SetFailed(const std::string& reason) {
    isFailed = true;
    errText = reason;
}

void MprpcController::StartCancel() { return; }

bool MprpcController::IsCanceled() const { return false; }

void MprpcController::NotifyOnCancel(google::protobuf::Closure* callback) { return; }
