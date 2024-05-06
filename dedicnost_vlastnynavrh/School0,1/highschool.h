#pragma once
#ifndef HIGHSCHOOL_H
#define HIGHSCHOOL_H

#include "school.h"

class HighSchool : public School {
private:
    string courses[10];
    int courseCount;

public:
    HighSchool(const string& n, const string& addr);
    void AddCourse(const string& course);
    void PrintInfo() const;
};

#endif // HIGHSCHOOL_H
