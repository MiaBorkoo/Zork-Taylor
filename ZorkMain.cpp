//
// Created by mia borko on 14/05/2024.
//
#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}