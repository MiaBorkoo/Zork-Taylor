#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <memory>
#include <iostream>

class Room {
public:
    virtual ~Room() = default;
    virtual QString getRoomImage() const = 0;
    virtual QString getDescription() const = 0;
    virtual std::unique_ptr<Room> clone() const = 0; // Clone method
};

#endif // ROOM_H
