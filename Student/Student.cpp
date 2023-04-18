#include "Student.h"
#include <iostream> 
#include <vector>
#include <map>

Student::Student(){cout<<"Konstruktor Student"<<endl;}
Student::~Student(){delete imie;}
Student::Student(string imie, string nazwisko, string dataurodzenia){
    this->imie = new string;
    *this->imie = imie;
    this->nazwisko = nazwisko;
    this->dataurodzenia = dataurodzenia;
}

Student::Student(const Student &student) : Osoba(*student.imie, student.nazwisko, student.dataurodzenia){
    imie = new string(*student.imie);
    this->nazwisko = student.nazwisko;
    this->dataurodzenia = student.dataurodzenia;
    this->oceny = student.oceny;
}

Student::Student(Student&& student) : Osoba(*student.imie, student.nazwisko, student.dataurodzenia){
    this->imie = student.imie;
    student.imie = NULL;
    this->nazwisko = student.nazwisko;
    this->oceny = student.oceny;
}

void Student::dodawanieoceny(int ocena, string przedmiot){
    if (ocena >= 1&& ocena<=5){
    this->oceny[przedmiot].push_back(ocena);
    }
    else{
        cout<<"Podaj ocene od 1 do 5"<<endl;
    }
}

void Student::przedstaw(){
    cout<<"Imie:" + *this->imie + "\n";
    cout<<"Nazwisko:" + this->nazwisko + "\n";
    cout<<"Data urodzenia:" + this->dataurodzenia + "\n";
}

void Student::wyswietloceny(){
    for(auto itr = oceny.begin(); itr != oceny.end(); ++itr){
        cout<<(*itr).first;
        cout<<": ";
        for(int i = 0; i < (*itr).second.size(); ++i){
            cout << (*itr).second[i];
            cout << " ";
        }
        cout << endl;
    }
}
vector<int> Student::getocena(string przedmiot){
    if (this->oceny.find(przedmiot) == this->oceny.end()){
        cout << "Brak przedmiotu" <<endl;
    }
    else{
        return this->oceny[przedmiot];
    }

}

