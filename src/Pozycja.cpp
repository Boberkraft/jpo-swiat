//
// Created by johnny on 09/12/2020.
//

#include "Pozycja.h"

#include <cstdlib>

Pozycja::Pozycja() {
    _rzad = 0;
    _kolumna = 0;
}

Pozycja::Pozycja(int rzad, int kolumna) {
    int rem;

    rem = rzad % 20;
    _rzad = (rem >= 0) ? rem : rem + 20;

    rem = kolumna % 20;
    _kolumna = (rem >= 0) ? rem : rem + 20;
}

unsigned int Pozycja::rzad() {
    return _rzad;
}

unsigned int Pozycja::kolumna() {
    return _kolumna;
}

unsigned int Pozycja::jednowymiarowo() {
    return _rzad * 20 + _kolumna;
}

Pozycja *Pozycja::obok(unsigned int zakres) {
    unsigned int deltaRzad = 0;
    unsigned int deltaKolumna = 0;

    while (deltaRzad == 0 && deltaKolumna == 0) {

        deltaRzad = (rand() % (zakres * 2 + 1)) - zakres;
        deltaKolumna = (rand() % (zakres * 2 + 1)) - zakres;
    }

    return new Pozycja(_rzad + deltaRzad, _kolumna + deltaKolumna);
}

bool Pozycja::operator==(const Pozycja drugaPozycja) const {
    return _rzad == drugaPozycja._rzad && _kolumna == drugaPozycja._kolumna;
}
