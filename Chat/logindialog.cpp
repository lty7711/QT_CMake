#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPushButton>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->regsBt, &QPushButton::clicked, this, [this](){emit SwitchRegsDlgSignal();});
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
