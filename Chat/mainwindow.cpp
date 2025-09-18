#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  
    __m_login_dlg = new LoginDialog(this);  // 初始化登录页面，代码这里加上this会出问题，无法显示
    connect(__m_login_dlg, &LoginDialog::SwitchRegsDlg, this, &MainWindow::SlotSwitchReg);
    __m_regs_dlg = new RegsDialog(this);
    
    // 当一个页面设置为CentralWidget后，当程序退出时，会自动删除CentralWidget中的类
    setCentralWidget(__m_login_dlg);  // 这里默认会设置__login_dlg的父类对象

    // 防止在生成两个窗口
    __m_login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    __m_regs_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg() {
    setCentralWidget(__m_regs_dlg);
    __m_login_dlg->hide();
    __m_regs_dlg->show();
}
