#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string name;
    std::string address;

public:
    Client(const std::string& n, const std::string& addr);
};

#endif // CLIENT_H
