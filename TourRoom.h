#ifndef ROOMTOUR_H
#define ROOMTOUR_H

#include "Room.h"

class TourRoom : public Room {
public:
    QString getRoomImage() const override {
        return "tours.png";
    }

    QString getDescription() const override {
        return "Choose a tour:";
    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<TourRoom>(*this);
    }
};

#endif // ROOMTOUR_H
