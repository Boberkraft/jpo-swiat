//
// Created by johnny on 23/11/2020.
//

#ifndef JPO_SWIAT_EKRAN_H
#define JPO_SWIAT_EKRAN_H

#include <vector>
#include <string>

class Ekran {
private:
    std::string plansza[20][20];
public:
    Ekran();

    void wstawZnak(std::string znak, int rzad, int kolumna);

    void wyswietl();

    static Ekran *instancja();

private:
    void wyswietlBuffer(std::vector<std::vector<std::string>> linie);
};


#endif //JPO_SWIAT_EKRAN_H
