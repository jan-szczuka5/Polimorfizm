#include "Osoba.h"
#include <iostream>
#include <vector>
#include <sstream>

Osoba::Osoba(){cout<<"Osoba konstruktor"<<endl;}

Osoba::Osoba(string imie, string nazwisko,  string dataurodzenia){
    this->imie = new string;
    *this->imie = imie;
    this->nazwisko = nazwisko;
    this-> dataurodzenia = dataurodzenia;
}

Osoba::~Osoba() {delete imie;}

Osoba::Osoba(const Osoba &osoba){
    imie = new string(*osoba.imie);
    this->nazwisko = osoba.nazwisko;
    this->dataurodzenia = osoba.dataurodzenia;
}

Osoba::Osoba(Osoba&& osoba){
    this->imie = osoba.imie;
    osoba.imie = NULL;
    this->nazwisko = osoba.nazwisko;
}

Osoba::Osoba(string imie){*this->imie = imie;}

void Osoba::setimie(string imie){
    *this->imie = imie;
}

string Osoba::getimie(){
    return *this->imie;
}

void Osoba::setnazwisko(string nazwisko){
    this->nazwisko = nazwisko;
}

string Osoba::getnazwisko(){
    return nazwisko;
}

void Osoba::setdata(string dataurodzenia){
    bool sprawdzanie = sprawdzaniedaty(dataurodzenia);
    if (sprawdzanie == true){
        this->dataurodzenia = dataurodzenia;
    }
    else{
        cout << "Blad w dacie urodzenia." << endl;
    }
}

string Osoba::getdata(){
    return dataurodzenia;
}

void Osoba::przedstaw(){
    cout << "Imie: " + *this->imie + "\n";
    cout << "Nazwisko: " + this->nazwisko + "\n";
    cout << "Data urodzenia: " + this->dataurodzenia + "\n";
}

vector<int> split(string data, char delimiter){
    vector<int> result;
    stringstream ss (data);
    string item;

    while(getline(ss, item, delimiter)){
        result.push_back(stoi(item));
    }
    return result;
}

bool Osoba::sprawdzaniedaty(string data){
    char delimiter = '.';
    vector<int> splitted = split(data, delimiter);
    bool ans = true;

    if (splitted[0] < 1 || splitted[0] > 31){
        ans = false;
    }
    if (splitted[1] < 1 || splitted[1] > 12){
        ans = false;
    }
    if (splitted[2] < 1 || splitted[2] > 2021){
        ans = false;
    }
    return ans;
}