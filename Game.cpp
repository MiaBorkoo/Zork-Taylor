#include "Game.h"

namespace GameNamespace {

    // Copy constructor
    Game::Game(const Game& other) : player(other.player), score(other.score) {
        gameState.level = other.gameState.level; // Copying union state
    }

    // Initializer list and object construction sequence
    Game::Game() : player("miaIsTrying"), score() {
        gameState.level = 1; // Initializing union state
        std::cout << "Game created" << std::endl;
    }

    // Destructor
    Game::~Game() {
        std::cout << "Game destroyed" << std::endl;
    }

    // Score update function
    void Game::updateScore(int points) {
        score.addToScore(points);
    }

    // set and get method for player's name
    void Game::setPlayerName(const std::string& name) {
        player = Player(name);
    }

    std::string Game::getPlayerName() const {
        return player.getName();
    }

    int Game::getScore() const {
        return score.getScore();
    }

}