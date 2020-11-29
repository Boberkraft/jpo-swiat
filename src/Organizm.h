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
    Swiat *swiat;
public:
    int sila;
    int inicjatywa;
    std::string znak;
    Organizm();

    virtual Organizm* podobnaInstacja() = 0;
    virtual void akcja() = 0;

    virtual void kolizja(Organizm &wchodzacy) = 0;

    virtual void rysowanie();

    void zarejestrujSwiat(Swiat &swiat);

    int rzad;
    int kolumna;
};


#endif //JPO_SWIAT_ORGANIZM_H
