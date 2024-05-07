#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
protected:
    std::string name;
public:
    Customer(std::string _name) : name(_name) {}
    virtual void displayInfo() = 0;
};

class RegisteredUser : public Customer {
public:
    RegisteredUser(std::string _name) : Customer(_name) {}
    void displayInfo() override {
        std::cout << "Registered User: " << name << std::endl;
    }
};

class UnregisteredUser : public Customer {
public:
    UnregisteredUser(std::string _name) : Customer(_name) {}
    void displayInfo() override {
        std::cout << "Unregistered User: " << name << std::endl;
    }
};

#endif
