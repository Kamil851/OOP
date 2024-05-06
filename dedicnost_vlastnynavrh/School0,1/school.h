#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
using namespace std;

class School {
protected:
    string name;
    string address;
    int studentCount;

public:
    School(const string& n, const string& addr);
    void AddStudent();
    void RemoveStudent();
    void PrintInfo() const;
};

#endif // SCHOOL_H

