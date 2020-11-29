#include <iostream>
#include <zconf.h>

#include "Swiat.h"
#include "Ekran.h"
#include "organizmy/Zwierze.h"

int main() {
    Swiat swiat;
    auto zwierze1 = new Zwierze();
    auto zwierze2 = new Zwierze();
    swiat.dodajOrganizm(zwierze1);
    swiat.dodajOrganizm(zwierze2);
    swiat.idz(*zwierze1, 5, 5);
    swiat.idz(*zwierze2, 5, 6);

    swiat.rozmnorz(*zwierze1, *zwierze2);
    for (int i = 0; i < 10; i++) {
        system("clear");
        swiat.rysujSwiat();
        sleep(1);
        swiat.wykonajTure();

    }
    return 0;
}

