#include "mainWindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <algorithm>
#include <iostream>
#include <QApplication>

//future feature implementation in the constructor with players and their score
// MainWindow::MainWindow(const std::string& playerName, int initialScore, QWidget *parent)
//     : QMainWindow(parent), roomLabel(new QLabel(this)), descriptionLabel(new QLabel(this)), game(std::make_unique<GameNamespace::Game>()), mainLayout(new QVBoxLayout), taylorManager()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), roomLabel(new QLabel(this)), descriptionLabel(new QLabel(this)), game(std::make_unique<GameNamespace::Game>()), mainLayout(new QVBoxLayout), taylorManager() {

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    this->resize(800, 600);
    this->setFixedSize(800, 600); //Fixed size for every room

    mainLayout = new QVBoxLayout(centralWidget);

    // Set the room label properties
    roomLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    roomLabel->setFixedSize(800, 400);
    mainLayout->addWidget(roomLabel);

    descriptionLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(descriptionLabel);

    albumNames = QStringList{"Debut", "Fearless", "Speak Now", "Red", "1989", "Reputation"}; //Use of arrays for album names
    buttonLayout = new QGridLayout();
    buttonLayout->setSpacing(10);
    //
    for (int i = 0; i < albumNames.size(); ++i) {
        QLabel* albumLabel = new QLabel(this);
        albumLabel->setScaledContents(true);
        albumLabel->setFixedSize(130, 130);
        buttonLayout->addWidget(albumLabel, 0, i, Qt::AlignCenter);

        QPushButton* button = new QPushButton(albumNames[i], this);
        buttons.push_back(button);
        button->setFixedSize(130, 30);
        buttonLayout->addWidget(button, 1, i, Qt::AlignCenter);
        connect(button, &QPushButton::clicked, [this, i]() { handleButtonClick(i); });

        QLabel* textLabel = new QLabel(this);
        textLabels.push_back(textLabel);
        buttonLayout->addWidget(textLabel, 2, i, Qt::AlignCenter);
    }
    mainLayout->addLayout(buttonLayout);

    // The start button
    startButton = new QPushButton("Start Game", this);
    startButton->setFixedSize(200, 50);
    startButton->hide();
    mainLayout->addWidget(startButton, 0, Qt::AlignCenter);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);

    //The back button
    backButton = new QPushButton("Back to collect", this);
    backButton->setFixedSize(200, 50);
    backButton->hide();
    mainLayout->addWidget(backButton, 0, Qt::AlignCenter);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goToRoom1);

    //The exit button
    exitButton = new QPushButton("Exit the Game", this);
    exitButton->setFixedSize(200, 50);
    exitButton->hide();
    mainLayout->addWidget(exitButton, 0, Qt::AlignCenter);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);



    showIntroRoom();  //intro room with start button
}

MainWindow::~MainWindow() {
    // Clean up any resources if necessary
}

void MainWindow::showIntroRoom() {
    taylorManager.showIntroRoom(this);
}

void MainWindow::startGame() {
    taylorManager.startGame(this);
}

void MainWindow::showRoom1() {
    taylorManager.showRoom1(this);
}

void MainWindow::showRoom2() {
    taylorManager.showRoom2(this);
}

void MainWindow::showTourRoom() {
    taylorManager.showTourRoom(this);
}

void MainWindow::showFinalRoom() {
    taylorManager.showFinalRoom(this);
}


void MainWindow::handleButtonClick(int buttonId) {
    if (buttonId == 0 || buttonId == 5) { //If Debut or Reputation is clicked, show room2 (not taylor's version)
        showRoom2();
    } else { //If its any other button, show a specific Taylor's version room
        switch (buttonId) {
            case 1:
                taylorManager.showSpecificRoom(this, "Fearless", "Fearless.png");
                break;
            case 2:
                taylorManager.showSpecificRoom(this, "Speak Now", "Speak Now.png");
                break;
            case 3:
                taylorManager.showSpecificRoom(this, "Red", "Red.png");
                break;
            case 4:
                taylorManager.showSpecificRoom(this, "1989", "1989.png");
                break;
            default:
                break;
        }
    }
}


void MainWindow::handleTourButtonClick(int buttonId) {
    if (buttonId == 4) { //If you click reputation, you're taken to the final room
        QMessageBox::information(this, "Good choice", "WOHOO THIS IS THE BEST TOUR EVER! \n Congrats!");
        showFinalRoom();
    } else { //any other button click, you're at the same page and try again

        QMessageBox::information(this, "Wrong Choice", "No, you failed. AGAIN!!");
    }
}

void MainWindow::goToRoom1() {
    showRoom1();
}

void MainWindow::exitGame() {
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit Game", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
