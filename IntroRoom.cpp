// #include "IntroRoom.h"
//
// IntroRoom::IntroRoom(QWidget *parent) : QWidget(parent), roomLabel(new QLabel(this)), descriptionLabel(new QLabel(this)), startButton(new QPushButton("Start Game", this)) {
//     QVBoxLayout *mainLayout = new QVBoxLayout(this);
//
//     roomLabel->setPixmap(QPixmap("zork-pics/tayFirst.png"));
//     roomLabel->setFixedSize(800, 400);
//     roomLabel->setScaledContents(true);
//     mainLayout->addWidget(roomLabel);
//
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     descriptionLabel->setText("Welcome to the Taylor Swift Game! Collect all Taylor's Version albums to win. \n Description: You'll be given 6 album options, you have to collect 4 of them in Room 1. \n Once you do that, you'll be taken to another room where you have to choose the best tour. There is only 1 correct answer. \n Click 'Start Game' to begin.");
//     mainLayout->addWidget(descriptionLabel);
//
//     startButton->setFixedSize(200, 50);
//     mainLayout->addWidget(startButton, 0, Qt::AlignCenter);
//
//     connect(startButton, &QPushButton::clicked, this, &IntroRoom::startButtonClicked);
// }
