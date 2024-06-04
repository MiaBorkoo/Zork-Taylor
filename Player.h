#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Collectible.h" //using the template class here

class Player {
public:
    Player(const std::string& name) : name(name) {}
    std::string getName() const { return name; }

    // Add an item to the player's collection
    template<typename T>
    void addCollectible(const Collectible<T>& collectible) {
        collectibles.push_back(collectible.getItem());
    }

    // Display the player's collectibles
    void showCollectibles() const {
        std::cout << "Collectibles: ";
        for (const auto& item : collectibles) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

private:
    std::string name;
    std::vector<std::string> collectibles;  // Assuming all collectibles are strings
};

#endif // PLAYER_H