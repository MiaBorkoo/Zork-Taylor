#ifndef ROOM3_H
#define ROOM3_H

#include "Room.h"

class Room3 : public Room {
public:
    QString getRoomImage() const override {
        return "zork-pics/speakNowNew.png";
    }
    QString getDescription() const override {
        return "You have found the Speak Now album.";
    }
};

#endif // ROOM3_H
