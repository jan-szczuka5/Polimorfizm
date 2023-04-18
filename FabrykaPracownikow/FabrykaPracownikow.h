#ifndef FABRYKAPRACOWNIKOW_H
#define FABRYKAPRACOWNIKOW_H

#include "../FabrykaOsob/FabrykaOsob.h"
#include "../Pracownik/Pracownik.h"

using namespace std;

class FabrykaPracownikow: public FabrykaOsob{
    public:
        Pracownik* utworz(string imie, string nazwisko, string dataUrodzenia);
};

#endif