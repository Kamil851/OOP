#pragma once
#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "school.h"

class University : public School {
private:
    int faculties;

public:
    University(const string& n, const string& addr, int fac);
    void PrintInfo() const;
};

#endif // UNIVERSITY_H
