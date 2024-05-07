#pragma once
#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

const double PI = 3.14159265358979323846;

class GeometricObject {
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual ~GeometricObject() {}
};

#endif // GEOMETRIC_OBJECT_H
