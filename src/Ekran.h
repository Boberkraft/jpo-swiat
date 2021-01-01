//
// Created by johnny on 23/11/2020.
//

#ifndef JPO_SWIAT_EKRAN_H
#define JPO_SWIAT_EKRAN_H

#include <vector>
#include <string>
#include "Ekran/KolorowyZnak.h"
#include "Pozycja.h"

class Ekran {
private:
    std::string plansza[20][20];

    unsigned int tura;
    std::vector<std::vector<KolorowyZnak>> templatka;
    std::vector<std::vector<std::string>> komunikaty;
public:
    Ekran();

    void wstawZnak(std::string znak, Pozycja pozycja);

    void wyswietl();

    static Ekran *instancja();

    void wstawTure(unsigned int tura);

    void wstawKomunikat(std::vector<std::string> komunikat);
private:
    std::vector<std::vector<KolorowyZnak>> wygenerujTemplatka();

    std::vector<std::vector<KolorowyZnak>> wstawZnakiGracza(std::vector<std::vector<KolorowyZnak>>);

    void wyswietlBuffer(const std::vector<std::vector<KolorowyZnak>> &linie);

    std::vector<std::vector<KolorowyZnak>> wstawTure(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza);

    std::vector<std::vector<KolorowyZnak>> wstawKomunikaty(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza);
};

#endif //JPO_SWIAT_EKRAN_H
