#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Score.h"

namespace GameNamespace {

    class Game {
    public:
        Game();
        Game(const Game& other);
        ~Game();

        // Score update function
        void updateScore(int points);

        // Player name setter and getter
        void setPlayerName(const std::string& name);
        std::string getPlayerName() const;

        // Get current score
        int getScore() const;

        // union for additional future feature
        union GameState {
            int level;
            char status[10];
        } gameState;

    private:
        Player player;
        Score score;
    };

} // namespace GameNamespace

#endif // GAME_H