#include "TaylorManager.h"
#include "MainWindow.h"
#include "Room1.h"
#include "Room2.h"
#include "TourRoom.h"
#include "FinalRoom.h"
#include "IntroRoom.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <algorithm>
#include <iostream>
#include <QObject> // Ensure this is included

TaylorManager::TaylorManager() {}

void TaylorManager::showIntroRoom(MainWindow* mainWindow) {
    IntroRoom introRoom;
    showRoom(mainWindow, introRoom);
}

void TaylorManager::startGame(MainWindow* mainWindow) {
    showRoom1(mainWindow);
}

void TaylorManager::showRoom1(MainWindow* mainWindow) {
    Room1 room1;
    showRoom(mainWindow, room1);
}

void TaylorManager::showRoom2(MainWindow* mainWindow) {
    Room2 room2;
    showRoom(mainWindow, room2);
}

void TaylorManager::showTourRoom(MainWindow* mainWindow) {
    TourRoom roomTour;
    showRoom(mainWindow, roomTour);
}

void TaylorManager::showFinalRoom(MainWindow* mainWindow) {
    FinalRoom roomFinal;
    showRoom(mainWindow, roomFinal);
}

void TaylorManager::showRoom(MainWindow* mainWindow, const Room& room) {
    QString imagePath = "zork-pics/" + room.getRoomImage();

    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
        QMessageBox::critical(mainWindow, "Error", "Failed to load image: " + imagePath);
        return;
    }

    mainWindow->getRoomLabel()->setPixmap(pixmap);
    mainWindow->getRoomLabel()->setScaledContents(true);

    mainWindow->getDescriptionLabel()->setText(room.getDescription());

    if (dynamic_cast<const IntroRoom*>(&room)) {
        mainWindow->getStartButton()->show();
        mainWindow->getBackButton()->hide();
        mainWindow->getExitButton()->hide();
        for (QPushButton *button : mainWindow->getButtons()) {
            button->hide();
        }
        for (QLabel *textLabel : mainWindow->getTextLabels()) {
            textLabel->clear();
        }

        QHBoxLayout *descriptionLayout = new QHBoxLayout();
        descriptionLayout->addStretch();
        descriptionLayout->addWidget(mainWindow->getDescriptionLabel());
        descriptionLayout->addStretch();

        // Add the description layout to the main layout
        mainWindow->getMainLayout()->addLayout(descriptionLayout);
    } else if (dynamic_cast<const Room2*>(&room)) {
        for (QPushButton *button : mainWindow->getButtons()) {
            button->hide();
        }
        for (QLabel *textLabel : mainWindow->getTextLabels()) {
            textLabel->clear();
        }

        mainWindow->getBackButton()->show();
        mainWindow->getExitButton()->hide();
        mainWindow->getStartButton()->hide();
    } else if (dynamic_cast<const TourRoom*>(&room)) {
        createTourLayout(mainWindow);
    } else {
        for (QPushButton *button : mainWindow->getButtons()) {
            button->show();
        }
        for (QLabel *textLabel : mainWindow->getTextLabels()) {
            textLabel->clear();
        }
        mainWindow->getBackButton()->hide();
        mainWindow->getExitButton()->hide();
        mainWindow->getStartButton()->hide();
    }

    if (dynamic_cast<const FinalRoom*>(&room)) {
        for (QPushButton *button : mainWindow->getButtons()) {
            button->hide();
        }
        for (QLabel *textLabel : mainWindow->getTextLabels()) {
            textLabel->clear();
        }
        mainWindow->getBackButton()->hide();
        mainWindow->getStartButton()->hide();
        for (QPushButton *button : mainWindow->getTourButtons()) {
            button->hide();
        }
        mainWindow->getExitButton()->show();
    }
}

void TaylorManager::createTourLayout(MainWindow* mainWindow) {
    QStringList tourNames = {"Fearless", "Speak Now", "Red", "1989", "Reputation", "Eras"};
    QGridLayout *tourLayout = new QGridLayout();
    tourLayout->setSpacing(10); // Set spacing between buttons

    for (int i = 0; i < tourNames.size(); ++i) {
        QPushButton* button = new QPushButton(tourNames[i], mainWindow);
        mainWindow->getTourButtons().push_back(button);
        button->setFixedSize(130, 30); // Set button size
        tourLayout->addWidget(button, 0, i, Qt::AlignCenter); // Position buttons in a grid layout
        QObject::connect(button, &QPushButton::clicked, mainWindow, [mainWindow, i]() { mainWindow->handleTourButtonClick(i); });
    }
    for (QPushButton *button : mainWindow->getButtons()) {
        button->hide();
    }
    for (QLabel *textLabel : mainWindow->getTextLabels()) {
        textLabel->clear();
    }
    mainWindow->getBackButton()->hide();
    mainWindow->getExitButton()->hide();
    mainWindow->getStartButton()->hide();

    mainWindow->getMainLayout()->addLayout(tourLayout); // Add the tour layout to the main layout
}

void TaylorManager::showSpecificRoom(MainWindow* mainWindow, const QString& albumName, const QString& newAlbumImagePath) {
    std::cout << "Showing specific room for " << albumName.toStdString() << std::endl;

    collectedAlbums.insert(albumName); // Add the album to the collected set

    QString imagePath = "zork-pics/" + newAlbumImagePath; // Ensure only one "zork-pics/" is added
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        std::cerr << "Failed to load image: " << imagePath.toStdString() << std::endl;
        QMessageBox::critical(mainWindow, "Error", "Failed to load image: " + imagePath);
        return;
    }

    mainWindow->getRoomLabel()->setPixmap(pixmap);
    mainWindow->getRoomLabel()->setScaledContents(true);

    for (QPushButton *button : mainWindow->getButtons()) {
        button->hide();
    }
    for (QLabel *textLabel : mainWindow->getTextLabels()) {
        textLabel->clear(); // Clear the text labels
    }

    if (albumName == "Fearless") {
        mainWindow->getDescriptionLabel()->setText("You have entered the room for Fearless. Taylor's Version is here.");
    } else if (albumName == "Speak Now") {
        mainWindow->getDescriptionLabel()->setText("You have entered the room for Speak Now. Taylor's Version is here.");
    } else if (albumName == "Red") {
        mainWindow->getDescriptionLabel()->setText("You have entered the room for Red. Taylor's Version is here.");
    } else if (albumName == "1989") {
        mainWindow->getDescriptionLabel()->setText("You have entered the room for 1989. Taylor's Version is here.");
    }

    mainWindow->getBackButton()->show();  // Show the back button in specific rooms
    mainWindow->getExitButton()->hide();  // Hide the exit button in specific rooms

    // Check if all required albums are collected
    if (isAllAlbumsCollected()) {
        QMessageBox::information(mainWindow, "Congratulations", "All Taylor's Version albums collected!\n The world has been blessed to have them");
        collectedAlbums.clear(); // Clear the collected albums set
        showTourRoom(mainWindow);  // Transition to the tour room
    }
}



bool TaylorManager::isAllAlbumsCollected() const {
    return collectedAlbums.size() >= requiredAlbums.size() && std::includes(collectedAlbums.begin(), collectedAlbums.end(), requiredAlbums.begin(), requiredAlbums.end());
}
