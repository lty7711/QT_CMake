#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "regsdialog.h"
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void SlotSwitchReg();
    // void SlotRegsCancel();

private:
    Ui::MainWindow *ui;
    LoginDialog *__m_login_dlg;             // 登录界面
    RegsDialog* __m_regs_dlg;               // 注册界面
    QStackedWidget *__m_widget_buf;         // 所有界面指针存储在改buf中，用于实现多界面切换   

};
#endif // MAINWINDOW_H
