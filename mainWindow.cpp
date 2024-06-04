#include "mainWindow.h"
#include "Room1.h"
#include "Room2.h"
#include "TourRoom.h"
#include "FinalRoom.h"

#include "Game.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <algorithm>
#include <iostream>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), roomLabel(new QLabel(this)), descriptionLabel(new QLabel(this)), game(std::make_unique<GameNamespace::Game>()), mainLayout(new QVBoxLayout) {

    // Set the central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set window size
    this->resize(800, 600);  // Optionally, if you want to set initial size
    this->setFixedSize(800, 600);  // Fix the window size to 800x600

    // Create a layout for the central widget
    mainLayout = new QVBoxLayout(centralWidget);

    // Set the room label properties
    roomLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    roomLabel->setFixedSize(800, 400);
    mainLayout->addWidget(roomLabel);

    // Set the description label properties
    descriptionLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(descriptionLabel);

    // Create the grid layout for buttons and album labels
    QStringList albumNames = {"Debut", "Fearless", "Speak Now", "Red", "1989", "Reputation"};
    QGridLayout *buttonLayout = new QGridLayout();
    buttonLayout->setSpacing(10); // Set spacing between buttons

    for (int i = 0; i < albumNames.size(); ++i) {
        QLabel* albumLabel = new QLabel(this);
        albumLabel->setPixmap(QPixmap("zork-pics/" + albumNames[i] + ".png"));
        albumLabel->setScaledContents(true);
        albumLabel->setFixedSize(130, 130); // Adjust size as needed
        buttonLayout->addWidget(albumLabel, 0, i, Qt::AlignCenter);

        QPushButton* button = new QPushButton(albumNames[i], this);
        buttons.push_back(button);
        button->setFixedSize(130, 30); // Set button size
        buttonLayout->addWidget(button, 1, i, Qt::AlignCenter); // Position buttons in a grid layout
        connect(button, &QPushButton::clicked, [this, i]() { handleButtonClick(i); });

        QLabel* textLabel = new QLabel(this);
        textLabels.push_back(textLabel);
        buttonLayout->addWidget(textLabel, 2, i, Qt::AlignCenter);
    }
    mainLayout->addLayout(buttonLayout);

    // Create the start button
    startButton = new QPushButton("Start Game", this);
    startButton->setFixedSize(200, 50);
    startButton->hide(); // Initially hidden
    mainLayout->addWidget(startButton, 0, Qt::AlignCenter);
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);

    // Create the back button
    backButton = new QPushButton("Back to collect", this);
    backButton->setFixedSize(200, 50);
    backButton->hide(); // Initially hidden
    mainLayout->addWidget(backButton, 0, Qt::AlignCenter);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goToRoom1);

    // Create the exit button
    exitButton = new QPushButton("Exit the Game", this);
    exitButton->setFixedSize(200, 50);
    exitButton->hide(); // Initially hidden
    mainLayout->addWidget(exitButton, 0, Qt::AlignCenter);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);

    std::cout << "Buttons created and connected" << std::endl;

    showIntroRoom();
}

MainWindow::~MainWindow() {
    // Clean up unique_ptr
}

void MainWindow::showIntroRoom() {
    std::cout << "Showing Intro Room" << std::endl;
    QString imagePath = "zork-pics/tayFirst.png";

    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
        QMessageBox::critical(this, "Error", "Failed to load image: " + imagePath);
        return;
    }

    roomLabel->setPixmap(pixmap);
    roomLabel->setScaledContents(true);

    descriptionLabel->setText("Welcome to the Taylor Swift Game! Collect all Taylor's Version albums to win. \n Description: You'll be given 6 album options, you have to collect 4 of them in Room 1. \n Once you do that, you'll be taken to another room where you have to choose the best tour. There is only 1 correct answer. \n Click 'Start Game' to begin.");

    startButton->show();
    backButton->hide();
    exitButton->hide();

    for (QPushButton *button : buttons) {
        button->hide();
    }
    for (QLabel *textLabel : textLabels) {
        textLabel->clear();
    }
    QHBoxLayout *descriptionLayout = new QHBoxLayout();
    descriptionLayout->addStretch();
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addStretch();

    // Add the description layout to the main layout
    mainLayout->addLayout(descriptionLayout);
}

void MainWindow::startGame() {
    showRoom1();
}

void MainWindow::showRoom1() {
    Room1 room1;
    showRoom(room1);


    descriptionLabel->setText("These are Taylor's albums that were sold to a third party in 2019. \n She doesn't own any of these inspite of writing every single song on them. Thats why iconic Tay Tay decided to rerecord the albums. \n She rerecorded 4 out of 6 on this list. Find them. Good luck.");
}

void MainWindow::showRoom2() {
    Room2 room2;
    showRoom(room2);
}

void MainWindow::showTourRoom() {
    TourRoom roomTour;
    showRoom(roomTour);
}

void MainWindow::showFinalRoom() {
    FinalRoom roomFinal;
    showRoom(roomFinal);
}

