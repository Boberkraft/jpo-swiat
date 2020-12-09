//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_SWIAT_H
#define JPO_SWIAT_SWIAT_H

#include <vector>
#include "Ekran.h"
#include "Organizm.h"
#include "organizmy/Zwierze.h"
#include "organizmy/Roslina.h"


class Swiat {
private:
    std::vector<Organizm *> organizmy;

    unsigned int korygatorWspolrzednej(int wspolrzedna);

    Organizm *rozmnorz(Organizm &organizm, unsigned int zasieg);

public:
    void wykonajTure();

    void rysujSwiat();

    void dodajOrganizm(Organizm *organizm);

    void idz(Organizm &organizm, int rzad, int kolumna);

    void zabij(Organizm &organizm);

    Organizm *znajdz(int rzad, int kolumna);

    Zwierze *rozmnorz(Zwierze &pasywny, Zwierze &inicjator);

    Roslina *rozmnorz(Roslina &roslina);


    bool znajdzWolneMiejsceObok(unsigned int zasieg, int rzad, int kolumna, int &wybranyRzad, int &wybranaKolumna);

};

//struct wspolrzedne {
//    int rzad;
//    int kolumna;
//};
#endif //JPO_SWIAT_SWIAT_H
