#include "regsdialog.h"
#include "ui_regsdialog.h"
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
    connect(ui->emaiLineEdit, &QLineEdit::textChanged, this, &RegsDialog::OnEmailTextChanged);
}

RegsDialog::~RegsDialog()
{
    delete ui;
}

void RegsDialog::OnEmailTextChanged(){
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
