//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_KOKA_H
#define JPO_SWIAT_KOKA_H


#include "../Roslina.h"

class Koka : public Roslina {
public:
    Koka();
    Organizm* dziecko();
    void kolizja(Organizm &wchodzacy);
};


#endif //JPO_SWIAT_KOKA_H
