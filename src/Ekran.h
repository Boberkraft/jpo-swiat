//
// Created by johnny on 23/11/2020.
//

#ifndef JPO_SWIAT_EKRAN_H
#define JPO_SWIAT_EKRAN_H

#include <vector>
#include <string>
#include "Ekran/KolorowyZnak.h"

class Ekran {
private:
    std::string plansza[20][20];

    std::vector<std::vector<KolorowyZnak>> templatka;
public:
    Ekran();

    void wstawZnak(std::string znak, int rzad, int kolumna);

    void wyswietl();

    static Ekran *instancja();

private:
    std::vector<std::vector<KolorowyZnak>> wygenerujTemplatka();

    std::vector<std::vector<KolorowyZnak>> wstawZnakiGracza(std::vector<std::vector<KolorowyZnak>>);

    void wyswietlBuffer(const std::vector<std::vector<KolorowyZnak>> &linie);
};

#endif //JPO_SWIAT_EKRAN_H
