#include <iostream>
#include "./Osoba/Osoba.h"
#include "./Student/Student.h"
#include "./Pracownik/Pracownik.h"
#include "./FabrykaOsob/FabrykaOsob.h"
#include "./FabrykaStudentow/FabrykaStudentow.h"
#include "./FabrykaPracownikow/FabrykaPracownikow.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

void foo(Osoba &os);
void bar(Osoba *os);

int main(){

    Osoba osoba1{"Marcin", "Nowak", "01.01.2004"};
    osoba1.przedstaw();

    Student student1("Albert", "Nowak", "26.04.1998");
    student1.dodawanieoceny(3, "Matematyka");
    student1.dodawanieoceny(4, "WF");
    student1.dodawanieoceny(4, "Matematyka");
    
    vector<int> ocenyMatematyka = student1.getocena("Matematyka");
    for(int i = 0; i < ocenyMatematyka.size(); ++i){
        cout << ocenyMatematyka[i];
        cout << " ";
    }
    cout << endl;    
    
    
    Pracownik pracownik1("Jakub", "Wójcik", "31.12.1982");

    pracownik1.dodawanieprzedmiotu("Matematyka");
    pracownik1.dodawanieprzedmiotu("Fizyka");

    for(int i = 0; i < pracownik1.getprzedmioty().size(); ++i){
        cout << pracownik1.getprzedmioty()[i] << endl;
    }

    pracownik1.usuwanieprzedmiotu("Fizyka");

    for(int i = 0; i < pracownik1.getprzedmioty().size(); ++i){
        cout << pracownik1.getprzedmioty()[i] << endl;
    }

    cout<<"Osoba:"<<endl;
    foo(osoba1);
    bar(&osoba1);
    cout<<"Student:"<<endl;
    foo(student1);
    bar(&student1);
    cout<<"Pracownik:"<<endl;
    foo(pracownik1);
    bar(&pracownik1);

    Pracownik pracownik0(move(pracownik1));
    cout<<"Konstruktor przenoszacy"<<"\n";
    pracownik0.przedstaw();


    map<string, FabrykaOsob*> map_fabryki;
    map_fabryki["student"] = new FabrykaStudentow();
    map_fabryki["pracownik"] = new FabrykaPracownikow();

    vector<Osoba*> osoba_v; 
    
    while(true){
        cout<<"Wybierz co chcesz zrobic poprzez wpisanie odpowiedniego slowa:"<<endl;
        cout<<"student - dodac studenta"<<endl;
        cout<<"pracownik - dodac pracownika"<<endl;
        cout<<"wyswietl - wyswietlic wlasnosci obiektu"<<endl;
        cout<<"wyjscie - zakonczyc program"<<endl;

        string wybor;

        cin>>wybor;
        
        string imie;
        string nazwisko;
        string dataUrodzenia;

        if (wybor == "student"){
            cout<<"Podaj imie, nazwisko i date urodzenia"<<endl;
            cin>>imie>>nazwisko>>dataUrodzenia;
            osoba_v.push_back(map_fabryki[wybor]->utworz(imie, nazwisko, dataUrodzenia));
        }
        if (wybor=="pracownik"){
            cout<<"Podaj imie, nazwisko i date urodzenia"<<endl;
            cin>>imie>>nazwisko>>dataUrodzenia;
            osoba_v.push_back(map_fabryki[wybor]->utworz(imie, nazwisko, dataUrodzenia));
        }
        if (wybor == "wyswietl"){
            for(int i = 0; i != osoba_v.size(); ++i){
                osoba_v[i]->przedstaw();
            }
        }
        if (wybor == "wyjscie"){
            break;
        }
    }
    return 0;
}

void foo(Osoba &os){
    os.przedstaw();
}

void bar(Osoba *os){
    os->przedstaw();
}

// 12. Przy wywołaniu metody przedstaw nie ma znaczenia czy jest to Osoba, Student czy pracownik. Każde wywołanie jest odwołaniem do klasy Osoba.
// 14. Dodanie specyfikatora virtual spowodowało, że metoda funkcja odnosi się do każdej klasy osobno.
// 16. Nie można skompilować projektu. Nowa definicja przedstaw tworzy klasę abstrakcyjną, nie można dla niej tworzyć obiektów.
// 19. Pamięć została zwolniona. Program działa poprawnie.
// 20. Po dodaniu specyfikatora virtual pamięć będzie zwalniana dla klasy bazowej i pochodniej.
// 30. Kompilator uruchamia wersję konstruktora klasy bazowej, ponieważ konstruktor klasy pochodnej uruchamia się po konstruktorze klasy bazowej.