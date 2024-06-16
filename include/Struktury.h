#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Postacie.h"
using namespace std;

class Obiekt {
protected:
    string nazwa;

public:
    Obiekt(string nazwa);
    virtual void przedstaw() = 0;
    string getNazwa();
};

class Struktura : public Obiekt {
protected:
    int poziom;

public:
    Struktura(string nazwa, int poziom);
    virtual void resetuj() = 0;
    int getPoziom();
    void zwiekszPoziom();
};

class Budynek : public Struktura {
public:
    Budynek(string nazwa, int poziom);
    void przedstaw() override;
    void resetuj() override;
};

class Zasoby : public Budynek {
protected:
    int zloto;

public:
    Zasoby(string nazwa, int poziom, int zloto);
    void przedstaw() override;
    void resetuj() override;
};

class ProdukcjaZasobow : public Zasoby {
protected:
    int produkcjaZlota;

public:
    ProdukcjaZasobow(string nazwa, int poziom, int zloto, int produkcjaZlota);
    void przedstaw() override;
    void resetuj() override;
};

class Miasto : public Zasoby {
protected:
    int populacja;

public:
    Miasto(string nazwa, int poziom, int populacja, int zloto);
    void zwiekszPopulacje(int ilosc);
    void zwiekszZloto(int ilosc);
    int getPopulacja();
    void przedstaw() override;
    void resetuj() override;
};

class Zamek : public Miasto {
    Bohater* wlasciciel;
    vector<Potwor*> jednostki;

public:
    Zamek(string nazwa, int poziom, int populacja, int zloto, Bohater* wlasciciel);
    void dodajJednostke(Potwor* jednostka);
    void przedstaw() override;
    string getNazwa() ;
    int getWartosc() ;
    void zmienWartosc(int wartosc) ;
};

class Kopalnia : public ProdukcjaZasobow {
public:
    Kopalnia(string nazwa, int poziom, int populacja, int zloto, int produkcjaZlota);
    void zwiekszProdukcjeZlota(int ilosc);
    int getProdukcjaZlota();
    void przedstaw() override;
    void resetuj();
    string getNazwa() ;
    int getWartosc() ;
    void zmienWartosc(int wartosc) ;
};

class Gildia : public Budynek {
public:
    Gildia(string nazwa, int poziom);
    void przedstaw() override;
};