//
// Created by johnny on 22/11/2020.
//
#include "Swiat.h"
#include "Organizm.h"

Organizm::Organizm() {
    sila = 0;
    inicjatywa = 0;
    kolumna = 0;
    rzad = 0;
    znak = "\U00002753";
}

void Organizm::zarejestrujSwiat(Swiat *_swiat) {
    swiat = _swiat;
}

void Organizm::rysowanie() {
    Ekran::instancja()->wstawZnak(znak, rzad, kolumna);
}


