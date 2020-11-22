//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ORGANIZM_H
#define JPO_SWIAT_ORGANIZM_H


class Organizm {
protected:
    int sila;
    int inicjatywa;
    int posX;
    int posY;
    Swiat *swiat;
public:
    virtual void akcja();

    virtual void kolizja();

    virtual void rysowanie();
};


#endif //JPO_SWIAT_ORGANIZM_H
