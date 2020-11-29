//
// Created by johnny on 22/11/2020.
//

#include "Zmija.h"

Zmija::Zmija() {
    sila = 2;
    inicjatywa = 3;
    znak = "\U0001F40D";
}

Organizm *Zmija::dziecko() {
    return new Zmija();
}