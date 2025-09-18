#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "regsdialog.h"

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
    void SlotSwitchReg();

private:
    Ui::MainWindow *ui;
    LoginDialog *__m_login_dlg;
    RegsDialog* __m_regs_dlg;

};
#endif // MAINWINDOW_H
