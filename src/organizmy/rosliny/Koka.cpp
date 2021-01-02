//
// Created by johnny on 22/11/2020.
//

#include "Koka.h"
#include "../Zwierze.h"

Koka::Koka() {
    znak = "\U0001F344";
}

Organizm *Koka::dziecko() {
    return new Koka();
}

void Koka::kolizja(Organizm &wchodzacy) {
    reinterpret_cast<Zwierze &>(wchodzacy).dajBuffaPodwojnegoRuchu();
    Roslina::kolizja(wchodzacy);
}

