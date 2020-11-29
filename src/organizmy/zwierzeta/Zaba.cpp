//
// Created by johnny on 22/11/2020.
//

#include "Zaba.h"

Zaba::Zaba() {
    sila = 9;
    inicjatywa = 5;
    znak = "\U0001F438";
}

Organizm *Zaba::dziecko() {
    return new Zaba();
}