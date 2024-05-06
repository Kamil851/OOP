#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int code;
    std::string name;

public:
    Client(int c, std::string n);

    int GetCode() const;
    std::string GetName() const;
};

#endif // CLIENT_H
