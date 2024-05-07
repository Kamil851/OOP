#pragma once
#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

const double PI = 3.14159265358979323846;

class GeometricObject {
public:

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

#endif // GEOMETRIC_OBJECT_H
