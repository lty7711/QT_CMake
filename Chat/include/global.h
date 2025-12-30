#pragma once

#include <iostream>
#include <memory>

#include <QWidget>
#include <QDebug>


enum ReqId{                             // 请求类型
    ID_GET_VARIFY_CODE = 1001,          // 获取验证码
    ID_REG_USER = 1002,                 // 注册用户
};

enum Modules{
    REGISTERMOD = 0,                    // 注册模块
};

enum ErrorCodes{
    SUCCESS = 0,                        // 成功
    ERR_JSON = 1,                       // JSON解析错误
    ERR_NETWORK = 2,                    // 网络错误
};

