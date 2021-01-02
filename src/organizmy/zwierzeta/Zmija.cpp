//
// Created by johnny on 22/11/2020.
//

#include "Zmija.h"
#include "../../Swiat.h"

Zmija::Zmija() {
    podwojnyRuch = false;
    sila = 2;
    inicjatywa = 3;
    znak = "\U0001F40D";
}

Organizm *Zmija::dziecko() {
    return new Zmija();
}

void Zmija::kolizja(Zwierze &wchodzacy) {
    Zwierze::kolizja(wchodzacy);
    if (!zyje) {
        swiat->zabij(wchodzacy);
    }
}
