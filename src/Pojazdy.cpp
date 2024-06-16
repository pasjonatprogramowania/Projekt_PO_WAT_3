#include "../include/Pojazdy.h"

Pojazd::Pojazd(string wlasciciel, string typ) : wlasciciel(wlasciciel), typ(typ) {}

PojazdLadowy::PojazdLadowy(string wlasciciel, string typ) : Pojazd(wlasciciel, typ) {}

PojazdWodny::PojazdWodny(string wlasciciel, string typ) : Pojazd(wlasciciel, typ) {}

PojazdPowietrzny::PojazdPowietrzny(string wlasciciel, string typ) : Pojazd(wlasciciel, typ) {}

PojazdKosmiczny::PojazdKosmiczny(string wlasciciel, string typ) : Pojazd(wlasciciel, typ) {}

Karoca::Karoca(string wlasciciel, string typ, int RokZakupu, int przebieg)
        : PojazdLadowy(wlasciciel, typ), RokZakupu(RokZakupu), przebieg(przebieg) {}

void Karoca::zwiekszPrzebieg(int kilometry) {
    przebieg += kilometry;
}

void Karoca::przedstaw() {
    cout << "Jestem karoca. Moj wlasciciel to: " << wlasciciel << ", typ: " << typ << endl;
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
    cout << "Wykonuje przeglad karocy." << endl;
}

void Karoca::jedzDoPrzodu() {
    cout << "Jade do przodu." << endl;
}

void Karoca::jedzDoTylu() {
    cout << "Jade do tylu." << endl;
}

void Karoca::skrecWLewo() {
    cout << "Skrecam w lewo." << endl;
}

void Karoca::skrecWPrawo() {
    cout << "Skrecam w prawo." << endl;
}

void Karoca::zatrzymajSie() {
    cout << "Zatrzymuje sie." << endl;
}