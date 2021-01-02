//
// Created by johnny on 22/11/2020.
//

#include "Trawa.h"


Trawa::Trawa() {
    znak = "\U0001F33E";
}

Organizm *Trawa::dziecko() {
    return new Trawa();
}

