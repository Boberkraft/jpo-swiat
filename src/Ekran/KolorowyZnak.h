//
// Created by johnny on 28/11/2020.
//

#ifndef JPO_SWIAT_KOLOROWY_ZNAK_H
#define JPO_SWIAT_KOLOROWY_ZNAK_H

#include <string>

class KolorowyZnak {
private:
    std::string zawartosc;
    std::string kolor;
public:
    KolorowyZnak(std::string nowaZawartosc);

    KolorowyZnak &ustawZawartosc(std::string nowaZawartosc);

    KolorowyZnak &ustawKolor(std::string nowyKolor);

    std::string toString();
};


#endif //JPO_SWIAT_KOLOROWY_ZNAK_H
