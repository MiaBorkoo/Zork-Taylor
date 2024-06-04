// Collectible.h
#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

//template class that can be used for collecting items

template<typename T>
class Collectible {
public:
    Collectible(T item) : item(item) {}
    T getItem() const { return item; }
private:
    T item;
};

#endif // COLLECTIBLE_H