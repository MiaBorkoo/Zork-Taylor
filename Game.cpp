#include "Game.h"

namespace GameNamespace {

    // Copy constructor (deep copy)
    Game::Game(const Game& other) : protectedValue(other.protectedValue), privateValue(other.privateValue), bitFields(other.bitFields) {
        for (const auto& room : other.rooms) {
            rooms.push_back(std::unique_ptr<Room>(room->clone()));
        }
    }

    // Initializer list and object construction sequence
    Game::Game() : protectedValue(0), privateValue(0) {
        std::cout << "Game created" << std::endl;
    }

    void Game::addRoom(std::unique_ptr<Room> room) {
        std::cout << "Adding room" << std::endl;
        rooms.push_back(std::move(room));
    }

    Room* Game::getRoom(int index) const {
        std::cout << "Getting room at index " << index << std::endl;
        if (index >= 0 && index < rooms.size()) {
            return rooms[index].get();
        }
        throw GameException("Room index out of bounds");
    }

    // Destructor
    Game::~Game() {
        std::cout << "Game destroyed" << std::endl;
    }

    // Operator overloading
    bool Game::operator==(const Game& other) const {
        return privateValue == other.privateValue && protectedValue == other.protectedValue;
    }

    // Assignment operator (deep copy)
    Game& Game::operator=(const Game& other) {
        if (this != &other) {
            protectedValue = other.protectedValue;
            privateValue = other.privateValue;
            bitFields = other.bitFields;

            rooms.clear();
            for (const auto& room : other.rooms) {
                rooms.push_back(std::unique_ptr<Room>(room->clone()));
            }
        }
        return *this;
    }

    // Friend function
    std::ostream& operator<<(std::ostream& os, const Game& game) {
        os << "Game(privateValue=" << game.privateValue << ", protectedValue=" << game.protectedValue << ")";
        return os;
    }

    // Memory management (new/delete)
    int* Game::allocateInt() {
        return new int(42);
    }

    void Game::deallocateInt(int* ptr) {
        delete ptr;
    }

}
