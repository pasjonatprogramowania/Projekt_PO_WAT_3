#ifndef POSTACIE_H
#define POSTACIE_H

#include <iostream>
#include "Istoty.h"

using namespace std;

class Postac : public Stworzenie {
protected:
    int punktyAtaku;
    int punktyObrony;

public:
    Postac(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony);
    void zwiekszPoziom() override;
    void przyjmijObrazenia(int obrazenia) override;
    int getPoziom() override;
    int getPunktyZycia() override;
    int getPunktyAtaku();
    int getPunktyObrony();
    void przedstaw() override;
    friend class Bohater;
    friend class Potwor;

    // Przeciążenie operatora porównania <
    bool operator<(const Postac& other) const;
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
    void przedstaw() override;

    // Przeciążenie operatora dodawania +=
    Bohater& operator+=(int punktyDoswiadczenia);
};

class Potwor : public Postac {
public:
    Potwor(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony);
    void przedstaw() override;

    // Przeciążenie operatora odejmowania -=
    Potwor& operator-=(int punktyZycia);
};

class Zwierze : public Stworzenie {
private:
    string gatunek;

public:
    Zwierze(string imie, int poziom, int punktyZycia, string gatunek);
    void przedstaw() override;
    int getPoziom() override;
    int getPunktyZycia() override;
    void zwiekszPoziom() override;
    void przyjmijObrazenia(int obrazenia) override;

    // Przeciążenie operatora indeksowania []
    char operator[](int index) const;
};

#endif // POSTACIE_H