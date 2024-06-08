#include "../include/Struktury.h"

Struktura::Struktura(string nazwa, int poziom) {
    this->nazwa = nazwa;
    this->poziom = poziom;
}

Miasto::Miasto(string nazwa, int poziom, int populacja, int zloto) : Struktura(nazwa, poziom) {
    this->populacja = populacja;
    this->zloto = zloto;
}

void Miasto::zwiekszPopulacje(int ilosc) {
    this->populacja += ilosc;
}

void Miasto::zwiekszZloto(int ilosc) {
    this->zloto += ilosc;
}

int Miasto::getPopulacja() {
    return populacja;
}

int Miasto::getZloto() {
    return zloto;
}

string Miasto::getNazwa() {
    return nazwa;
}

int Miasto::getPoziom() {
    return poziom;
}

void Miasto::zwiekszPoziom() {
    poziom++;
}

void Miasto::resetuj() {
    poziom = 0;
    populacja = 0;
    zloto = 0;
}

void Miasto::przedstaw() {
    cout << "Miasto: " << nazwa << ", Poziom: " << poziom << ", Populacja: " << populacja << ", Zloto: " << zloto << endl;
}

Zamek::Zamek(string nazwa, int poziom, int populacja, int zloto, Bohater* wlasciciel) : Miasto(nazwa, poziom, populacja, zloto) {
    this->wlasciciel = wlasciciel;
}

void Zamek::dodajJednostke(Potwor* jednostka) {
    this->jednostki.push_back(jednostka);
}

void Zamek::przedstaw() {
    cout << "Zamek: " << nazwa << ", Poziom: " << poziom << ", Populacja: " << getPopulacja() << ", Zloto: " << getZloto() << ", Wlasciciel: ";
    wlasciciel->przedstaw();
    for (auto jednostka : jednostki) {
        jednostka->przedstaw();
    }
}

Kopalnia::Kopalnia(string nazwa, int poziom, int populacja, int zloto, int produkcjaZlota) : Miasto(nazwa, poziom, populacja, zloto) {
    this->produkcjaZlota = produkcjaZlota;
}

void Kopalnia::zwiekszProdukcjeZlota(int ilosc) {
    this->produkcjaZlota += ilosc;
}

int Kopalnia::getProdukcjaZlota() {
    return produkcjaZlota;
}

void Kopalnia::przedstaw() {
    cout << "Kopalnia: " << nazwa << ", Poziom: " << poziom << ", Populacja: " << getPopulacja() << ", Zloto: " << getZloto() << ", Produkcja Zlota: " << produkcjaZlota << endl;
}

Gildia::Gildia(string nazwa, int poziom) : Struktura(nazwa, poziom) {}

void Gildia::przedstaw() {
    cout << "Gildia: " << nazwa << ", Poziom: " << poziom << endl;
}

string Gildia::getNazwa() {
    return nazwa;
}

int Gildia::getPoziom() {
    return poziom;
}

void Gildia::zwiekszPoziom() {
    poziom++;
}

void Gildia::resetuj() {
    poziom = 0;
}