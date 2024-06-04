#ifndef INTROROOM_H
#define INTROROOM_H

#include "Room.h"

class IntroRoom : public Room {
public:
    QString getRoomImage() const override {
        return "tayFirst.png";
    }

    QString getDescription() const override {
        return "Welcome to the Taylor Swift Game! Collect all Taylor's Version albums to win. \n Description: You'll be given 6 album options, you have to collect 4 of them in Room 1. \n Once you do that, you'll be taken to another room where you have to choose the best tour. There is only 1 correct answer. \n Click 'Start Game' to begin.";

    }

    std::unique_ptr<Room> clone() const override {
        return std::make_unique<IntroRoom>(*this);
    }
};

#endif // INTROROOM_H
