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
    zyje = true;
    swiat = _swiat;
}

void Organizm::rysowanie() {
    Ekran::instancja()->wstawZnak(znak, pozycja);
}


