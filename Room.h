#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room {
public:
    virtual ~Room() = default;
    virtual QString getRoomImage() const = 0;
    virtual QString getDescription() const = 0;
};

#endif // ROOM_H
