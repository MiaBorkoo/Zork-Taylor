#ifndef ROOM2_H
#define ROOM2_H

#include "Room.h"

class Room2 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/own.png"; // Update with the correct path to your room2 image
    }
};

#endif // ROOM2_H

