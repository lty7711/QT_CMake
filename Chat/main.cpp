#include <QApplication>
#include <QIcon>
#include <QFile>

#include <iostream>

#include "mainwindow.h"
#include "singleton.h"
#include <string>
#include "http_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/styles/stylesheet.qss");
    if (qss.open(QFile::ReadOnly))
    {
        std::cout << "open success" << std::endl;
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else {
        std::cout << "Open failed" << std::endl;
    }
    // HttpManager::GetInstance();
    MainWindow w;
    w.setWindowTitle("IIfChat");
    w.setWindowIcon(QIcon(":/icons/icon.ico"));
    w.show();
    return a.exec();
}
