// #ifndef ROOMMANAGER_H
// #define ROOMMANAGER_H
//
// #include <QObject>
// #include <QWidget>
// #include <QVBoxLayout>
// #include <QLabel>
// #include <QPushButton>
// #include <set>
// #include "Game.h"
// #include "Room1.h"
//
// class RoomManager : public QObject {
//     Q_OBJECT
//
// public:
//     explicit RoomManager(GameNamespace::Game *game, QWidget *parent = nullptr);
//
//     signals:
//         void roomChanged(QWidget *newRoom);
//
//     public slots:
//         void showIntroRoom();
//     void showRoom1();
//     void showRoom2();
//     void showTourRoom();
//     void showFinalRoom();
//     void handleButtonClicked(int buttonId);
//     void handleTourButtonClick(int buttonId);
//
// private:
//     void setupIntroRoom();
//     void setupRoom2();
//     void setupTourRoom();
//     void setupFinalRoom();
//     void setupSpecificRoom(const QString &albumName, const QString &imagePath);
//
//     GameNamespace::Game *game;
//     Room1 *room1;
//     QWidget *introRoom;
//     QWidget *tourRoom;
//     QWidget *finalRoom;
//     QWidget *room2;
//     std::set<QString> collectedAlbums;
// };
//
// #endif // ROOMMANAGER_H
