#ifndef FABRYKAOSOB_H
#define FABRYKAOSOB_H

#include "../Osoba/Osoba.h"

using namespace std;

class FabrykaOsob{
    public:
        virtual Osoba* utworz(string name, string surname, string dateOfBirth) = 0;
};

#endif