//
// Created by johnny on 22/11/2020.
//

#include "Koka.h"

Koka::Koka() {
    znak = "\U0001F336 ";
}

Organizm *Koka::dziecko() {
    return new Koka();
}
