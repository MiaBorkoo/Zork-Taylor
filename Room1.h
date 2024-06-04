#ifndef ROOM1_H
#define ROOM1_H

#include "Room.h"

class Room1 : public Room {
public:
    QString getRoomImage() const override {
        return "steal.png";
    }

    QString getDescription() const override {
        return " These are Taylor's albums that were sold to a third party in 2019. \n She doesn't own any of these inspite of writing every single song on them.\n Thats why iconic Tay Tay decided to rerecord the albums. She rerecorded 4 out of 6 on this list.\n They are now here in this basement waiting to be rescued. Find them. Good luck.";

    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<Room1>(*this);
    }
};

#endif // ROOM1_H
