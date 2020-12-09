//
// Created by johnny on 09/12/2020.
//

#ifndef JPO_SWIAT_POZYCJA_H
#define JPO_SWIAT_POZYCJA_H


class Pozycja {
private:
    unsigned int _rzad;
    unsigned int _kolumna;
public:
    Pozycja();

    Pozycja(int rzad, int kolumna);

    bool operator==(const Pozycja) const;

    unsigned int rzad();

    unsigned int kolumna();

    unsigned int jednowymiarowo();

    Pozycja *obok(unsigned int zakres);
};


#endif //JPO_SWIAT_POZYCJA_H
