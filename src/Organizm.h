//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ORGANIZM_H
#define JPO_SWIAT_ORGANIZM_H

#include "Swiat.h"
#include "Ekran.h"

class Swiat;

class Organizm {
protected:
    int sila;
    int inicjatywa;
    int kolumna;
    int rzad;
    std::string znak;
    Swiat *swiat;
public:
    Organizm();

    virtual void akcja();

    virtual void kolizja();

    virtual void rysowanie();

    void zarejestrujSwiat(Swiat &swiat);
};


#endif //JPO_SWIAT_ORGANIZM_H
