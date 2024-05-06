#ifndef KINDERGARTEN_H
#define KINDERGARTEN_H

#include "school.h"

class Kindergarten : public School {
private:
    int teacherCount;

public:
    Kindergarten(const string& n, const string& addr, int teachers);
    void PrintInfo() const;
};

#endif // KINDERGARTEN_H
