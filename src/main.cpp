#include <iostream>
#include <zconf.h>

#include "Swiat.h"
#include "Ekran.h"
#include "organizmy/zwierzeta/Wilk.h"
#include "organizmy/zwierzeta/Owca.h"
#include "organizmy/zwierzeta/Zmija.h"
#include "organizmy/zwierzeta/Leniwiec.h"
#include "organizmy/zwierzeta/Zaba.h"
#include "organizmy/rosliny/Koka.h"
#include "organizmy/rosliny/Mlecz.h"
#include "organizmy/rosliny/Trawa.h"

#define dodaj(nazwa_zmiennaj, KLASA, rzad, kolumna) \
        Organizm * nazwa_zmiennaj = new KLASA();    \
        swiat.dodajOrganizm(nazwa_zmiennaj);        \
        swiat.idz(*nazwa_zmiennaj, Pozycja(rzad, kolumna));

int main() {
    Swiat swiat;

    dodaj(wilk1, Wilk, 14, 1);
    dodaj(wilk2, Wilk, 13, 1);
    dodaj(wilk3, Wilk, 2, 1);
    dodaj(owca1, Owca, 3, 3);
    dodaj(owca2, Owca, 4, 16);
    dodaj(owca3, Owca, 6, 6);
    dodaj(owca4, Owca, 14, 13);
    dodaj(zmija1, Zmija, 7, 7);
    dodaj(zmija2, Zmija, 13, 15);
    dodaj(zmija3, Zmija, 10, 10);
    dodaj(leniwiec1, Leniwiec, 16, 10);
    dodaj(leniwiec2, Leniwiec, 15, 10);
    dodaj(leniwiec3, Leniwiec, 15, 7);
    dodaj(zaba1, Zaba, 3, 9);
    dodaj(zaba2, Zaba, 3, 7);
    dodaj(zaba4, Zaba, 1, 7);
    dodaj(zaba5, Zaba, 5, 7);
    dodaj(koka, Koka, 8, 8);
    dodaj(koka1, Koka, 9, 4);
    dodaj(koka2, Koka, 10, 2);
    dodaj(mlecz, Mlecz, 10, 15);
    dodaj(trawa1, Trawa, 10, 17);
    dodaj(trawa2, Trawa, 10, 18);

//    dodaj(wilk1, Wilk, 8, 9);
//    dodaj(koka, Koka, 8, 8);

    for (int i = 0; i < 100000; i++) {

        swiat.rysujSwiat();
        sleep(1);
        swiat.wykonajTure();

    }
    return 0;
}
