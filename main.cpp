#include <iostream>
#include "include/Postacie.h"
#include "include/Przedmioty.h"
#include "include/Struktury.h"
#include "include/Pojazdy.h"

using namespace std;

int main() {
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

    return 0;
}