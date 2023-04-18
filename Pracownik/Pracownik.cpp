#include "Pracownik.h"
#include <iostream>
#include <algorithm>

using namespace std;

Pracownik::Pracownik(){cout<<"Pracownik konstruktor"<<endl;}
Pracownik::~Pracownik(){delete imie;}
Pracownik::Pracownik(string imie, string nazwisko, string dataurodzenia){
    this->imie = new string;
    *this->imie = imie;
    this->nazwisko = nazwisko;
    this->dataurodzenia = dataurodzenia;
}

Pracownik::Pracownik(const Pracownik &pracownik) : Osoba(*pracownik.imie, pracownik.nazwisko, pracownik.dataurodzenia){
    imie = new string(*pracownik.imie);
    this->nazwisko = pracownik.nazwisko;
    this->dataurodzenia = pracownik.dataurodzenia;
    this->przedmioty = pracownik.przedmioty;
}

Pracownik::Pracownik(Pracownik&& pracownik) : Pracownik(*pracownik.imie, pracownik.nazwisko, pracownik.dataurodzenia){
    this->imie = pracownik.imie;
    pracownik.imie = NULL;
    this->nazwisko = pracownik.nazwisko;
    this->przedmioty = pracownik.przedmioty;
}

void Pracownik::dodawanieprzedmiotu(string nazwaPrzedmiotu){
    if (find(przedmioty.begin(), przedmioty.end(), nazwaPrzedmiotu) != przedmioty.end()){
        cout << nazwaPrzedmiotu + " jest juz na liscie przedmiotow!";
    }
    else{
        przedmioty.push_back(nazwaPrzedmiotu);
    }
}

void Pracownik::usuwanieprzedmiotu(string nazwaPrzedmiotu){
    przedmioty.erase(remove(przedmioty.begin(), przedmioty.end(), nazwaPrzedmiotu), przedmioty.end());
}

vector <string> Pracownik::getprzedmioty(){
    return przedmioty;
}

void Pracownik::przedstaw(){
    cout << "Przedstawianie: " << endl;
    cout << "Imie:" + *this->imie + "\n"<< endl;
    cout << "Nazwisko:" + this->nazwisko + "\n" << endl;
    cout << "Data urodzenia:" + this->dataurodzenia + "\n" << endl;
}


