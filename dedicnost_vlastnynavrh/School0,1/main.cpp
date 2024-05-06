#include "kindergarten.h"
#include "elementaryschool.h"
#include "highschool.h"
#include "university.h"
#include <iostream>

int main() {
    Kindergarten k("Stastne deti", "123 ABC ulica", 5);
    k.AddStudent();
    k.AddStudent();
    k.PrintInfo();
    cout << endl;

    ElementarySchool e("Zakladna skola", "456 XYZ cesta", 6);
    e.AddStudent();
    e.AddStudent();
    e.PrintInfo();
    cout << endl;

    HighSchool h("Gymnazium Krala", "789 Hlavna cesta");
    h.AddStudent();
    h.AddStudent();
    h.AddCourse("Matematika");
    h.AddCourse("Fyzika");
    h.PrintInfo();
    cout << endl;

    University u("Technicka univerzita", "101 Univerzitny bulvar", 8);
    u.AddStudent();
    u.AddStudent();
    u.PrintInfo();

    return 0;
}
