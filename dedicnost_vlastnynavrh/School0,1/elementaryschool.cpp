#include "elementaryschool.h"
#include <iostream>

ElementarySchool::ElementarySchool(const string& n, const string& addr, int grades) : School(n, addr), gradeLevels(grades) {}

void ElementarySchool::PrintInfo() const {
    School::PrintInfo();
    cout << "Roky studia: " << gradeLevels << endl;
}
