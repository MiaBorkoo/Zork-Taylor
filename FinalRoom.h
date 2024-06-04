#ifndef ROOMFINAL_H
#define ROOMFINAL_H

#include "Room.h"

class FinalRoom : public Room {
public:
    QString getRoomImage() const override {
        return "own.png";
    }

    QString getDescription() const override {
        return "Congratulations! You collected all the Taylor's version albums And you selected the best tour known to universe.\n You have completed the game and your reward is Tay Tay with all the albums she owns now.  \n Now go listen to Taylor.";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<FinalRoom>(*this);
    }
};

#endif // ROOMFINAL_H
