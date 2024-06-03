#ifndef ROOM1_H
#define ROOM1_H

#include "Room.h"

class Room1 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/steal.png";
    }
    QString getDescription() const override {
        return "";
    }
};

#endif // ROOM1_H
