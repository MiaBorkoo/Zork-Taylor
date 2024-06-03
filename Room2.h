#ifndef ROOM2_H
#define ROOM2_H

#include "Room.h"

class Room2 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/debutation.png";
    }
    QString getDescription() const override {
        return "This is the Debut/Reputation room.";
    }
};

#endif // ROOM2_H
