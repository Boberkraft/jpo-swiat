//
// Created by johnny on 22/11/2020.
//

#include "Zwierze.h"
//
//
//podstawową formę ruchu w metodzie akcja() → każde typowe zwierze w swojej turze
//przesuwa się na wybrane losowo, sąsiednie pole,
//
//        rozmnażanie w ramach metody kolizja() → przy kolizji z organizmem tego samego gatunku
//        nie dochodzi do walki, oba zwierzęta pozostają na swoich miejscach, koło nich pojawia się trzecie zwierze, tego samego gatunku.


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
    if (znak == wchodzacy.znak) {
        swiat->rozmnorz(*this, wchodzacy);
    } else {
        int rzadZabitego = rzad;
        int kolumnaZabitego = kolumna;
        swiat->zabij(*this);
        swiat->idz(wchodzacy, rzadZabitego, kolumnaZabitego);
    }
}

Organizm *Zwierze::podobnaInstacja() {
    return new Zwierze();
}
