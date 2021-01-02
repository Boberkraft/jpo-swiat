//
// Created by johnny on 22/11/2020.
//

#include "Leniwiec.h"



Leniwiec::Leniwiec() {
    spi = false;
    sila = 2;
    inicjatywa = 1;
    znak = "\U0001F9A5";
}

Organizm *Leniwiec::dziecko() {
    return new Leniwiec();
}

void Leniwiec::akcja() {
    spi = !spi;
    if (!spi) {
        Zwierze::akcja();
    }
}
