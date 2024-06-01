#ifndef ROOM3_H
#define ROOM3_H

#include "Room.h"

class Room3 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/debutation.png"; // Update with the correct path to your room3 image
    }
};

#endif // ROOM3_H
