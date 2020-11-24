//
// Created by johnny on 22/11/2020.
//

#include "Organizm.h"

Organizm::Organizm() {
    sila = 0;
    inicjatywa = 0;
    posX = 0;
    posY = 0;
}

void Organizm::zarejestrujSwiat(Swiat &_swiat) {
    swiat = &_swiat;
}

void Organizm::akcja() {

}

void Organizm::kolizja() {

}

void Organizm::rysowanie() {
    //    std::string bee =  "\uD83D";
    Ekran::instancja()->wstawZnak("\U0001F331", 1, 1);
    Ekran::instancja()->wstawZnak("\U0001F34E", 3, 3);
    Ekran::instancja()->wstawZnak("\U0001F411", 5, 5);
}
