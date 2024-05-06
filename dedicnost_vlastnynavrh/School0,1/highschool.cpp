#include "highschool.h"
#include <iostream>

HighSchool::HighSchool(const string& n, const string& addr) : School(n, addr), courseCount(0) {}

void HighSchool::AddCourse(const string& course) {
    if (courseCount < 10) {
        courses[courseCount++] = course;
    }
}

void HighSchool::PrintInfo() const {
    School::PrintInfo();
    cout << "kurz:" << std::endl;
    for (int i = 0; i < courseCount; ++i) {
        cout << "- " << courses[i] << endl;
    }
}
