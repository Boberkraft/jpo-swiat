//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ROSLINA_H
#define JPO_SWIAT_ROSLINA_H

#include "../Organizm.h"

class Roslina : public Organizm {
public:
    Roslina();

    void akcja();

    void kolizja(Organizm &wchodzacy);
};


#endif //JPO_SWIAT_ROSLINA_H
