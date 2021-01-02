//
// Created by johnny on 22/11/2020.
//

#include "Wilk.h"

Wilk::Wilk() {
    podwojnyRuch = false;
    sila = 9;
    inicjatywa = 5;
    znak = "\U0001F415";
}

Organizm *Wilk::dziecko() {
    return new Wilk();
}
