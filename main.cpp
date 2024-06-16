
#include <iostream>
#include "include/Postacie.h"
#include "include/Przedmioty.h"
#include "include/Struktury.h"
#include "include/Pojazdy.h"

void Lab5();

void showMenu();

using namespace std;

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    int showMenu = true;
    while (showMenu){
        cout << "//////////////////////////\n/////MENU//////\n" ;
        cout << "1. Graj\n";
        cout << "2. Sprawdz zadania z zajec\n";
        cout << "3. Przeprowadz testy jednostkowe\n";
        cout << "4. Dodaj swoją frakacje\n";
        cout << "5. Wyjdz\n";
        int userNr;
        cin>>userNr;
        switch(userNr){
            case(1):
                break;
            case(2):
                Lab5();
                break;
            case(3):
                showMenu = false;
                break;
            case(4):
                break;
            case(5):
                exit(1);
            default:
                cout<<"Podaj poprawną wartość\n";
                break;
        }
    }
}

void Lab5() {
    auto* bohater = new Bohater("Archibald", 1, 100, 10, 5, 0, 500);
    auto* potwor = new Potwor("Goblin", 1, 50, 5, 2);
    auto* bron = new Bron("Miecz", 100, 10);
    auto* zbroja = new Zbroja("Zbroja Skorzana", 50, 5);
    auto* miasto = new Miasto("Steadwick", 1, 1000, 5000);
    auto* zamek = new Zamek("Zamek Steadwick", 1, 500, 2000, bohater);
    auto* kopalnia = new Kopalnia("Kopalnia Zlota", 1, 100, 1000, 100);
    auto* gildia = new Gildia("Gildia Magow", 1);
    auto* zwierze = new Zwierze("Wilk", 7, 100, "Psowaty");
    auto* karoca = new Karoca("Archibald", "Arabski", 2000, 3000);

    Bron bron1("Miecz", 100, 50);
    Bron bron2("Topór", 80, 40);
    Bron bron3 = bron1 + bron2;

    Zbroja zbroja1("Zbroja Skórzana", 50, 20);
    Zbroja zbroja2("Zbroja Płytowa", 100, 50);
    Zbroja zbroja3 = zbroja2 - zbroja1;

    Bohater bohater2("Rycerz", 1, 100, 20, 10, 0, 0);
    bohater2 += 50;

    Potwor potwor2("Ork", 2, 80, 15, 5);
    potwor2 -= 30;

    char literaGatunku = (*zwierze)[0];

    bohater->zwiekszPoziom();
    bohater->zwiekszPunktyDoswiadczenia(100);
    bohater->zwiekszZloto(200);
    potwor->przyjmijObrazenia(20);
    miasto->zwiekszPopulacje(500);
    miasto->zwiekszZloto(1000);
    zamek->dodajJednostke(potwor);
    kopalnia->zwiekszProdukcjeZlota(50);
    gildia->przedstaw();
    zwierze->przedstaw();
    karoca->zwiekszPrzebieg(20);
    bohater->przedstaw();
    potwor->przedstaw();
    miasto->przedstaw();
    zamek->przedstaw();
    kopalnia->przedstaw();
    karoca->przedstaw();

    delete bohater;
    delete potwor;
    delete bron;
    delete zbroja;
    delete miasto;
    delete zamek;
    delete kopalnia;
    delete gildia;
    delete zwierze;
    delete karoca;
}
