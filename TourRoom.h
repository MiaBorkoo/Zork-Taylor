#ifndef ROOMTOUR_H
#define ROOMTOUR_H

#include "Room.h"

class TourRoom : public Room {
public:
    QString getRoomImage() const override {
        return "tours.png";
    }

    QString getDescription() const override {
        return "Here are all the tours Taylor has ever been on - but only 1 is the best. Choose the best tour out of them all. \n Hint: creator's favorite album";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<TourRoom>(*this);
    }
};

#endif // ROOMTOUR_H
