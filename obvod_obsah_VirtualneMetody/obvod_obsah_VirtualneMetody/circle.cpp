#include "circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::Area() const {
    return PI * radius * radius;
}

double Circle::Perimeter() const {
    return 2 * PI * radius;
}
