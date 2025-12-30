#pragma once


#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>

#include "global.h"
#include "singleton.h"

// CRTP
class HttpManager: public QObject, public Singleton<HttpManager>, public std::enable_shared_from_this<HttpManager>
{
    Q_OBJECT
    friend class Singleton<HttpManager>;

public:
    ~HttpManager();

private:
    HttpManager();
    QNetworkAccessManager __http_manager;
    void PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod);  // 发送post请求

private slots:
    void HttpFinishedSlot(ReqId id, QString res, ErrorCodes err, Modules mod);  // 处理http请求结果

signals:
    void HttpFinishedSignal(ReqId id, QString res, ErrorCodes err, Modules mod);  // Http请求发送结束信号
    void RegsModFinishedSignal(ReqId id, QString res, ErrorCodes err);
};

