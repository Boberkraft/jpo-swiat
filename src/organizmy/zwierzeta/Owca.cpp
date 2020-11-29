//
// Created by johnny on 22/11/2020.
//

#include "Owca.h"

Owca::Owca() {
    sila = 4;
    inicjatywa = 4;
    znak = "\U0001F411";
}

Organizm *Owca::dziecko() {
    return new Owca();
}
