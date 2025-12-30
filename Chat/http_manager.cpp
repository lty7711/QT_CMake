#include "http_manager.h"
#include <QJsonDocument>
#include <QByteArray>
#include <QNetworkReply>

HttpManager::HttpManager(){
    connect(this, &HttpManager::HttpFinishedSignal, this, &HttpManager::HttpFinishedSlot);
}

HttpManager::~HttpManager(){

}

void HttpManager::PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod){
    QByteArray data = QJsonDocument(json).toJson();         // 转换成 HTTP 请求能发送的字节数组（JSON 字符串的二进制形式）
    QNetworkRequest request(url);                           // 创建 Qt 网络请求对象，封装 HTTP 请求的基础信息
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");          // 告诉服务端，本次请求体是JSON格式
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));     // 设置请求体的长度
    auto self = shared_from_this();
    QNetworkReply *reply = __http_manager.post(request, data);                              // 非阻塞式
    connect(reply, &QNetworkReply::finished, [self, reply, req_id, mod](){
        if(reply->error() != QNetworkReply::NoError){       // 处理错误
            qDebug() << reply->errorString();
            // 发送信号
            emit self->HttpFinishedSignal(req_id, "", ErrorCodes::ERR_NETWORK, mod);
            reply->deleteLater();       // 释放reply指针
            return;
        }

        // 无错误
        QString res = reply->readAll();
        // 发送信号通知完成
        emit self->HttpFinishedSignal(req_id, res, ErrorCodes::SUCCESS, mod);
        reply->deleteLater();
        return;
    });
}

void HttpManager::HttpFinishedSlot(ReqId id, QString res, ErrorCodes err, Modules mod){
    if(mod == Modules::REGISTERMOD){
        // 发送信号信号通知指定模块http的相应结束了
        emit RegsModFinishedSignal(id, res, err);
    }
}