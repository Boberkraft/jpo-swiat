#include <iostream>
#include <zconf.h>

#include "Swiat.h"
#include "Ekran.h"

int main() {
    Swiat swiat;
    auto organizm1 = new Organizm();
    auto organizm2 = new Organizm();
    swiat.dodajOrganizm(organizm1);
    swiat.dodajOrganizm(organizm2);
    swiat.idz(*organizm1, 5, 5);
    swiat.idz(*organizm2, 5, 6);

    swiat.rozmnorz(*organizm1, *organizm2);
    for (int i = 0; i < 100; i++) {
        system("clear");
        swiat.rysujSwiat();
        sleep(0.1);
        swiat.wykonajTure();

    }
    return 0;
}

