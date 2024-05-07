#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
protected:
    std::string productName;
public:
    Product(std::string _productName) : productName(_productName) {}
    virtual void displayInfo() = 0;
};

class MobilePhone : public Product {
public:
    MobilePhone(std::string _productName) : Product(_productName) {}
    void displayInfo() override {
        std::cout << "Mobile Phone: " << productName << std::endl;
    }
};

class Notebook : public Product {
public:
    Notebook(std::string _productName) : Product(_productName) {}
    void displayInfo() override {
        std::cout << "Notebook: " << productName << std::endl;
    }
};

class Tablet : public Product {
public:
    Tablet(std::string _productName) : Product(_productName) {}
    void displayInfo() override {
        std::cout << "Tablet: " << productName << std::endl;
    }
};

#endif
        