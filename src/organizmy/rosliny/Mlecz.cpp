//
// Created by johnny on 22/11/2020.
//

#include "Mlecz.h"

Mlecz::Mlecz() {
    znak = "\U0001F337";
}

Organizm *Mlecz::dziecko() {
    return new Mlecz();
}

void Mlecz::akcja() {
    Roslina::akcja();
    Roslina::akcja();
    Roslina::akcja();
}
