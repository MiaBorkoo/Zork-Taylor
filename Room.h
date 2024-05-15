//
// Created by mia borko on 14/05/2024.
//
#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <vector>
#include <QString>
#include "item.h"
#include "JSONclass.h"
using namespace std;

class Room {
private:
    QString description;
    std::map<QString, Room*> exits;
    std::vector<Item> track5Songs;
    std::vector<Item> randomStuff;
    QString picturePath;

public:
    Room(QString description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    QString shortDescription() const;
    QString longDescription() const;
    Room* nextRoom(QString direction) const;
    void addTrack5Song(Item song);
    void addRandomStuff(Item stuff);
    QString displayTrack5Songs() const;
    QString displayRandomStuff() const;
    int numberOfTrack5Songs() const;
    int numberOfRandomStuff() const;
    Item takeTrack5Song(int index);
    Item takeRandomStuff(int index);
    QString getPicturePath() const;
    void setPicturePath(const QString& path);

    static std::vector<Room*> loadRoomsFromJSON(const QString& filePath);
};


#endif // ROOM_H