#include "client.h"

Client::Client(const string& n, const string& addr) : name(n), address(addr) {}

string Client::GetName() const {
    return name;
}

string Client::GetAddress() const {
    return address;
}
