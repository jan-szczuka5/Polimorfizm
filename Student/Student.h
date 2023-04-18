#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>
#include <vector>
#include "../Osoba/Osoba.h"

using namespace std;

class Student: public Osoba{
    private:
        map<string, vector<int> > oceny;
    public:
        Student();
        ~Student();
        Student(Student&& student);
        Student(const Student &student);
        Student(string imie, string nazwisko, string dataurodzenia);

        vector<int> getocena(string przedmiot);
        void dodawanieoceny(int ocena, string przedmiot);
        void wyswietloceny();
        void przedstaw();
};


#endif