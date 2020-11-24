//
// Created by johnny on 23/11/2020.
//

#include "Ekran.h"
#include <stdio.h>
#include "iostream"

Ekran::Ekran() {
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            plansza[rzad][kolumna] = "  ";
        }
    };
}

void Ekran::wstawZnak(std::string znak, int rzad, int kolumna) {
    plansza[rzad][kolumna] = znak;
}

void Ekran::wyswietl() {
    std::vector<std::string> asciLinie;

    asciLinie.emplace_back("                                                                   \n");
    asciLinie.emplace_back(" 1xxxxxxxxxxxxxxxxxx3 ╔══════════════════════════════════════════╗ \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx ║          Andrzej Bisewski 182619         ║ \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx ╚══════════════════════════════════════════╝ \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx  Tura: 19                                    \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciLinie.emplace_back("                                                                   \n");



    std::vector<std::vector<std::string>> utfLinie;

    for(std::string linia : asciLinie) {
         std::vector<std::string> nowyLinia;
        for (char znak : linia) {
            nowyLinia.emplace_back(std::string(1, znak));
        }
        utfLinie.emplace_back(nowyLinia);
    }

    const unsigned int RZAD_MAPY = 1;
    const unsigned int KOLUMNA_MAPY = 1;
    const std::string colors [] = { "22", "23", "35", "58" , "28"};
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            int v1 = rand() % 5;
            auto color = colors[v1];
            utfLinie[RZAD_MAPY + rzad][KOLUMNA_MAPY + kolumna] = "\033[48;5;" + color + "m" + plansza[rzad][kolumna] + "\e[0m";
        }
    };

    wyswietlBuffer(utfLinie);
}

void Ekran::wyswietlBuffer(std::vector<std::vector<std::string>> linie) {


    for (auto linia : linie) {
        for (auto znak : linia) {
//            std::cout << "\e[0;39;102m" << znak << "\e[0m";
            std::cout <<  znak;
        }
    }
    std::cout.flush();
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            plansza[rzad][kolumna] = "⠀";
        }
    };
};

Ekran *Ekran::instancja() {
    static Ekran instancja;
    return &instancja;
}
