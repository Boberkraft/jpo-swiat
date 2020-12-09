//
// Created by johnny on 22/11/2020.
//
#include "../Swiat.h"
#include "Zwierze.h"


Zwierze::Zwierze() {
    znak = "\U0001F43E";
}

void Zwierze::akcja() {
    int deltaRzad = 0;
    int deltaKolumna = 0;

    while (deltaRzad == 0 && deltaKolumna == 0) {
        deltaRzad = (rand() % 3) - 1;
        deltaKolumna = (rand() % 3) - 1;
    }
    swiat->idz(*this,
               rzad + deltaRzad,
               kolumna + deltaKolumna);
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

