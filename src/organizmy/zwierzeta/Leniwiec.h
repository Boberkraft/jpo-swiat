//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_LENIWIEC_H
#define JPO_SWIAT_LENIWIEC_H


#include "../Zwierze.h"

class Leniwiec : public Zwierze {
    bool spi;
public:
    Leniwiec();
    Organizm* dziecko();
    void akcja();
};


#endif //JPO_SWIAT_LENIWIEC_H
