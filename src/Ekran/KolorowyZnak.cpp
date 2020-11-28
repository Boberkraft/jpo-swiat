//
// Created by johnny on 28/11/2020.
//

#include "KolorowyZnak.h"

KolorowyZnak::KolorowyZnak(std::string nowaZawartosc) {
    kolor = "";
    ustawZawartosc(nowaZawartosc);
}

KolorowyZnak &KolorowyZnak::ustawZawartosc(std::string nowaZawartosc) {
    zawartosc = nowaZawartosc;
    return *this;
}

KolorowyZnak &KolorowyZnak::ustawKolor(std::string nowyKolor) {
    kolor = nowyKolor;
    return *this;
}

std::string KolorowyZnak::toString() {
    std::string doWypisania;

//    if (zawartosc.size() == 0) {
//        doWypisania = "  ";
//    } else if (zawartosc.size() == 1) {
//        doWypisania = zawartosc + " ";
//    } else {
//        doWypisania = zawartosc;
//    }

    doWypisania = zawartosc;
    if (kolor.empty()) {
        return doWypisania;
    } else {
        return "\033[48;5;" + kolor + "m" + doWypisania + "\e[0m";
    }

}
