#include "include/Postacie.h"
#include "include/Przedmioty.h"
#include "include/Struktury.h"
#include "include/Pojazdy.h"
#include "src/Test/BoardTest.cpp"
#include "src/Test/CreatureTest.cpp"
#include "src/Test/CreatureStatisticsTest.cpp"
#include "src/Test/PointTest.cpp"
#include "src/Test/RangeTest.cpp"
#include "src/Test/CreatureTurnQueueTest.cpp"
#include <iostream>
#include <string>


void runTests();
void labolatoria();
void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void showMenu();
using namespace std;

int main() {
    showMenu();
    return 0;
}
void runTests() {
    try {
        BoardTest::runAllTests();
        CreatureTest::runAllTests();
        CreatureStatisticsTest::runAllTests();
        PointTest::runAllTests();
        RangeTest::runAllTests();
        CreatureTurnQueueTest::runAllTests();
        cout << "Wszystkie testy przeszly pomyslnie!" << endl;
    } catch (const exception& e) {
        cout << "Wystapil blad podczas testow: " << e.what() << endl;

    }
}
void showMenu() {
    int showMenu = true;
    while (showMenu){
        cout << "//////////////////////////\n/////MENU//////\n" ;
        cout << "1. Graj\n";
        cout << "2. Sprawdz zadania z zajec\n";
        cout << "3. Przeprowadz testy jednostkowe\n";
        cout << "4. Dodaj swoja frakacje\n";
        cout << "5. Wyjdz\n";
        int userNr;
        cin>>userNr;
        switch(userNr){
            case(1):
                showMenu = false;
                break;
            case(2):
                labolatoria();
                break;
            case(3):
                cout << "////Testy////\n";
                runTests();
                cout<<"\n\n\n";
                break;
            case(4):
                break;
            case(5):
                exit(1);
            default:
                cout<<"Podaj poprawna wartosc\n";
                break;
        }
    }
}
void lab1(){
    cout<<"Lab 1\n";
    auto* bohater = new Bohater("Archibald", 1, 100, 10, 5, 0, 500);
    auto* potwor = new Potwor("Goblin", 1, 50, 5, 2);
    auto* bron = new Bron("Miecz", 100, 10);
    auto* zbroja = new Zbroja("Zbroja Skorzana", 50, 5);
    auto* zamek = new Zamek("Zamek Steadwick", 1, 500, 2000, bohater);
    auto* kopalnia = new Kopalnia("Kopalnia Zlota", 1, 100, 1000, 100);
    auto* gildia = new Gildia("Gildia Magow", 1);
    auto* zwierze = new Zwierze("Wilk", 7, 100, "Psowaty");
    auto* karoca = new Karoca("Archibald", "Arabski", 2000, 3000);

    zbroja->przedstaw();
    bohater->przedstaw();
    potwor->przedstaw();
    zamek->przedstaw();
    kopalnia->przedstaw();
    karoca->przedstaw();
    gildia->przedstaw();
    zwierze->przedstaw();

    bohater->zwiekszPoziom();
    bohater->zwiekszPunktyDoswiadczenia(100);
    bohater->zwiekszZloto(200);
    potwor->przyjmijObrazenia(20);
    zamek->dodajJednostke(potwor);
    kopalnia->zwiekszProdukcjeZlota(50);
    karoca->zwiekszPrzebieg(20);


    delete bohater;
    delete potwor;
    delete bron;
    delete zbroja;
    delete zamek;
    delete kopalnia;
    delete gildia;
    delete zwierze;
    delete karoca;
}
void lab2(){
    cout<<"Lab 2\n";
    Postac postac("Postac", 1, 100, 10, 5);
    Bohater bohater("Bohater", 1, 100, 15, 10, 0, 0);
    Potwor potwor("Potwor", 1, 50, 8, 3);
    Zwierze zwierze("Zwierze", 1, 30, "Kot");

    // Wywolanie zaprzyjaznionych metod
    cout << "Stan poczatkowy:" << endl;
    postac.przedstaw();
    bohater.przedstaw();
    potwor.przedstaw();
    zwierze.przedstaw();

    cout << endl;

    cout << "Bohater zwieksza punkty ataku Postaci o 5:" << endl;
    bohater.zwiekszPunktyAtakuPostaci(postac, 5);
    postac.przedstaw();

    cout << endl;

    cout << "Bohater zwieksza punkty zycia Zwierzecia o 10:" << endl;
    bohater.zwiekszPunktyZyciaZwierzecia(zwierze, 10);
    zwierze.przedstaw();

    cout << endl;

    cout << "Potwor zmniejsza punkty obrony Postaci o 2:" << endl;
    potwor.zmniejszPunktyObronyPostaci(postac, 2);
    postac.przedstaw();

    cout << endl;

    cout << "Postac zwieksza punkty zycia Potwora o 20:" << endl;
    postac.zwiekszPunktyZyciaPotwora(potwor, 20);
    potwor.przedstaw();

    cout << endl;

    cout << "Zwierze zwieksza poziom Bohatera:" << endl;
    zwierze.zwiekszPoziomBohatera(bohater);
    bohater.przedstaw();
}
void lab3(){
    cout<<"Lab 3\n";
    auto* bohater = new Bohater("Archibald", 1, 100, 10, 5, 0, 500);
    auto* zamek = new Zamek("Kaer Morhen", 1, 100, 1000, bohater);
    auto* kopalnia = new Kopalnia("Kopalnia Zlota", 1, 50, 500, 10);
    auto* gildia = new Gildia("Gildia Magow", 1);

    zamek->przedstaw();
    kopalnia->przedstaw();
    gildia->przedstaw();

    zamek->zmienWartosc(2);
    zamek->zwiekszPopulacje(50);
    zamek->zwiekszZloto(500);

    kopalnia->zmienWartosc(2);
    kopalnia->zwiekszProdukcjeZlota(5);

    gildia->zwiekszPoziom();

    zamek->przedstaw();
    kopalnia->przedstaw();
    gildia->przedstaw();

    delete bohater;
    delete zamek;
    delete kopalnia;
    delete gildia;
}
void lab4(){
    cout<<"Lab 4\n";
    Karoca karoca("Jan Kowalski", "Bryczka", 2010, 5000);
    cout << "Informacje o obiektach:" << endl;
    karoca.przedstaw();
    cout << "Wlasciciel: " << karoca.getWlasciciel() << endl;
    cout << "Typ: " << karoca.getTyp() << endl;

    cout << "\nWywolanie metod:" << endl;
    karoca.jedzDoPrzodu();
    karoca.skrecWLewo();
    karoca.jedzDoTylu();
    karoca.skrecWPrawo();
    karoca.zatrzymajSie();
    karoca.wykonajPrzeglad();

    karoca.zmienTyp("Powoz");
    karoca.zwiekszPrzebieg(1000);

    cout << "\nZaktualizowane informacje:" << endl;
    karoca.przedstaw();
    cout << "Wlasciciel: " << karoca.getWlasciciel() << endl;
    cout << "Typ: " << karoca.getTyp() << endl;

}
void lab5(){
    cout << "Lab 5\n";
    auto* bohater = new Bohater("Archibald", 1, 100, 10, 5, 0, 500);
    auto* potwor = new Potwor("Goblin", 1, 50, 5, 2);
    auto* bron = new Bron("Miecz", 100, 10);
    auto* zbroja = new Zbroja("Zbroja Skorzana", 50, 5);

    Bron bron1("Miecz", 100, 50);
    Bron bron2("Topor", 80, 40);
    Bron bron3 = bron1 + bron2;

    Zbroja zbroja1("Zbroja Skorzana", 50, 20);
    Zbroja zbroja2("Zbroja Plytowa", 100, 50);
    cout << "Punkty obrony zbroi 1 przed odjeciu: " << zbroja1.getPunktyObrony() << endl;
    cout << "Punkty obrony zbroi 2 przed odjeciu: " << zbroja2.getPunktyObrony() << endl;
    Zbroja zbroja3 = zbroja2 - zbroja1;
    cout << "Punkty obrony zbroi 3 po odjeciu: " << zbroja3.getPunktyObrony() << endl;

    Bohater bohater2("Rycerz", 1, 100, 20, 10, 0, 0);
    cout << "Poczatkowe punkty bohatera: " << bohater2.getPunktyDoswiadczenia() << endl;
    bohater2 += 50;
    cout << "Punkty bohatera po dodaniu 50: " << bohater2.getPunktyDoswiadczenia() << endl;

    Potwor potwor2("Ork", 2, 80, 15, 5);
    cout << "Punkty zycia bohatera przed walka z potworem: " << bohater2.getPunktyZycia() << endl;
    potwor2 -= 30;
    cout << "Punkty zycia potwora po otrzymaniu obrazen: " << potwor2.getPunktyZycia() << endl;

    delete bohater;
    delete potwor;
    delete bron;
    delete zbroja;
}
void labolatoria() {
    lab1();
    lab2();
    lab3();
    lab4();
    lab5();
}
