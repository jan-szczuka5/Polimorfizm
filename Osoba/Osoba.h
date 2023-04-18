#ifndef OSOBA_H
#define OSOBA_H
#include <string>

using namespace std;

class Osoba{
    protected:
        string* imie;
        string nazwisko;
        string dataurodzenia;
        bool sprawdzaniedaty(string data);
    public:
        Osoba();
        Osoba(string imie, string nazwisko, string dataurodzenia);
        ~Osoba();
        Osoba(Osoba&& osoba);
        Osoba(const Osoba &osoba);
        Osoba(string imie);
        void setimie(string imie);
        void setnazwisko(string nazwisko);
        void setdata(string dataurodzenia);
        string getimie();
        string getnazwisko();
        string getdata();

        virtual void przedstaw();

};

#endif