#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  
    __m_login_dlg = new LoginDialog(this);  // ��ʼ����¼ҳ�棬�����������this������⣬�޷���ʾ
    connect(__m_login_dlg, &LoginDialog::SwitchRegsDlg, this, &MainWindow::SlotSwitchReg);
    __m_regs_dlg = new RegsDialog(this);
    
    // ��һ��ҳ������ΪCentralWidget�󣬵������˳�ʱ�����Զ�ɾ��CentralWidget�е���
    setCentralWidget(__m_login_dlg);  // ����Ĭ�ϻ�����__login_dlg�ĸ������

    // ��ֹ��������������
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
