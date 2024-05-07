#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "geometric_object.h"

class Square : public GeometricObject {
private:
    double side;
public:
    Square(double s);
    double Area() const override;
    double Perimeter() const override;
};

#endif // SQUARE_H
