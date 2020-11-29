//
// Created by johnny on 22/11/2020.
//
#include "../Swiat.h"
#include "Zwierze.h"


Zwierze::Zwierze() {
    znak = "\U0001F43E";
}

void Zwierze::akcja() {
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


void Zwierze::kolizja(Organizm &wchodzacy) {
    kolizja(reinterpret_cast<Zwierze &>(wchodzacy));
}

void Zwierze::kolizja(Zwierze &wchodzacy) {
    if (znak == wchodzacy.znak) {
        swiat->rozmnorz(*this, wchodzacy);
    } else {
        int rzadZabitego = rzad;
        int kolumnaZabitego = kolumna;
        swiat->zabij(*this);
        swiat->idz(wchodzacy, rzadZabitego, kolumnaZabitego);
    }
}

