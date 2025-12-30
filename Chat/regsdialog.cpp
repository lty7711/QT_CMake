#include "regsdialog.h"
#include "ui_regsdialog.h"
#include "http_manager.h"

#include <QLineEdit>
#include <QRegularExpression>

RegsDialog::RegsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegsDialog)
{
    ui->setupUi(this);
    // 输入的时候就看不见
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmLineEdit->setEchoMode(QLineEdit::Password);
    ui->err_tips->setText("");

    connect(ui->emaiLineEdit, &QLineEdit::textChanged, this, &RegsDialog::OnEmailTextChangedSlot);
    connect(ui->cancelBt, &QPushButton::clicked, this, [this](){ emit CancelRegsSignal();});
    connect(HttpManager::GetInstance().get(), &HttpManager::RegsModFinishedSignal, this, &RegsDialog::RegsFinishedSlot );

    // 注册回调函数
    RegsHttpHandlers();
}

RegsDialog::~RegsDialog()
{
    delete ui;
}

void RegsDialog::RegsHttpHandlers(){
    // 注册消息处理回调函数
    __handlerMap.insert(ReqId::ID_REG_USER, [this](const QJsonObject &jsonObj){
        int err = jsonObj["error"].toInt();
        if(err != ErrorCodes::SUCCESS){
            ui->err_tips->setText("参数错误");
            ui->err_tips->setStyleSheet("color: red;");
        }

        auto email = jsonObj["email"].toString();
        ui->err_tips->setText("验证码已发送到邮箱，注意查收。");
        ui->err_tips->setStyleSheet("color: green;");
        qDebug() << "email is " << email;
    });
}

void RegsDialog::OnEmailTextChangedSlot(){
    // lty8866@163.com
    QRegularExpression regex(R"(^[A-Za-z0-9]+@[A-Za-z0-9]+\.[A-Za-z]+$)");
    // 匹配账号匹配 或者 未输入
    if(ui->emaiLineEdit->text().isEmpty() || regex.match(ui->emaiLineEdit->text()).hasMatch()){
        ui->err_tips->setText("");
        ui->err_tips->setStyleSheet("");
    }
    else{   // 邮箱格式不匹配，提示输入错误
        ui->err_tips->setText("邮箱格式输入错误");
        ui->err_tips->setStyleSheet("color: red;");
    }
}

void RegsDialog::RegsFinishedSlot(ReqId id, QString res, ErrorCodes err){
    if(err != ErrorCodes::SUCCESS){
        ui->err_tips->setText("网络请求错误");
        ui->err_tips->setStyleSheet("color: red;");
    }

    // 解析JSON字符串能否被解析，语法层面
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        ui->err_tips->setText("Json解析错误");
        ui->err_tips->setStyleSheet("color: red;");
        return;
    }

    // 判断合法Json是什么类型 构层面（对象{} / 数组[] / 纯值）
    if(!jsonDoc.isObject()){
        ui->err_tips->setText("Json解析错误");
        ui->err_tips->setStyleSheet("color: red;");
        return;
    }

    // 转成json对象
    // jsonDoc.object();
    __handlerMap[id](jsonDoc.object());
    return;
}
