#ifndef TAYLORMANAGER_H
#define TAYLORMANAGER_H

#include <set>

#include "Room.h"
#include "Player.h"


class Player;

class MainWindow;


class TaylorManager {
public:
    TaylorManager();

    void showIntroRoom(MainWindow* mainWindow);
    void startGame(MainWindow* mainWindow);
    void showRoom1(MainWindow* mainWindow);
    void showRoom2(MainWindow* mainWindow);
    void showTourRoom(MainWindow* mainWindow);
    void showFinalRoom(MainWindow* mainWindow);
    void showSpecificRoom(MainWindow* mainWindow, const QString& albumName, const QString& newAlbumImagePath);
    bool isAllAlbumsCollected() const;
    void performInvalidMove();
    //void updateScore(Score& score, int points); -> for score implementation in the future
    void collectAlbum(Player& player, const std::string& album);
    void logPlayerScoreChanges(const Player& player);

private:
    void showRoom(MainWindow* mainWindow, const Room& room);
    void createTourLayout(MainWindow* mainWindow);
    std::set<QString> collectedAlbums;
    std::set<QString> requiredAlbums = {"Fearless", "Speak Now", "Red", "1989"};
};



#endif // TAYLORMANAGER_H
