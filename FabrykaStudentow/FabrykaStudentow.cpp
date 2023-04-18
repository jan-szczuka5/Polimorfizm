#include "Fabrykastudentow.h"
#include <iostream>

Student* FabrykaStudentow::utworz(string imie, string nazwisko, string dataUrodzenia){
    Student* studentObiekt = new Student(imie, nazwisko, dataUrodzenia);
    return studentObiekt;
}