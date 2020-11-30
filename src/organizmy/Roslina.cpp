//
// Created by johnny on 22/11/2020.
//

#include "../Swiat.h"
#include "Roslina.h"

Roslina::Roslina() {
    inicjatywa = 0;
    sila = 0;
    znak = "\U0001F343";
}

void Roslina::akcja() {
    if (rand() % 100 < 20) {
        swiat->rozmnorz(*this);
    }
}

void Roslina::kolizja(Organizm &wchodzacy) {
    auto rzadZabitego = rzad;
    auto kolumnaZabitego = kolumna;
    swiat->zabij(*this);
    swiat->idz(wchodzacy, rzadZabitego, kolumnaZabitego);
}
