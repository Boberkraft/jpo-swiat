//
// Created by johnny on 22/11/2020.
//

#include "../Swiat.h"
#include "Roslina.h"

Roslina::Roslina() {
    inicjatywa = 0;
    sila = 0;
    znak = "\U0001F343";
}

void Roslina::akcja() {
    if (rand() % 100 < 20) {
        swiat->rozmnorz(*this);
    }
}

//void Roslina::rozmnorz() {
//    int wolnyRzad, wolnaKolumna;
//    swiat->znajdzWolneMiejsceObok();
//
//}
void Roslina::kolizja(Organizm &wchodzacy) {

    auto komunikat = std::vector<std::string>();
    komunikat.push_back(wchodzacy.znak);
    komunikat.emplace_back("\U0001F52A");
    komunikat.push_back(this->znak);
    Ekran::instancja()->wstawKomunikat(komunikat);
    swiat->zabij(*this);
    swiat->idz(wchodzacy, pozycja);
}
