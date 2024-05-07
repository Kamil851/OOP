#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

using namespace std;

class Client {
private:
    string name;
    string address;

public:
    Client(const string& n, const string& addr);
    string GetName() const;
    string GetAddress() const;
};

#endif // CLIENT_H
