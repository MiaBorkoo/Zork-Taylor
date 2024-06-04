// #include "TourRoom.h"
//
// TourRoom::TourRoom(QWidget *parent) : QWidget(parent) {
//     QVBoxLayout *mainLayout = new QVBoxLayout(this);
//
//     QLabel *roomLabel = new QLabel(this);
//     roomLabel->setPixmap(QPixmap("zork-pics/tours.png"));
//     roomLabel->setScaledContents(true);
//     mainLayout->addWidget(roomLabel);
//
//     QLabel *descriptionLabel = new QLabel("Choose a tour:", this);
//     descriptionLabel->setAlignment(Qt::AlignCenter);
//     mainLayout->addWidget(descriptionLabel);
//
//     QStringList tourNames = {"Fearless", "Speak Now", "Red", "1989", "Reputation", "Eras"};
//     QGridLayout *tourLayout = new QGridLayout();
//     tourLayout->setSpacing(10); // Set spacing between buttons
//
//     for (int i = 0; i < tourNames.size(); ++i) {
//         QPushButton* button = new QPushButton(tourNames[i], this);
//         tourButtons.push_back(button);
//         button->setFixedSize(130, 30); // Set button size
//         tourLayout->addWidget(button, 0, i, Qt::AlignCenter); // Position buttons in a grid layout
//         connect(button, &QPushButton::clicked, [this, i]() { emit tourButtonClicked(i); });
//     }
//
//     mainLayout->addLayout(tourLayout); // Add the tour layout to the main layout
// }
//
// QString TourRoom::getRoomImage() const {
//     return "zork-pics/tours.png";
// }
//
// QString TourRoom::getDescription() const {
//     return "Choose a tour:";
// }
