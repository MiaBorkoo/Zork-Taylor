#ifndef ROOM2_H
#define ROOM2_H

#include "Room.h"

class Room2 : public Room {
public:
    QString getRoomImage() const override {
        return "debutation.png";
    }

    QString getDescription() const override {
        return "This is Room 2.";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<Room2>(*this);
    }
};

#endif // ROOM2_H
