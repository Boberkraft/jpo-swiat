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
        auto komunikat = std::vector<std::string>();



        if (wchodzacy.jakaSila() >= this->jakaSila()) {
            komunikat.push_back(wchodzacy.znak);
            komunikat.emplace_back("\U0001F52A");
            komunikat.push_back(this->znak);
            swiat->zabij(*this);
            swiat->idz(wchodzacy, pozycja);
        } else {
            komunikat.push_back(this->znak);
            komunikat.emplace_back("\U0001F6E1 ");
            komunikat.push_back(wchodzacy.znak);
            swiat->zabij(wchodzacy);
        }

        Ekran::instancja()->wstawKomunikat(komunikat);

    }
}

void Zwierze::dajBuffaPodwojnegoRuchu() {
    podwojnyRuch = true;
}

