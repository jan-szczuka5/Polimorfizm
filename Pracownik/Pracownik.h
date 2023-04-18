#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <string>
#include <map>
#include <vector>
#include "../Osoba/Osoba.h"

using namespace std;

class Pracownik: public Osoba{
    private:
        vector <string> przedmioty;
    public:
        Pracownik();
        ~Pracownik();
        Pracownik(Pracownik&& pracownik);
        Pracownik(const Pracownik &pracownik);
        Pracownik(string imie, string nazwisko, string dataurodzenia);
        void dodawanieprzedmiotu(string nazwaPrzedmiotu);
        void usuwanieprzedmiotu(string nazwaPrzedmiotu);
        vector <string> getprzedmioty();
        void przedstaw();
    
};

#endif