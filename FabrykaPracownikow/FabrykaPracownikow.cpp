#include "FabrykaPracownikow.h"
#include <iostream>

Pracownik* FabrykaPracownikow::utworz(string imie, string nazwisko, string dataUrodzenia){
    Pracownik* pracownikObiekt = new Pracownik(imie, nazwisko, dataUrodzenia);
    return pracownikObiekt;
}