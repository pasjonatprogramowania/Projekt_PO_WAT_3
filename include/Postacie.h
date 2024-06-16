#ifndef POSTACIE_H
#define POSTACIE_H

#include <iostream>
#include <string>
#include "Istoty.h"

using namespace std;

class Bohater;
class Potwor;
class Zwierze;

class Postac : public Stworzenie {
public:
    Postac(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony);
    void zwiekszPoziom();
    void przyjmijObrazenia(int obrazenia);
    int getPoziom();
    int getPunktyZycia();
    int getPunktyAtaku();
    int getPunktyObrony();
    void przedstaw();
    bool operator<(const Postac& other) const;

    void zwiekszPunktyZyciaPotwora(Potwor& potwor, int punkty);

    int punktyAtaku;
    int punktyObrony;
};

class Potwor : public Postac {
public:
    Potwor(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony);
    void przedstaw();
    Potwor& operator-=(int punktyZycia);

    static void zmniejszPunktyObronyPostaci(Postac& postac, int punkty);
};

class Zwierze : public Stworzenie {
private:
    string gatunek;

public:
    Zwierze(string imie, int poziom, int punktyZycia, string gatunek);
    void przedstaw();
    int getPoziom();
    int getPunktyZycia();
    void zwiekszPoziom();
    void przyjmijObrazenia(int obrazenia);
    char operator[](int index) const;

    void zwiekszPoziomBohatera(Bohater& bohater);
};

class Bohater : public Postac {
private:
    int punktyDoswiadczenia;
    int zloto;

public:
    Bohater(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony, int punktyDoswiadczenia, int zloto);
    void zwiekszPunktyDoswiadczenia(int punkty);
    void zwiekszZloto(int ilosc);
    int getPunktyDoswiadczenia();
    int getZloto();
    void przedstaw();
    Bohater& operator+=(int punktyDoswiadczenia);

    friend void Zwierze::zwiekszPoziomBohatera(Bohater& bohater);
    void zwiekszPunktyAtakuPostaci(Postac& postac, int punkty);
    void zwiekszPunktyZyciaZwierzecia(Zwierze& zwierze, int punkty);
};

#endif
