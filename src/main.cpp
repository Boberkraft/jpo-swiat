#include <iostream>
#include <zconf.h>

#include "Swiat.h"
#include "Ekran.h"
#include "organizmy/zwierzeta/Wilk.h"
#include "organizmy/zwierzeta/Owca.h"

int main() {
    Swiat swiat;
    auto wilk1 = new Wilk();
    auto wilk2 = new Wilk();
    auto owca1 = new Owca();
    swiat.dodajOrganizm(wilk1);
    swiat.dodajOrganizm(wilk2);
    swiat.dodajOrganizm(owca1);
    swiat.idz(*wilk1, 5, 5);
    swiat.idz(*wilk2, 5, 6);
    swiat.idz(*owca1, 3, 3);
    swiat.rozmnorz(*wilk1, *wilk2);
    for (int i = 0; i < 10; i++) {
        system("clear");
        swiat.rysujSwiat();
        sleep(1);
        swiat.wykonajTure();

    }
    return 0;
}

