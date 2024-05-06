#include "university.h"
#include <iostream>

University::University(const string& n, const string& addr, int fac) : School(n, addr), faculties(fac) {}

void University::PrintInfo() const {
    School::PrintInfo();
    cout << "Fakulta: " << faculties << endl;
}
