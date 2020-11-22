//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ZWIERZE_H
#define JPO_SWIAT_ZWIERZE_H

#include "../Organizm.h"

class Zwierze: public Organizm {
    podstawową formę ruchu w metodzie akcja() → każde typowe zwierze w swojej turze
    przesuwa się na wybrane losowo, sąsiednie pole,

            rozmnażanie w ramach metody kolizja() → przy kolizji z organizmem tego samego gatunku
            nie dochodzi do walki, oba zwierzęta pozostają na swoich miejscach, koło nich pojawia się trzecie zwierze, tego samego gatunku.
};


#endif //JPO_SWIAT_ZWIERZE_H
