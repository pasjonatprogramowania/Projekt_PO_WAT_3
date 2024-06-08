#include "../include/Pojazdy.h"

Pojazd::Pojazd(string wlasciciel, string typ) {
    this->wlasciciel = wlasciciel;
    this->typ = typ;
}

Karoca::Karoca(string wlasciciel, string typ, int RokZakupu, int przebieg) : Pojazd(wlasciciel, typ) {
    this->RokZakupu = RokZakupu;
    this->przebieg = przebieg;
}

void Karoca::zwiekszPrzebieg(int kilometry) {
    this->przebieg += kilometry;
}

void Karoca::przedstaw() {
    cout << "Karoca: " << wlasciciel << ", Typ: " << typ << ", Rok Zakupu: " << RokZakupu << ", Przebieg: " << przebieg << endl;
}

string Karoca::getWlasciciel() {
    return wlasciciel;
}

string Karoca::getTyp() {
    return typ;
}

void Karoca::zmienTyp(string nowyTyp) {
    typ = nowyTyp;
}

void Karoca::wykonajPrzeglad() {
    przebieg = 0;
}