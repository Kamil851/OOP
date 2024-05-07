#include "order.h"

void OrderItem::displayInfo() {
    product->displayInfo();
    std::cout << "Quantity: " << quantity << std::endl;
}

void Order::addItem(OrderItem* item) {
    if (itemCount < 10) {
        items[itemCount++] = item;
    }
    else {
        std::cout << "Cannot add more items to order." << std::endl;
    }
}

void Order::displayInfo() {
    customer->displayInfo();
    std::cout << "Order Items:" << std::endl;
    for (int i = 0; i < itemCount; ++i) {
        items[i]->displayInfo();
    }
}
