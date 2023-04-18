#ifndef FABRYKASTUDENTOW_H
#define FABRYKASTUDENTOW_H

#include "../FabrykaOsob/FabrykaOsob.h"
#include "../Student/Student.h"

using namespace std;

class FabrykaStudentow: public FabrykaOsob{
    public:
        Student* utworz(string imie, string nazwisko, string dataUrodzenia);
};

#endif