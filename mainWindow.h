#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <memory>
#include "Game.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void showRoom1();
    void showRoom2();
    void showRoom3();
    void handleButtonClick(int buttonId);

    QLabel *roomLabel;
    std::vector<QPushButton*> buttons;
    std::unique_ptr<GameNamespace::Game> game;
};

#endif // MAINWINDOW_H
