#include "mainWindow.h"
#include "Room1.h"
#include "Room2.h"
#include "Room3.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), roomLabel(new QLabel(this)), game(new GameNamespace::Game()) {
    setCentralWidget(roomLabel);


    // Add rooms to the game
    game->addRoom(std::make_unique<Room1>());
    game->addRoom(std::make_unique<Room2>());
    game->addRoom(std::make_unique<Room3>());

    std::cout << "Rooms added to the game" << std::endl;

    for (int i = 0; i < 7; ++i) {
        buttons.push_back(new QPushButton(this));
        buttons[i]->setGeometry(100 + i * 150, 500, 130, 130); // Adjust the geometry as needed
        buttons[i]->setFlat(true); // Make the button transparent
        buttons[i]->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        connect(buttons[i], &QPushButton::clicked, [this, i]() { handleButtonClick(i); });
    }

    std::cout << "Buttons created and connected" << std::endl;

    showRoom1();
}

MainWindow::~MainWindow() {
    delete game.release();
}

void MainWindow::showRoom1() {
    std::cout << "Showing Room 1" << std::endl;
    QString imagePath = "zork-pics/steal.png"; // Update the path as needed

    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
        QMessageBox::critical(this, "Error", "Failed to load image: " + imagePath);
        return;
    }

    roomLabel->setPixmap(pixmap);
    roomLabel->setScaledContents(true);

    for (QPushButton *button : buttons) {
        button->show();
    }
}

void MainWindow::showRoom2() {
    std::cout << "Showing Room 2" << std::endl;
    Room* room = game->getRoom(1); // Assuming room2 is at index 1
    if (room) {
        QString imagePath = room->getRoomImage();
        QPixmap pixmap(imagePath);
        if (pixmap.isNull()) {
            std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
            QMessageBox::critical(this, "Error", "Failed to load image: " + imagePath);
            return;
        }
        roomLabel->setPixmap(pixmap);
    }
    roomLabel->setScaledContents(true);

    for (QPushButton *button : buttons) {
        button->hide();
    }
}

void MainWindow::showRoom3() {
    std::cout << "Showing Room 3" << std::endl;
    Room* room = game->getRoom(2); // Assuming room3 is at index 2
    if (room) {
        QString imagePath = room->getRoomImage();
        QPixmap pixmap(imagePath);
        if (pixmap.isNull()) {
            std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
            QMessageBox::critical(this, "Error", "Failed to load image: " + imagePath);
            return;
        }
        roomLabel->setPixmap(pixmap);
    }
    roomLabel->setScaledContents(true);

    for (QPushButton *button : buttons) {
        button->hide();
    }
}

void MainWindow::handleButtonClick(int buttonId) {
    std::cout << "Button " << buttonId << " clicked" << std::endl;
    if (buttonId == 0 || buttonId == 6) {
        showRoom2();
    } else {
        showRoom3();
    }
}
