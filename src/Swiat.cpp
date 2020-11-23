//
// Created by johnny on 22/11/2020.
//

#include "Swiat.h"

void Swiat::wykonajTure() {

}

void Swiat::rysujSwiat() {
    for (auto organizm : organizmy) {
        organizm->rysowanie();
    }
    Ekran::instancja()->wyswietl();
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
    organizm->zarejestrujSwiat(*this);
}