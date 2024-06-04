#ifndef SCORE_H
#define SCORE_H

class Score {
public:
    Score() : score(0) {}
    int getScore() const { return score; }
    void addToScore(int points) { score += points; }
private:
    int score;
};

#endif // SCORE_H