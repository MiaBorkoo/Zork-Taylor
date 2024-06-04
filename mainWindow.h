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
#include "TaylorManager.h"
#include "Globals.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel* getRoomLabel() const { return roomLabel; }
    QLabel* getDescriptionLabel() const { return descriptionLabel; }
    QPushButton* getStartButton() const { return startButton; }
    QPushButton* getBackButton() const { return backButton; }
    QPushButton* getExitButton() const { return exitButton; }
    QVBoxLayout* getMainLayout() const { return mainLayout; }
    std::vector<QPushButton*>& getButtons() { return buttons; }
    std::vector<QLabel*>& getTextLabels() { return textLabels; }
    std::vector<QPushButton*>& getTourButtons() { return tourButtons; }

    public slots:
        void showIntroRoom();
        void showRoom1();
        void showRoom2();
        void showTourRoom();
        void showFinalRoom();
        void startGame();
        void goToRoom1();
        void exitGame();
        void handleButtonClick(int buttonId);
        void handleTourButtonClick(int buttonId);

private:
    QLabel *roomLabel;
    QLabel *descriptionLabel;
    std::vector<QPushButton*> buttons;
    std::vector<QLabel*> textLabels;
    std::vector<QPushButton*> tourButtons;
    QPushButton *backButton;
    QPushButton *exitButton;
    QPushButton *startButton;
    std::unique_ptr<GameNamespace::Game> game;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QGridLayout *buttonLayout;
    QStringList albumNames;
    TaylorManager taylorManager;
};

#endif // MAINWINDOW_H
