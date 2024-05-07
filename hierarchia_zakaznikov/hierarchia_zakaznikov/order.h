#pragma once
#ifndef ORDER_H
#define ORDER_H

#include "customer.h"
#include "product.h"

class OrderItem {
private:
    Product* product;
    int quantity;
public:
    OrderItem(Product* _product, int _quantity) : product(_product), quantity(_quantity) {}
    void displayInfo();
};

class Order {
private:
    Customer* customer;
    OrderItem* items[10];
    int itemCount;
public:
    Order(Customer* _customer) : customer(_customer), itemCount(0) {}
    void addItem(OrderItem* item);
    void displayInfo();
};

#endif
