#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeometricObject.h"


class Circle : public GeometricObject {
private:
    double radius;
public:
    Circle(double r);

 
    double area() const override;
    double perimeter() const override;
};

#endif // CIRCLE_H
