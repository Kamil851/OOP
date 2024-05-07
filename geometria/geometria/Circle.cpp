#include "Circle.h"

Circle::Circle(double r) : radius(r) {}


double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}
