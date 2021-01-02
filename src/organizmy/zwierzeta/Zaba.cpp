//
// Created by johnny on 22/11/2020.
//

#include "Zaba.h"
#include "../../Swiat.h"
#include "iostream"

Zaba::Zaba() {
    podwojnyRuch = false;
    sila = 0;
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
    std::cout << "HEJ" << std::endl;
    bool znalezionoWolneMiejsce = swiat->znajdzWolneMiejsceObok(1,
                                                         this->pozycja,
                                                         wolnaPozycja);

    if (wchodzacy.znak != znak && znalezionoWolneMiejsce) {
        auto komunikat = std::vector<std::string>();
        komunikat.push_back(znak);
        komunikat.emplace_back("\U0001F4A8");
        Ekran::instancja()->wstawKomunikat(komunikat);
        swiat->idz(*this, wolnaPozycja);
    } else {
        Zwierze::kolizja(wchodzacy);
    };
}
