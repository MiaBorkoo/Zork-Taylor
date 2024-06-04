#include "mainWindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <algorithm>
#include <iostream>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), roomLabel(new QLabel(this)), descriptionLabel(new QLabel(this)), game(std::make_unique<GameNamespace::Game>()), mainLayout(new QVBoxLayout), taylorManager() {

    // Set the central widget
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set window size
    this->resize(800, 600);
    this->setFixedSize(800, 600);

    // Create a layout for the central widget
    mainLayout = new QVBoxLayout(centralWidget);

    // Set the room label properties
    roomLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    roomLabel->setFixedSize(800, 400);
    mainLayout->addWidget(roomLabel);

    // Set the description label properties
    descriptionLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(descriptionLabel);

    // Initialize albumNames correctly
    albumNames = QStringList{"Debut", "Fearless", "Speak Now", "Red", "1989", "Reputation"};
    buttonLayout = new QGridLayout();
    buttonLayout->setSpacing(10);

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

    // Create the start button
    startButton = new QPushButton("Start Game", this);
    startButton->setFixedSize(200, 50);
    startButton->hide();
    mainLayout->addWidget(startButton, 0, Qt::AlignCenter);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);

    // Create the back button
    backButton = new QPushButton("Back to collect", this);
    backButton->setFixedSize(200, 50);
    backButton->hide();
    mainLayout->addWidget(backButton, 0, Qt::AlignCenter);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goToRoom1);

    // Create the exit button
    exitButton = new QPushButton("Exit the Game", this);
    exitButton->setFixedSize(200, 50);
    exitButton->hide();
    mainLayout->addWidget(exitButton, 0, Qt::AlignCenter);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);

    std::cout << "Buttons created and connected" << std::endl;

    showIntroRoom();
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
    std::cout << "Button " << buttonId << " clicked" << std::endl;
    if (buttonId == 0 || buttonId == 5) {
        showRoom2();
    } else {
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
    std::cout << "Tour Button " << buttonId << " clicked" << std::endl;
    if (buttonId == 4) { // Assuming "Reputation" is at index 4
        std::cout << "Reputation tour selected, going to final room" << std::endl;
        QMessageBox::information(this, "Good choice", "WOHOO THIS IS THE BEST TOUR EVER! \n Congrats!");
        showFinalRoom();
    } else {
        std::cout << "Wrong tour selected, try again" << std::endl;
        QMessageBox::information(this, "Wrong Choice", "No, you failed. AGAIN!!");
    }
}

void MainWindow::goToRoom1() {
    showRoom1();
}

void MainWindow::exitGame() {
    QApplication::quit();
}