void MainWindow::showRoom(const Room& room) {
    QString imagePath = "zork-pics/" + room.getRoomImage();

    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
        QMessageBox::critical(this, "Error", "Failed to load image: " + imagePath);
        return;
    }

    roomLabel->setPixmap(pixmap);
    roomLabel->setScaledContents(true);

    descriptionLabel->setText(room.getDescription());

    if (dynamic_cast<const TourRoom*>(&room)) {
        createTourLayout();
    } else {
        for (QPushButton *button : buttons) {
            button->show();
        }
        for (QLabel *textLabel : textLabels) {
            textLabel->clear();
        }
        backButton->hide();
        exitButton->hide();
        startButton->hide();
    }

    if (dynamic_cast<const FinalRoom*>(&room)) {
        for (QPushButton *button : buttons) {
            button->hide();
        }
        for (QLabel *textLabel : textLabels) {
            textLabel->clear();
        }
        descriptionLabel->setText("Congratulations! You have completed the Taylor Swift Game.");
        backButton->hide();
        startButton->hide();
        for (QPushButton *button : tourButtons) {
            button->hide();
        }
        exitButton->show();
    }
}

void MainWindow::createTourLayout() {
    QStringList tourNames = {"Fearless", "Speak Now", "Red", "1989", "Reputation", "Eras"};
    QGridLayout *tourLayout = new QGridLayout();
    tourLayout->setSpacing(10); // Set spacing between buttons

    for (int i = 0; i < tourNames.size(); ++i) {
        QPushButton* button = new QPushButton(tourNames[i], this);
        tourButtons.push_back(button);
        button->setFixedSize(130, 30); // Set button size
        tourLayout->addWidget(button, 0, i, Qt::AlignCenter); // Position buttons in a grid layout
        connect(button, &QPushButton::clicked, [this, i]() { handleTourButtonClick(i); });
    }
    for (QPushButton *button : buttons) {
        button->hide();
    }
    for (QLabel *textLabel : textLabels) {
        textLabel->clear();
    }
    backButton->hide();
    exitButton->hide();
    startButton->hide();

    mainLayout->addLayout(tourLayout); // Add the tour layout to the main layout
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

void MainWindow::showSpecificRoom(const QString& albumName, const QString& newAlbumImagePath) {
    std::cout << "Showing specific room for " << albumName.toStdString() << std::endl;

    collectedAlbums.insert(albumName); // Add the album to the collected set

    QPixmap pixmap(newAlbumImagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << newAlbumImagePath.toStdString() << std::endl;
        QMessageBox::critical(this, "Error", "Failed to load image: " + newAlbumImagePath);
        return;
    }

    roomLabel->setPixmap(pixmap);
    roomLabel->setScaledContents(true);

    for (QPushButton *button : buttons) {
        button->hide();
    }
    for (QLabel *textLabel : textLabels) {
        textLabel->clear(); // Clear the text labels
    }

    if (albumName == "Fearless") {
        descriptionLabel->setText("You have entered the room for Fearless. Taylor's Version is here.");
    } else if (albumName == "Speak Now") {
        descriptionLabel->setText("You have entered the room for Speak Now. Taylor's Version is here.");
    } else if (albumName == "Red") {
        descriptionLabel->setText("You have entered the room for Red. Taylor's Version is here.");
    } else if (albumName == "1989") {
        descriptionLabel->setText("You have entered the room for 1989. Taylor's Version is here.");
    }

    backButton->show();  // Show the back button in specific rooms
    exitButton->hide();  // Hide the exit button in specific rooms

    // Define the required albums
    std::set<QString> requiredAlbums = {"Fearless", "Speak Now", "Red", "1989"};

    // Check if the collected albums match the required set
    if (collectedAlbums.size() >= requiredAlbums.size() && std::includes(collectedAlbums.begin(), collectedAlbums.end(), requiredAlbums.begin(), requiredAlbums.end())) {
        QMessageBox::information(this, "Congratulations", "All Taylor's Version albums collected!\n The world has been blessed to have them");
        collectedAlbums.clear(); // Clear the collected albums set
        showTourRoom();  // Transition to the tour room
    }
}

void MainWindow::handleButtonClick(int buttonId) {
    std::cout << "Button " << buttonId << " clicked" << std::endl;
    if (buttonId == 0 || buttonId == 5) {
        showRoom2();
    } else {
        switch (buttonId) {
            case 1:
                showSpecificRoom("Fearless", "zork-pics/Fearless1.png");
                break;
            case 2:
                showSpecificRoom("Speak Now", "zork-pics/speakNowNew.png");
                break;
            case 3:
                showSpecificRoom("Red", "zork-pics/Red1.png");
                break;
            case 4:
                showSpecificRoom("1989", "zork-pics/1989new.png");
                break;
            default:
                break;
        }
    }
}

void MainWindow::goToRoom1() {
    showRoom1();
}

void MainWindow::exitGame() {
    QApplication::quit();
}
