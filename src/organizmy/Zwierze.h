//
// Created by johnny on 22/11/2020.
//

#ifndef JPO_SWIAT_ZWIERZE_H
#define JPO_SWIAT_ZWIERZE_H

#include "../Organizm.h"

class Zwierze : public Organizm {
protected:
    bool podwojnyRuch;
public:
    Zwierze();

    void akcja() ;

    void kolizja(Organizm &wchodzacy);

    virtual void kolizja(Zwierze &wchodzacy);

    void dajBuffaPodwojnegoRuchu();
};


#endif //JPO_SWIAT_ZWIERZE_H
