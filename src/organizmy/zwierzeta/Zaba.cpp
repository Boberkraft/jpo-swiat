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

void Zaba::kolizja(Zwierze &wchodzacy) {
    Pozycja wolnaPozycja;
    bool znalezionoWolneMiejsce = swiat->znajdzWolneMiejsceObok(1,
                                                         this->pozycja,
                                                         wolnaPozycja);

    if (wchodzacy.znak != znak && znalezionoWolneMiejsce && rand() % 2 == 0) {
        swiat->idz(*this, wolnaPozycja);
    } else {
        Zwierze::kolizja(wchodzacy);
    };
}
