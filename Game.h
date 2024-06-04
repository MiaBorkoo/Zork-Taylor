#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <array>
#include "Room.h"

// Namespaces
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

    // Union
    union Data {
        int intValue;
        float floatValue;
        char charValue;
    };

    // Abstract class
    class Drawable {
    public:
        virtual void draw() const = 0;
    };

    // Bit structures
    struct BitFields {
        unsigned int a : 1;
        unsigned int b : 3;
        unsigned int c : 4;
    };

    class Game {
    public:
        Game();
        Game(const Game& other); // Copy constructor
        ~Game(); // Destructor
        void addRoom(std::unique_ptr<Room> room);
        Room* getRoom(int index) const;

        // Operator overloading
        bool operator==(const Game& other) const;
        Game& operator=(const Game& other); // Assignment operator

        // Friend function
        friend std::ostream& operator<<(std::ostream& os, const Game& game);

        // Memory management (new/delete)
        int* allocateInt();
        void deallocateInt(int* ptr);

    private:
        std::vector<std::unique_ptr<Room>> rooms;
        Manager<std::string> itemManager; // Using the template class
        BitFields bitFields; // Using bitfields

    protected:
        int protectedValue;
    private:
        int privateValue;
    };

    std::ostream& operator<<(std::ostream& os, const Game& game);

} // namespace GameNamespace

#endif // GAME_H
