#ifndef ISTOTY_H
#define ISTOTY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stworzenie {
protected:
    string imie;
    int poziom;
    int punktyZycia;

public:
    Stworzenie(string imie, int poziom, int punktyZycia);
    virtual ~Stworzenie() = default;
    virtual void przedstaw() = 0;
    virtual int getPoziom() = 0;
    virtual int getPunktyZycia() = 0;
    virtual void zwiekszPoziom() = 0;
    virtual void przyjmijObrazenia(int obrazenia) = 0;
};

#endif // ISTOTY_H