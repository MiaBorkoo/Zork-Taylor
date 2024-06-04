// // Room.cpp
// #include "Room.h"
//
// #include <QJsonArray>
// #include <QJsonObject>
// #include <QFile>
// #include <QDebug>
//
// Room::Room(QString description) : description(description) {}
//
// void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
//     if (north != nullptr)
//         exits["north"] = north;
//     if (east != nullptr)
//         exits["east"] = east;
//     if (south != nullptr)
//         exits["south"] = south;
//     if (west != nullptr)
//         exits["west"] = west;
// }
//
// QString Room::shortDescription() const {
//     return description;
// }
//
// QString Room::longDescription() const {
//     QString desc = "Room = " + description + ".\n";
//     desc += displayTrack5Songs() + "\n";
//     desc += displayRandomStuff() + "\n";
//     desc += "Exits = ";
//     for (auto it = exits.begin(); it != exits.end(); ++it) {
//         desc += "  " + it->first;
//     }
//     return desc;
// }
//
// Room* Room::nextRoom(QString direction) const {
//     auto next = exits.find(direction);
//     if (next != exits.end())
//         return next->second;
//     else
//         return nullptr;
// }
//
// void Room::addTrack5Song(Item song) {
//     track5Songs.push_back(song);
// }
//
// void Room::addRandomStuff(Item stuff) {
//     randomStuff.push_back(stuff);
// }
//
// QString Room::displayTrack5Songs() const {
//     QString tempString = "Track5 Songs in room = ";
//     if (track5Songs.empty()) {
//         tempString = "No Track5 Songs in room";
//     } else {
//         for (const auto& song : track5Songs) {
//             tempString += song.getShortDescription() + "  ";
//         }
//     }
//     return tempString;
// }
//
// QString Room::displayRandomStuff() const {
//     QString tempString = "Random Stuff in room = ";
//     if (randomStuff.empty()) {
//         tempString = "No Random Stuff in room";
//     } else {
//         for (const auto& stuff : randomStuff) {
//             tempString += stuff.getShortDescription() + "  ";
//         }
//     }
//     return tempString;
// }
//
// int Room::numberOfTrack5Songs() const {
//     return track5Songs.size();
// }
//
// int Room::numberOfRandomStuff() const {
//     return randomStuff.size();
// }
//
// Item Room::takeTrack5Song(int index) {
//     Item song = track5Songs[index];
//     track5Songs.erase(track5Songs.begin() + index);
//     return song;
// }
//
// Item Room::takeRandomStuff(int index) {
//     Item stuff = randomStuff[index];
//     randomStuff.erase(randomStuff.begin() + index);
//     return stuff;
// }
//
// QString Room::getPicturePath() const {
//     return picturePath;
// }
//
// void Room::setPicturePath(const QString& path) {
//     picturePath = path;
// }
//
//
//
// std::vector<Room*> Room::loadRoomsFromJSON(const QString& filePath) {
//     std::vector<Room*> rooms;
//
//     QFile file(filePath);
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qDebug() << "Failed to open file:" << filePath;
//         return rooms;
//     }
//
//     QByteArray jsonData = file.readAll();
//     file.close();
//
//     QJsonDocument doc = QJsonDocument::fromJson(jsonData);
//     if (!doc.isObject()) {
//         qDebug() << "JSON data is not an object.";
//         return rooms;
//     }
//
//     QJsonObject rootObject = doc.object();
//     QJsonArray roomsArray = rootObject["rooms"].toArray();
//
//     for (const auto& roomValue : roomsArray) {
//         if (roomValue.isObject()) {
//             QJsonObject roomObject = roomValue.toObject();
//             QString description = roomObject["description"].toString();
//             QString picturePath = roomObject["picturePath"].toString();
//             Room* room = new Room(description);
//             room->setPicturePath(picturePath);
//
//             // Add the room to the vector
//             rooms.push_back(room);
//         }
//     }
//
//     return rooms;
// }
//