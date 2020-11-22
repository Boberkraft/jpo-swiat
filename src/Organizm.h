//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ORGANIZM_H
#define JPO_SWIAT_ORGANIZM_H


class Organizm {
protected:
    siła
    inicjatywa
    polozenie (x,y)
    świat
public:
    virtual void akcja() = 0;
    virtual void kolizja() = 0;
    virtual void rysowanie() = 0;
};


#endif //JPO_SWIAT_ORGANIZM_H
