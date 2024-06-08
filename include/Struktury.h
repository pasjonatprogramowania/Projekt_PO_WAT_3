#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream>
#include <string>
#include <vector>
#include "Postacie.h"

using namespace std;

class Struktura {
protected:
    string nazwa;
    int poziom;

public:
    Struktura(string nazwa, int poziom);
    virtual ~Struktura() = default;
    virtual void przedstaw() = 0;
    virtual string getNazwa() = 0;
    virtual int getPoziom() = 0;
    virtual void zwiekszPoziom() = 0;
    virtual void resetuj() = 0;
};

class Miasto : public Struktura {
private:
    int populacja;
    int zloto;

public:
    Miasto(string nazwa, int poziom, int populacja, int zloto);
    void zwiekszPopulacje(int ilosc);
    void zwiekszZloto(int ilosc);
    int getPopulacja();
    int getZloto();
    string getNazwa() override;
    int getPoziom() override;
    void zwiekszPoziom() override;
    void resetuj() override;
    void przedstaw() override;
};

class Zamek : public Miasto {
private:
    Bohater* wlasciciel;
    vector<Potwor*> jednostki;

public:
    Zamek(string nazwa, int poziom, int populacja, int zloto, Bohater* wlasciciel);
    void dodajJednostke(Potwor* jednostka);
    void przedstaw() override;
};

class Kopalnia : public Miasto {
private:
    int produkcjaZlota;

public:
    Kopalnia(string nazwa, int poziom, int populacja, int zloto, int produkcjaZlota);
    void zwiekszProdukcjeZlota(int ilosc);
    int getProdukcjaZlota();
    void przedstaw() override;
};

class Gildia : public Struktura {
public:
    Gildia(string nazwa, int poziom);
    void przedstaw() override;
    string getNazwa() override;
    int getPoziom() override;
    void zwiekszPoziom() override;
    void resetuj() override;
};

#endif // STRUKTURY_H