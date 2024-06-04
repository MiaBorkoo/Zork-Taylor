#ifndef ROOM2_H
#define ROOM2_H

#include "Room.h"

class Room2 : public Room {
public:
    QString getRoomImage() const override {
        return "debutation.png";
    }

    QString getDescription() const override {
        return "This is the room where Reputation and Debut live. They are all alone, waiting for their rerecords. \n You can't collect them yet because Taylor hasn't blessed us with their rerecords yet.";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<Room2>(*this);
    }
};

#endif // ROOM2_H
