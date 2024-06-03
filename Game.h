#ifndef GAME_H
#define GAME_H

#include <vector>

#include <iostream>
#include <stdexcept>
#include "Room.h"

namespace GameNamespace {

    // Programmer defined exception
    class GameException : public std::exception {
    public:
        explicit GameException(const std::string& message) : message_(message) {}
        const char* what() const noexcept override {
            return message_.c_str();
        }
    private:
        std::string message_;
    };

    // Template class
    template <typename T>
    class Manager {
    public:
        void addItem(const T& item) {
            items.push_back(item);
        }
        T getItem(int index) const {
            if (index >= 0 && index < items.size()) {
                return items[index];
            }
            throw GameException("Index out of bounds");
        }
    private:
        std::vector<T> items;
    };

    class Game {
    public:
        Game();
        void addRoom(std::unique_ptr<Room> room);
        Room* getRoom(int index) const;

    private:
        std::vector<std::unique_ptr<Room>> rooms;
        Manager<std::string> itemManager; // Using the template class

        // Private, public, protected
    protected:
        int protectedValue;
    private:
        int privateValue;
    };

} // namespace GameNamespace

#endif // GAME_H
