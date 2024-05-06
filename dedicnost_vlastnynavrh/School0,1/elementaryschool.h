#pragma once
#ifndef ELEMENTARYSCHOOL_H
#define ELEMENTARYSCHOOL_H

#include "school.h"

class ElementarySchool : public School {
private:
    int gradeLevels;

public:
    ElementarySchool(const string& n, const string& addr, int grades);
    void PrintInfo() const;
};

#endif // ELEMENTARYSCHOOL_H
