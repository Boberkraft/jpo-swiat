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
public:
    void wykonajTure();

    void rysujSwiat();

    void dodajOrganizm(Organizm *organizm);
};


#endif //JPO_SWIAT_SWIAT_H
