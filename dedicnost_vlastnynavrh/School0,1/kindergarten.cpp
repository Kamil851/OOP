#include "kindergarten.h"
#include <iostream>

Kindergarten::Kindergarten(const string& n, const string& addr, int teachers) : School(n, addr), teacherCount(teachers) {}

void Kindergarten::PrintInfo() const {
    School::PrintInfo();
    cout << "pocet ucitelov: " << teacherCount << endl;
}
