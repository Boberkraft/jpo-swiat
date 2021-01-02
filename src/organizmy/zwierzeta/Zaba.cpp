//
// Created by johnny on 22/11/2020.
//

#include "Zaba.h"
#include "../../Swiat.h"

Zaba::Zaba() {
    podwojnyRuch = false;
    sila = 4;
    inicjatywa = 2;
    znak = "\U0001F438";
}

Organizm *Zaba::dziecko() {
    return new Zaba();
}

void Zaba::akcja() {
    swiat->idz(*this, *pozycja.obok(2));
    if (podwojnyRuch) {
        podwojnyRuch = false;
        akcja();
    }
}
