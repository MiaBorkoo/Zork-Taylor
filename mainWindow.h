#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <memory>
#include <set>
#include "Game.h"
#include "Room.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
        void showIntroRoom();
    void showRoom1();
    void showRoom2();
    void showTourRoom();
    void showFinalRoom();
    void showRoom(const Room& room);
    void createTourLayout();
    void showSpecificRoom(const QString& albumName, const QString& newAlbumImagePath);
    void handleButtonClick(int buttonId);
    void handleTourButtonClick(int buttonId);
    void goToRoom1();
    void exitGame();
    void startGame();  // In the intro room

private:
    QLabel *roomLabel;
    QLabel *descriptionLabel;
    std::vector<QPushButton*> buttons;
    std::vector<QLabel*> textLabels;
    std::vector<QPushButton*> tourButtons;
    QPushButton *backButton;
    QPushButton *exitButton;
    QPushButton *startButton;  // Start button for the intro room
    std::unique_ptr<GameNamespace::Game> game;
    std::set<QString> collectedAlbums;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QGridLayout *buttonLayout;
    QStringList albumNames;  // Member variable for album names
};

#endif // MAINWINDOW_H
