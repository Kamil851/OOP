#include <iostream>
#include "constants.h"
#include "geometric_object.h"
#include "square.h"
#include "circle.h"

int main() {
    const int numOfObjects = 2;
    GeometricObject* objects[numOfObjects];

    objects[0] = new Square(5.0);
    objects[1] = new Circle(3.0);

    for (int i = 0; i < numOfObjects; ++i) {
        std::cout << "Object " << i + 1 << " - Area: " << objects[i]->Area() << ", Perimeter: " << objects[i]->Perimeter() << std::endl;
    }

    for (int i = 0; i < numOfObjects; ++i) {
        delete objects[i];
    }

    return 0;
}
