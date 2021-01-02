//
// Created by johnny on 22/11/2020.
//
#include "Swiat.h"
#include "Organizm.h"

Organizm::Organizm() {
    zyje = false;
    sila = 0;
    znak = "\U00002753";
}

void Organizm::zarejestrujSwiat(Swiat *_swiat) {
    urodziny = _swiat->ktoraTura();
    zyje = true;
    swiat = _swiat;
}

void Organizm::rysowanie() {
    Ekran::instancja()->wstawZnak(znak, pozycja);
}

int Organizm::jakaInicjatywa() {
    return inicjatywa;
}


unsigned int Organizm::wiek() {
    return swiat->ktoraTura() - urodziny;
}


