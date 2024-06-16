#include "../include/Postacie.h"

// Implementacje metod klasy Postac
Postac::Postac(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony)
        : Stworzenie(imie, poziom, punktyZycia) {
    this->punktyAtaku = punktyAtaku;
    this->punktyObrony = punktyObrony;
}

void Postac::zwiekszPoziom() {
    this->poziom++;
}

void Postac::przyjmijObrazenia(int obrazenia) {
    this->punktyZycia -= obrazenia;
}

int Postac::getPoziom() {
    return poziom;
}

int Postac::getPunktyZycia() {
    return punktyZycia;
}

int Postac::getPunktyAtaku() {
    return punktyAtaku;
}

int Postac::getPunktyObrony() {
    return punktyObrony;
}

void Postac::przedstaw() {
    cout << "Postac: " << imie << ", Poziom: " << poziom << ", Punkty Zycia: " << punktyZycia << ", Punkty Ataku: " << punktyAtaku << ", Punkty Obrony: " << punktyObrony << endl;
}

// Implementacje metod klasy Bohater
Bohater::Bohater(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony, int punktyDoswiadczenia, int zloto)
        : Postac(imie, poziom, punktyZycia, punktyAtaku, punktyObrony) {
    this->punktyDoswiadczenia = punktyDoswiadczenia;
    this->zloto = zloto;
}

void Bohater::zwiekszPunktyDoswiadczenia(int punkty) {
    this->punktyDoswiadczenia += punkty;
}

void Bohater::zwiekszZloto(int ilosc) {
    this->zloto += ilosc;
}

int Bohater::getPunktyDoswiadczenia() {
    return punktyDoswiadczenia;
}

int Bohater::getZloto() {
    return zloto;
}

void Bohater::przedstaw() {
    cout << "Bohater: " << imie << ", Poziom: " << poziom << ", Punkty Zycia: " << punktyZycia << ", Punkty Ataku: " << punktyAtaku << ", Punkty Obrony: " << punktyObrony << ", Punkty Doswiadczenia: " << punktyDoswiadczenia << ", Zloto: " << zloto << endl;
}

// Implementacje metod klasy Potwor
Potwor::Potwor(string imie, int poziom, int punktyZycia, int punktyAtaku, int punktyObrony)
        : Postac(imie, poziom, punktyZycia, punktyAtaku, punktyObrony) {}

void Potwor::przedstaw() {
    cout << "Potwor: " << imie << ", Poziom: " << poziom << ", Punkty Zycia: " << punktyZycia << ", Punkty Ataku: " << punktyAtaku << ", Punkty Obrony: " << punktyObrony << endl;
}

// Implementacje metod klasy Zwierze
Zwierze::Zwierze(string imie, int poziom, int punktyZycia, string gatunek)
        : Stworzenie(imie, poziom, punktyZycia) {
    this->gatunek = gatunek;
}

void Zwierze::przedstaw() {
    cout << "Zwierze: " << imie << ", Wiek: " << poziom << ", Gatunek: " << gatunek << endl;
}

int Zwierze::getPoziom() {
    return poziom;
}

int Zwierze::getPunktyZycia() {
    return punktyZycia;
}

void Zwierze::zwiekszPoziom() {
    poziom++;
}

void Zwierze::przyjmijObrazenia(int obrazenia) {
    punktyZycia -= obrazenia;
}



bool Postac::operator<(const Postac& other) const {
    return poziom < other.poziom;
}

Bohater& Bohater::operator+=(int punktyDoswiadczenia) {
    this->punktyDoswiadczenia += punktyDoswiadczenia;
    return *this;
}

Potwor& Potwor::operator-=(int punktyZycia) {
    this->punktyZycia -= punktyZycia;
    return *this;
}

char Zwierze::operator[](int index) const {
    if (index >= 0 && index < gatunek.length()) {
        return gatunek[index];
    }
    return '\0';
}