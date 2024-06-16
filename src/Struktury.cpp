#include "../include/Struktury.h"

Obiekt::Obiekt(string nazwa) : nazwa(nazwa) {}

string Obiekt::getNazwa() {
    return nazwa;
}

Struktura::Struktura(string nazwa, int poziom) : Obiekt(nazwa), poziom(poziom) {}

int Struktura::getPoziom() {
    return poziom;
}

void Struktura::zwiekszPoziom() {
    poziom++;
}

Budynek::Budynek(string nazwa, int poziom) : Struktura(nazwa, poziom) {}

void Budynek::przedstaw() {
    cout << "Budynek: " << nazwa << ", Poziom: " << poziom << endl;
}

void Budynek::resetuj() {
    poziom = 1;
}

Zasoby::Zasoby(string nazwa, int poziom, int zloto) : Budynek(nazwa, poziom), zloto(zloto) {}

void Zasoby::przedstaw() {
    cout << "Zasoby: " << nazwa << ", Poziom: " << poziom << ", Zloto: " << zloto << endl;
}

void Zasoby::resetuj() {
    Budynek::resetuj();
    zloto = 0;
}

ProdukcjaZasobow::ProdukcjaZasobow(string nazwa, int poziom, int zloto, int produkcjaZlota)
        : Zasoby(nazwa, poziom, zloto), produkcjaZlota(produkcjaZlota) {}

void ProdukcjaZasobow::przedstaw() {
    cout << "ProdukcjaZasobow: " << nazwa << ", Poziom: " << poziom << ", Zloto: " << zloto
         << ", ProdukcjaZlota: " << produkcjaZlota << endl;
}

void ProdukcjaZasobow::resetuj() {
    Zasoby::resetuj();
    produkcjaZlota = 0;
}

Miasto::Miasto(string nazwa, int poziom, int populacja, int zloto)
        : Zasoby(nazwa, poziom, zloto), populacja(populacja) {}

void Miasto::zwiekszPopulacje(int ilosc) {
    populacja += ilosc;
}

void Miasto::zwiekszZloto(int ilosc) {
    zloto += ilosc;
}

int Miasto::getPopulacja() {
    return populacja;
}

void Miasto::przedstaw() {
    cout << "Miasto: " << nazwa << ", Poziom: " << poziom << ", Populacja: " << populacja
         << ", Zloto: " << zloto << endl;
}

void Miasto::resetuj() {
    Zasoby::resetuj();
    populacja = 0;
}

Zamek::Zamek(string nazwa, int poziom, int populacja, int zloto, Bohater* wlasciciel)
        : Miasto(nazwa, poziom, populacja, zloto), wlasciciel(wlasciciel) {}

void Zamek::dodajJednostke(Potwor* jednostka) {
    jednostki.push_back(jednostka);
}
string Zamek::getNazwa() {
    return nazwa;
}

int Zamek::getWartosc() {
    return poziom;
}

void Zamek::zmienWartosc(int wartosc) {
    poziom = wartosc;
}

string Kopalnia::getNazwa() {
    return nazwa;
}

int Kopalnia::getWartosc() {
    return poziom;
}

void Kopalnia::zmienWartosc(int wartosc) {
    poziom = wartosc;
}
void Zamek::przedstaw() {
    cout << "Zamek: " << nazwa << ", Poziom: " << poziom << ", Populacja: " << getPopulacja()
         << ", Zloto: " << zloto << endl;
}

Kopalnia::Kopalnia(string nazwa, int poziom, int populacja, int zloto, int produkcjaZlota)
        : ProdukcjaZasobow(nazwa, poziom, zloto, produkcjaZlota) {}

void Kopalnia::zwiekszProdukcjeZlota(int ilosc) {
    produkcjaZlota += ilosc;
}

int Kopalnia::getProdukcjaZlota() {
    return produkcjaZlota;
}

void Kopalnia::przedstaw() {
    cout << "Kopalnia: " << nazwa << ", Poziom: " << poziom << ", Zloto: " << zloto
         << ", ProdukcjaZlota: " << produkcjaZlota << endl;
}

void Kopalnia::resetuj() {
    ProdukcjaZasobow::resetuj();
}

Gildia::Gildia(string nazwa, int poziom) : Budynek(nazwa, poziom) {}

void Gildia::przedstaw() {
    cout << "Gildia: " << nazwa << ", Poziom: " << poziom << endl;
}