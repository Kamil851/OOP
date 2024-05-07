#include "square.h"

Square::Square(double s) : side(s) {}

double Square::Area() const {
    return side * side;
}

double Square::Perimeter() const {
    return 4 * side;
}
