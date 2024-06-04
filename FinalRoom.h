#ifndef ROOMFINAL_H
#define ROOMFINAL_H

#include "Room.h"

class FinalRoom : public Room {
public:
    QString getRoomImage() const override {
        return "own.png";
    }

    QString getDescription() const override {
        return "Congratulations! You have completed the Taylor Swift Game.";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<FinalRoom>(*this);
    }
};

#endif // ROOMFINAL_H
