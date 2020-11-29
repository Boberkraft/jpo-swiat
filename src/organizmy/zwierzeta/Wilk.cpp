//
// Created by johnny on 22/11/2020.
//

#include "Wilk.h"

Wilk::Wilk() {
    znak = "\U0001F415";
}

Organizm *Wilk::dziecko() {
    return new Wilk();
}
