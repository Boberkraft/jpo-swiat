#include <iostream>

#include "Swiat.h"
#include "Ekran.h"

int main() {
    Swiat swiat;
    swiat.dodajOrganizm(new Organizm());
    swiat.rysujSwiat();
    return 0;
}

