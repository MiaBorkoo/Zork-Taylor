// #include "RoomManager.h"
// #include <QMessageBox>
// #include <QApplication>
//
// RoomManager::RoomManager(GameNamespace::Game *game, QWidget *parent)
//     : QObject(parent), game(game) {
//     room1 = new Room1(parent);
//     connect(room1, &Room1::buttonClicked, this, &RoomManager::handleButtonClicked);
//     connect(room1, &Room1::backButtonClicked, this, &RoomManager::showRoom1); // Handle back button
//
//     // Initialize other rooms and connect signals
//     introRoom = new QWidget(parent);
//     tourRoom = new QWidget(parent);
//     finalRoom = new QWidget(parent);
//     room2 = new QWidget(parent);
//
//     // Setup UI for each room
//     setupIntroRoom();
//     setupTourRoom();
//     setupFinalRoom();
//     setupRoom2();
// }
//
// void RoomManager::setupIntroRoom() {
//     QVBoxLayout *layout = new QVBoxLayout(introRoom);
//     QLabel *roomLabel = new QLabel(introRoom);
//     roomLabel->setPixmap(QPixmap("zork-pics/tayFirst.png"));
//     roomLabel->setScaledContents(true);
//     layout->addWidget(roomLabel);
//
//     QLabel *descriptionLabel = new QLabel("Welcome to the Taylor Swift Game! Collect all Taylor's Version albums to win. \n Description: You'll be given 6 album options, you have to collect 4 of them in Room 1. \n Once you do that, you'll be taken to another room where you have to choose the best tour. There is only 1 correct answer. \n Click 'Start Game' to begin.", introRoom);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(descriptionLabel);
//
//     QPushButton *startButton = new QPushButton("Start Game", introRoom);
//     layout->addWidget(startButton, 0, Qt::AlignCenter);
//     connect(startButton, &QPushButton::clicked, this, &RoomManager::showRoom1);
//
//     introRoom->setLayout(layout);
// }
//
// void RoomManager::setupRoom2() {
//     QVBoxLayout *layout = new QVBoxLayout(room2);
//     QLabel *roomLabel = new QLabel(room2);
//     roomLabel->setPixmap(QPixmap("zork-pics/debutation.png"));
//     roomLabel->setScaledContents(true);
//     layout->addWidget(roomLabel);
//
//     QLabel *descriptionLabel = new QLabel("This is where Debut/Reputation reside. They are all alone.", room2);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(descriptionLabel);
//
//     QPushButton *backButton = new QPushButton("Back to Room 1", room2);
//     layout->addWidget(backButton, 0, Qt::AlignCenter);
//     connect(backButton, &QPushButton::clicked, this, &RoomManager::showRoom1);
//
//     room2->setLayout(layout);
// }
//
// void RoomManager::setupTourRoom() {
//     QVBoxLayout *layout = new QVBoxLayout(tourRoom);
//     QLabel *roomLabel = new QLabel(tourRoom);
//     roomLabel->setPixmap(QPixmap("zork-pics/tours.png"));
//     roomLabel->setScaledContents(true);
//     layout->addWidget(roomLabel);
//
//     QLabel *descriptionLabel = new QLabel("Choose a tour:", tourRoom);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(descriptionLabel);
//
//     QStringList tourNames = {"Fearless", "Speak Now", "Red", "1989", "Reputation", "Eras"};
//     QGridLayout *tourLayout = new QGridLayout();
//     tourLayout->setSpacing(10);
//
//     for (int i = 0; i < tourNames.size(); ++i) {
//         QPushButton* button = new QPushButton(tourNames[i], tourRoom);
//         connect(button, &QPushButton::clicked, [this, i]() { handleTourButtonClick(i); });
//         tourLayout->addWidget(button, 0, i, Qt::AlignCenter);
//     }
//     layout->addLayout(tourLayout);
//
//     tourRoom->setLayout(layout);
// }
//
// void RoomManager::setupFinalRoom() {
//     QVBoxLayout *layout = new QVBoxLayout(finalRoom);
//     QLabel *roomLabel = new QLabel(finalRoom);
//     roomLabel->setPixmap(QPixmap("zork-pics/own.png"));
//     roomLabel->setScaledContents(true);
//     layout->addWidget(roomLabel);
//
//     QLabel *descriptionLabel = new QLabel("Congratulations! You have completed the Taylor Swift Game.", finalRoom);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(descriptionLabel);
//
//     QPushButton *exitButton = new QPushButton("Exit the Game", finalRoom);
//     layout->addWidget(exitButton, 0, Qt::AlignCenter);
//     connect(exitButton, &QPushButton::clicked, []() { QCoreApplication::quit(); });
//
//     finalRoom->setLayout(layout);
// }
//
// void RoomManager::showIntroRoom() {
//     emit roomChanged(introRoom);
// }
//
// void RoomManager::showRoom1() {
//     emit roomChanged(room1);
// }
//
// void RoomManager::showRoom2() {
//     emit roomChanged(room2);
// }
//
// void RoomManager::showTourRoom() {
//     emit roomChanged(tourRoom);
// }
//
// void RoomManager::showFinalRoom() {
//     emit roomChanged(finalRoom);
// }
//
// void RoomManager::handleButtonClicked(int buttonId) {
//     if (buttonId == 0 || buttonId == 5) {
//         showRoom2();
//     } else {
//         QString albumName;
//         QString imagePath;
//
//         switch (buttonId) {
//             case 1:
//                 albumName = "Fearless";
//                 imagePath = "zork-pics/Fearless1.png";
//                 break;
//             case 2:
//                 albumName = "Speak Now";
//                 imagePath = "zork-pics/speakNowNew.png";
//                 break;
//             case 3:
//                 albumName = "Red";
//                 imagePath = "zork-pics/Red1.png";
//                 break;
//             case 4:
//                 albumName = "1989";
//                 imagePath = "zork-pics/1989new.png";
//                 break;
//             default:
//                 return;
//         }
//
//         collectedAlbums.insert(albumName);
//         QPixmap pixmap(imagePath);
//         if (pixmap.isNull()) {
//             QMessageBox::critical(nullptr, "Error", "Failed to load image: " + imagePath);
//             return;
//         }
//
//         QLabel *roomLabel = new QLabel(room1);
//         roomLabel->setPixmap(pixmap);
//         roomLabel->setScaledContents(true);
//
//         QLabel *descriptionLabel = new QLabel("You have entered the room for " + albumName + ". Taylor's Version is here.", room1);
//         descriptionLabel->setAlignment(Qt::AlignCenter);
//
//         QVBoxLayout *layout = new QVBoxLayout();
//         layout->addWidget(roomLabel);
//         layout->addWidget(descriptionLabel);
//
//         QPushButton *backButton = new QPushButton("Back to Room 1", room1);
//         layout->addWidget(backButton, 0, Qt::AlignCenter);
//         connect(backButton, &QPushButton::clicked, this, &RoomManager::showRoom1);
//
//         if (room1->layout()) {
//             delete room1->layout();
//         }
//         room1->setLayout(layout);
//
//         if (collectedAlbums.size() >= 4) {
//             QMessageBox::information(nullptr, "Congratulations", "All Taylor's Version albums collected!\n The world has been blessed to have them");
//             collectedAlbums.clear();
//             showTourRoom();
//         } else {
//             emit roomChanged(room1);
//         }
//     }
// }
//
// void RoomManager::handleTourButtonClick(int buttonId) {
//     if (buttonId == 4) { // Assuming "Reputation" is at index 4
//         QMessageBox::information(tourRoom, "Good choice", "WOHOO THIS IS THE BEST TOUR EVER! \n Congrats!");
//         showFinalRoom();
//     } else {
//         QMessageBox::information(tourRoom, "Wrong Choice", "No, you failed. AGAIN!!");
//     }
// }
