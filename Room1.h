#ifndef ROOM1_H
#define ROOM1_H

#include "Room.h"

class Room1 : public Room {
public:
    QString getRoomImage() const override {
        return "steal.png";
    }

    QString getDescription() const override {
        return "This is Room 1.";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<Room1>(*this);
    }
};

#endif // ROOM1_H
