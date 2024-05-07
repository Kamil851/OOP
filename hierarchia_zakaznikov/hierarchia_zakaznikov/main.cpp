#include <iostream>
#include "customer.h"
#include "product.h"
#include "order.h"

int main() {
    RegisteredUser user1("John Doe");
    UnregisteredUser user2("Jane Smith");

    MobilePhone phone1("iPhone 13");
    Notebook laptop1("Dell XPS 15");
    Tablet tablet1("iPad Pro");

    OrderItem item1(&phone1, 2);
    OrderItem item2(&laptop1, 1);
    OrderItem item3(&tablet1, 3);

    Order order1(&user1);
    order1.addItem(&item1);
    order1.addItem(&item2);

    Order order2(&user2);
    order2.addItem(&item3);

    std::cout << "Order 1:" << std::endl;
    order1.displayInfo();

    std::cout << "\nOrder 2:" << std::endl;
    order2.displayInfo();

    return 0;
}
