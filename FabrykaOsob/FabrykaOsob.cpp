#include "FabrykaOsob.h"
#include <iostream>

#include "../Osoba/Osoba.h"

Osoba* FabrykaOsob::utworz(string imie, string nazwisko, string dataUrodzenia){
    Osoba* osobaObiekt = new Osoba(imie, nazwisko, dataUrodzenia);
    return osobaObiekt;
}

