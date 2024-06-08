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

class Karoca : public Pojazd {
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
};

#endif // POJAZDY_H