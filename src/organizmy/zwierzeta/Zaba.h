//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ZABA_H
#define JPO_SWIAT_ZABA_H


#include "../Zwierze.h"

class Zaba : public Zwierze {
public:
    Zaba();
    Organizm* dziecko();
    void akcja();

    void kolizja(Zwierze &wchodzacy);
};


#endif //JPO_SWIAT_ZABA_H
