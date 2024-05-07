#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

using namespace std;


void printInfo(const GeometricObject& obj) {
    cout << "Area: " << obj.area() << endl;
    cout << "Perimeter: " << obj.perimeter() << endl;
}

int main() {
    Rectangle rectangle(5, 4);
    Circle circle(3);

    cout << "Rectangle:" << endl;
    printInfo(rectangle);

    cout << "\nCircle:" << endl;
    printInfo(circle);

    return 0;
}
