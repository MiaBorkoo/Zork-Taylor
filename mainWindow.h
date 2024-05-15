//
// Created by mia borko on 14/05/2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Room.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

