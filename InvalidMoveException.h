#ifndef INVALIDMOVEEXCEPTION_H
#define INVALIDMOVEEXCEPTION_H

#include <exception>
#include <string>

class InvalidMoveException : public std::exception {
public:
    InvalidMoveException(const std::string& message) : message(message) {}
    const char* what() const noexcept override { return message.c_str(); }
private:
    std::string message;
};

#endif // INVALIDMOVEEXCEPTION_H