#include "../include/Przedmioty.h"

Zasoby::Zasoby(string nazwa, int wartosc) {
    this->nazwa = nazwa;
    this->wartosc = wartosc;
}

Przedmiot::Przedmiot(string nazwa, int wartosc) : Zasoby(nazwa, wartosc) {}

void Przedmiot::przedstaw() {
    cout << "Przedmiot: " << nazwa << ", Wartosc: " << wartosc << endl;
}

string Przedmiot::getNazwa() {
    return nazwa;
}

int Przedmiot::getWartosc() {
    return wartosc;
}

void Przedmiot::zmienWartosc(int nowaWartosc) {
    wartosc = nowaWartosc;
}

void Przedmiot::resetuj() {
    wartosc = 0;
}

Bron::Bron(string nazwa, int wartosc, int punktyAtaku) : Przedmiot(nazwa, wartosc) {
    this->punktyAtaku = punktyAtaku;
}

int Bron::getPunktyAtaku() {
    return punktyAtaku;
}

void Bron::przedstaw() {
    cout << "Bron: " << nazwa << ", Wartosc: " << wartosc << ", Punkty Ataku: " << punktyAtaku << endl;
}

Zbroja::Zbroja(string nazwa, int wartosc, int punktyObrony) : Przedmiot(nazwa, wartosc) {
    this->punktyObrony = punktyObrony;
}

int Zbroja::getPunktyObrony() {
    return punktyObrony;
}

void Zbroja::przedstaw() {
    cout << "Zbroja: " << nazwa << ", Wartosc: " << wartosc << ", Punkty Obrony: " << punktyObrony << endl;
}