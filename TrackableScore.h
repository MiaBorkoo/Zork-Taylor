#ifndef TRACKABLESCORE_H
#define TRACKABLESCORE_H

#include "Score.h"
#include "Trackable.h"

class TrackableScore : public Score, public Trackable {
public:
    void addToScore(int points) override {
        Score::addToScore(points);
        logChange("Added " + std::to_string(points) + " points. Total: " + std::to_string(getScore()));
    }

    void logChange(const std::string& change) override {
        scoreLog.push_back(change);
    }

    std::vector<std::string> getLog() const override {
        return scoreLog;
    }

private:
    std::vector<std::string> scoreLog;
};

#endif // TRACKABLESCORE_H
