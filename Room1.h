#ifndef ROOM1_H
#define ROOM1_H

#include "Room.h"

class Room1 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/steal.png"; // Update with the correct path to your room1 image
    }
};

#endif // ROOM1_H
