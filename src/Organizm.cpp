//
// Created by johnny on 22/11/2020.
//

#include "Organizm.h"

Organizm::Organizm() {
    sila = 0;
    inicjatywa = 0;
    kolumna = 0;
    rzad = 0;
    znak = "\U00002753";
}

void Organizm::zarejestrujSwiat(Swiat &_swiat) {
    swiat = &_swiat;
}

void Organizm::akcja() {
    switch (rand() % 4) {
        case 0:
            swiat->idz(*this, rzad + 1, kolumna);
            break;
        case 1:
            swiat->idz(*this, rzad - 1, kolumna);
            break;
        case 2:
            swiat->idz(*this, rzad, kolumna + 1);
            break;
        case 3:
            swiat->idz(*this, rzad, kolumna - 1);
            break;
    }
}

void Organizm::kolizja(Organizm &wchodzacy) {
    if (znak == wchodzacy.znak) {
        swiat->rozmnorz(*this, wchodzacy);
    } else {
        int rzadZabitego = rzad;
        int kolumnaZabitego = kolumna;
        swiat->zabij(*this);
        swiat->idz(wchodzacy, rzadZabitego, kolumnaZabitego);
    }
}

void Organizm::rysowanie() {
    Ekran::instancja()->wstawZnak(znak, rzad, kolumna);
}
