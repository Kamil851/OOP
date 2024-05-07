#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricObject.h"


class Rectangle : public GeometricObject {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h);

    
    double area() const override;
    double perimeter() const override;
};

#endif // RECTANGLE_H
