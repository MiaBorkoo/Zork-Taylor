// Room.cpp
#include "Room.h"

Room::Room(QString description) : description(description) {}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != nullptr)
        exits["north"] = north;
    if (east != nullptr)
        exits["east"] = east;
    if (south != nullptr)
        exits["south"] = south;
    if (west != nullptr)
        exits["west"] = west;
}

QString Room::shortDescription() const {
    return description;
}

QString Room::longDescription() const {
    QString desc = "Room = " + description + ".\n";
    desc += displayTrack5Songs() + "\n";
    desc += displayRandomStuff() + "\n";
    desc += "Exits = ";
    for (auto it = exits.begin(); it != exits.end(); ++it) {
        desc += "  " + it->first;
    }
    return desc;
}

Room* Room::nextRoom(QString direction) const {
    auto next = exits.find(direction);
    if (next != exits.end())
        return next->second;
    else
        return nullptr;
}

void Room::addTrack5Song(Item song) {
    track5Songs.push_back(song);
}

void Room::addRandomStuff(Item stuff) {
    randomStuff.push_back(stuff);
}

QString Room::displayTrack5Songs() const {
    QString tempString = "Track5 Songs in room = ";
    if (track5Songs.empty()) {
        tempString = "No Track5 Songs in room";
    } else {
        for (const auto& song : track5Songs) {
            tempString += song.getShortDescription() + "  ";
        }
    }
    return tempString;
}

QString Room::displayRandomStuff() const {
    QString tempString = "Random Stuff in room = ";
    if (randomStuff.empty()) {
        tempString = "No Random Stuff in room";
    } else {
        for (const auto& stuff : randomStuff) {
            tempString += stuff.getShortDescription() + "  ";
        }
    }
    return tempString;
}

int Room::numberOfTrack5Songs() const {
    return track5Songs.size();
}

int Room::numberOfRandomStuff() const {
    return randomStuff.size();
}

Item Room::takeTrack5Song(int index) {
    Item song = track5Songs[index];
    track5Songs.erase(track5Songs.begin() + index);
    return song;
}

Item Room::takeRandomStuff(int index) {
    Item stuff = randomStuff[index];
    randomStuff.erase(randomStuff.begin() + index);
    return stuff;
}

QString Room::getPicturePath() const {
    return picturePath;
}

void Room::setPicturePath(const QString& path) {
    picturePath = path;
}

std::vector<Room*> Room::loadRoomsFromJSON(const QString& "rooms.json") {
    std::vector<Room*> rooms;

    QJsonArray roomsArray = JSONclass::parseJSON();
    for (const auto& roomValue : roomsArray) {
        if (roomValue.isObject()) {
            QJsonObject roomObject = roomValue.toObject("rooms.json");
            QString description = roomObject["description"].toString();
            Room* room = new Room(description);

            // Set exits, track5Songs, randomStuff, picturePath, etc.
            // according to your JSON structure
            // Example: room->setPicturePath(roomObject["picturePath"].toString());

            rooms.push_back(room);
        }
    }

    return rooms;
}
