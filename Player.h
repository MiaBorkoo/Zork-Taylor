#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Collectible.h"
#include "TrackableScore.h"

class Player {
    friend class TaylorManager;  // Granting friendship to TaylorManager
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

    void setScore(int points) { score.addToScore(points); }
    int getScore() const { return score.getScore(); }

    std::vector<std::string> getScoreLog() const { return score.getLog(); }

    bool operator==(const Player& other) const {
        return this->score.getScore() == other.score.getScore();
    }

private:
    std::string name;
    std::vector<std::string> collectibles;
    TrackableScore score;
};

#endif // PLAYER_H
