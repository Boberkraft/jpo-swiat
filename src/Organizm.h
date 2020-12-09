//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ORGANIZM_H
#define JPO_SWIAT_ORGANIZM_H

#include <vector>
#include <string>
#include "Pozycja.h"

class Swiat;

class Organizm {
protected:
    Swiat *swiat;
public:
    bool zyje;
    int sila;
    int inicjatywa;
    std::string znak;

    Organizm();

    virtual Organizm *dziecko() = 0;

    virtual void akcja() = 0;

    virtual void kolizja(Organizm &wchodzacy) = 0;

    virtual void rysowanie();

    void zarejestrujSwiat(Swiat *swiat);

    Pozycja pozycja;
};


#endif //JPO_SWIAT_ORGANIZM_H
