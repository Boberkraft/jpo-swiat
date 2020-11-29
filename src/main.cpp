#include <iostream>
#include <zconf.h>

#include "Swiat.h"
#include "Ekran.h"

int main() {
    Swiat swiat;
    auto organizm = new Organizm();
    swiat.dodajOrganizm(organizm);
    swiat.idz(*organizm, 5, 5);

    for (int i = 0; i < 10; i++) {
        system("clear");
        swiat.rysujSwiat();
        sleep(1);
        swiat.wykonajTure();

    }
    return 0;
}

