#include "school.h"
#include <iostream>

School::School(const string& n, const string& addr) : name(n), address(addr), studentCount(0) {}

void School::AddStudent() {
    studentCount++;
}

void School::RemoveStudent() {
    if (studentCount > 0)
        studentCount--;
}

void School::PrintInfo() const {
    cout << "Nazov skoly: " << name << endl;
    cout << "Adresa: " << address << endl;
    cout << "pocet studentov: " << studentCount << endl;
}

