#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometric_object.h"

class Circle : public GeometricObject {
private:
    double radius;
public:
    Circle(double r);
    double Area() const override;
    double Perimeter() const override;
};

#endif // CIRCLE_H
