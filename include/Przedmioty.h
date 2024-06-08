#ifndef PRZEDMIOTY_H
#define PRZEDMIOTY_H

#include <iostream>
#include <string>

using namespace std;

class Zasoby {
protected:
    string nazwa;
    int wartosc;

public:
    Zasoby(string nazwa, int wartosc);
    virtual ~Zasoby() = default;
    virtual void przedstaw() = 0;
    virtual string getNazwa() = 0;
    virtual int getWartosc() = 0;
    virtual void zmienWartosc(int nowaWartosc) = 0;
    virtual void resetuj() = 0;
};

class Przedmiot : public Zasoby {
public:
    Przedmiot(string nazwa, int wartosc);
    void przedstaw() override;
    string getNazwa() override;
    int getWartosc() override;
    void zmienWartosc(int nowaWartosc) override;
    void resetuj() override;
};

class Bron : public Przedmiot {
private:
    int punktyAtaku;

public:
    Bron(string nazwa, int wartosc, int punktyAtaku);
    int getPunktyAtaku();
    void przedstaw() override;
};

class Zbroja : public Przedmiot {
private:
    int punktyObrony;

public:
    Zbroja(string nazwa, int wartosc, int punktyObrony);
    int getPunktyObrony();
    void przedstaw() override;
};

#endif // PRZEDMIOTY_H