//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_SWIAT_H
#define JPO_SWIAT_SWIAT_H

#include <vector>
#include "Ekran.h"
#include "Organizm.h"

class Organizm;

class Swiat {
private:
    std::vector<Organizm *> organizmy;

    int korygatorWspolrzednej(int wspolrzedna);

    bool znajdzWolneMiejsceObok(int rzad, int kolumna, int &wybranyRzad, int &wybranaKolumna);

public:
    void wykonajTure();

    void rysujSwiat();

    void dodajOrganizm(Organizm *organizm);

    void idz(Organizm &organizm, int rzad, int kolumna);

    void zabij(Organizm &organizm);

    Organizm *znajdz(int rzad, int kolumna);

    Organizm *rozmnorz(Organizm &pasywny, Organizm &inicjator);

};

//struct wspolrzedne {
//    int rzad;
//    int kolumna;
//};
#endif //JPO_SWIAT_SWIAT_H
