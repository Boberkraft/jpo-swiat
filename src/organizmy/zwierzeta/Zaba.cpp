//
// Created by johnny on 22/11/2020.
//

#include "Zaba.h"
#include "../../Swiat.h"

Zaba::Zaba() {
    sila = 9;
    inicjatywa = 5;
    znak = "\U0001F438";
}

Organizm *Zaba::dziecko() {
    return new Zaba();
}

void Zaba::akcja() {
    int deltaRzad = 0;
    int deltaKolumna = 0;

    while (deltaRzad == 0 && deltaKolumna == 0) {
        deltaRzad = (rand() % 4) - 2;
        deltaKolumna = (rand() % 4) - 2;
    }
    swiat->idz(*this,
               rzad + deltaRzad,
               kolumna + deltaKolumna);
}
