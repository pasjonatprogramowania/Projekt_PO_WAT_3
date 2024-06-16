#ifndef POJAZDY_H
#define POJAZDY_H

#include <iostream>
#include <string>

using namespace std;

class Pojazd {
protected:
    string wlasciciel;
    string typ;

public:
    Pojazd(string wlasciciel, string typ);
    virtual ~Pojazd() = default;
    virtual void przedstaw() = 0;
    virtual string getWlasciciel() = 0;
    virtual string getTyp() = 0;
    virtual void zmienTyp(string nowyTyp) = 0;
    virtual void wykonajPrzeglad() = 0;
};

class PojazdLadowy : public Pojazd {
public:
    PojazdLadowy(string wlasciciel, string typ);
    virtual void jedzDoPrzodu() = 0;
    virtual void jedzDoTylu() = 0;
    virtual void skrecWLewo() = 0;
    virtual void skrecWPrawo() = 0;
    virtual void zatrzymajSie() = 0;
};

class PojazdWodny : public Pojazd {
public:
    PojazdWodny(string wlasciciel, string typ);
    virtual void plyn() = 0;
    virtual void zanurz() = 0;
    virtual void wynurz() = 0;
    virtual void obroc() = 0;
    virtual void zarzucKotwice() = 0;
};

class PojazdPowietrzny : public Pojazd {
public:
    PojazdPowietrzny(string wlasciciel, string typ);
    virtual void startuj() = 0;
    virtual void laduj() = 0;
    virtual void wznies() = 0;
    virtual void obniz() = 0;
    virtual void wykonajBeczkę() = 0;
};

class PojazdKosmiczny : public Pojazd {
public:
    PojazdKosmiczny(string wlasciciel, string typ);
    virtual void wystrzel() = 0;
    virtual void orbituj() = 0;
    virtual void powrocNaZiemie() = 0;
    virtual void dokuj() = 0;
    virtual void odczepKapsulee() = 0;
};

class Karoca : public PojazdLadowy {
private:
    int RokZakupu;
    int przebieg;

public:
    Karoca(string wlasciciel, string typ, int RokZakupu, int przebieg);
    void zwiekszPrzebieg(int kilometry);
    void przedstaw() override;
    string getWlasciciel() override;
    string getTyp() override;
    void zmienTyp(string nowyTyp) override;
    void wykonajPrzeglad() override;
    void jedzDoPrzodu() override;
    void jedzDoTylu() override;
    void skrecWLewo() override;
    void skrecWPrawo() override;
    void zatrzymajSie() override;
};

#endif // POJAZDY_H