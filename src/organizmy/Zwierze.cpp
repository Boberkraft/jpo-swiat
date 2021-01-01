//
// Created by johnny on 22/11/2020.
//
#include "../Swiat.h"
#include "Zwierze.h"


Zwierze::Zwierze() {
    znak = "\U0001F43E";
    podwojnyRuch = false;
}

void Zwierze::akcja() {
    swiat->idz(*this, *pozycja.obok(1));
    if (podwojnyRuch) {
        podwojnyRuch = false;
        akcja();
    }
}


void Zwierze::kolizja(Organizm &wchodzacy) {
    kolizja(reinterpret_cast<Zwierze &>(wchodzacy));
}

void Zwierze::kolizja(Zwierze &wchodzacy) {
    if (znak == wchodzacy.znak) {
        swiat->rozmnorz(*this, wchodzacy);
    } else {
        swiat->zabij(*this);
        swiat->idz(wchodzacy, pozycja);
    }
}

void Zwierze::dajBuffaPodwojnegoRuchu() {
    podwojnyRuch = true;
}

