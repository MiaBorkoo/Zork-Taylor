#ifndef TRACKABLE_H
#define TRACKABLE_H

#include <vector>
#include <string>

class Trackable {
public:
    virtual void logChange(const std::string& change) = 0;
    virtual std::vector<std::string> getLog() const = 0;
};

#endif // TRACKABLE_H
