#ifndef SCORE_H
#define SCORE_H

class Score {
public:
    Score() : score(0) {}
    virtual ~Score() = default;  // Ensure a virtual destructor for polymorphism

    int getScore() const { return score; }
    virtual void addToScore(int points) { score += points; }

private:
    int score;
};

#endif // SCORE_H
