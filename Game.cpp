#include "Game.h"

namespace GameNamespace {

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

}
