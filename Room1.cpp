// #include "Room1.h"
//
// Room1::Room1(QWidget *parent) : QWidget(parent) {
//     QVBoxLayout *mainLayout = new QVBoxLayout(this);
//
//     roomLabel = new QLabel(this);
//     roomLabel->setPixmap(QPixmap("zork-pics/steal.png"));
//     roomLabel->setScaledContents(true);
//     mainLayout->addWidget(roomLabel);
//
//     descriptionLabel = new QLabel("These are Taylor's first 6 albums. In 2019, they were sold to a third party. \n This means that she doesn't own any of her songs from these albums (she wrote every song herself), and not a single cent goes into her pocket when fans stream her music.\n Thats why Taylor (the legend she is) decided to rerecord her past albums so she can own her art. \n 4 out of these 6 albums are rerecorded. Your task is to collect them to get to the next room.", this);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     mainLayout->addWidget(descriptionLabel);
//
//     QStringList albumNames = {"Debut", "Fearless", "Speak Now", "Red", "1989", "Reputation"};
//     QGridLayout *buttonLayout = new QGridLayout();
//     buttonLayout->setSpacing(10);
//
//     for (int i = 0; i < albumNames.size(); ++i) {
//         QLabel *albumLabel = new QLabel(this);
//         albumLabel->setPixmap(QPixmap("zork-pics/" + albumNames[i] + ".png"));
//         albumLabel->setScaledContents(true);
//         albumLabel->setFixedSize(130, 130);
//         buttonLayout->addWidget(albumLabel, 0, i, Qt::AlignCenter);
//
//         QPushButton *button = new QPushButton(albumNames[i], this);
//         buttons.push_back(button);
//         button->setFixedSize(130, 30);
//         buttonLayout->addWidget(button, 1, i, Qt::AlignCenter);
//         connect(button, &QPushButton::clicked, [this, i]() { emit buttonClicked(i); });
//
//         QLabel *textLabel = new QLabel(this);
//         textLabels.push_back(textLabel);
//         buttonLayout->addWidget(textLabel, 2, i, Qt::AlignCenter);
//     }
//
//     mainLayout->addLayout(buttonLayout);
//
//     // Add the back button
//     backButton = new QPushButton("Back to Room 1", this);
//     mainLayout->addWidget(backButton, 0, Qt::AlignCenter);
//     connect(backButton, &QPushButton::clicked, this, &Room1::backButtonClicked);
//
//     setLayout(mainLayout);  // Ensure the layout is set
// }
//
// QString Room1::getRoomImage() const {
//     return "zork-pics/steal.png";
// }
//
// QString Room1::getDescription() const {
//     return "These are Taylor's first 6 albums. In 2019, they were sold to a third party. \n This means that she doesn't own any of her songs from these albums (she wrote every song herself), and not a single cent goes into her pocket when fans stream her music.\n Thats why Taylor (the legend she is) decided to rerecord her past albums so she can own her art. \n 4 out of these 6 albums are rerecorded. Your task is to collect them to get to the next room.";
// }
