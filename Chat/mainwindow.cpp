#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __m_widget_buf = new QStackedWidget(this);
    __m_login_dlg = new LoginDialog();
    __m_regs_dlg = new RegsDialog();

    __m_widget_buf->addWidget(__m_login_dlg);
    __m_widget_buf->addWidget(__m_regs_dlg);

    setCentralWidget(__m_widget_buf);

    __m_widget_buf->setCurrentWidget(__m_login_dlg);

    connect(__m_login_dlg, &LoginDialog::SwitchRegsDlgSignal, this, [=](){__m_widget_buf->setCurrentWidget(__m_regs_dlg);});
    connect(__m_regs_dlg, &RegsDialog::CancelRegsSignal, this, [=](){__m_widget_buf->setCurrentWidget(__m_login_dlg);});

    // 防止在生成两个窗口
    // __m_login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    // __m_regs_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}
