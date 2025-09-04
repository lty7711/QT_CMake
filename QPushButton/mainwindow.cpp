#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QString>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bt, &QPushButton::clicked, this, &MainWindow::ButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ButtonClicked() {
    QString str = "Hello Qt";
    std::cout << str.toStdString() << std::endl;
    std::cout << "Button is Clicked !!!" << std::endl;
}
