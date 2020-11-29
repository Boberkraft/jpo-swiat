//
// Created by johnny on 23/11/2020.
//

#include "Ekran.h"
#include <stdio.h>

#include <utility>
#include "iostream"

Ekran::Ekran() {
    templatka = wygenerujTemplatka();
    for (auto &rzad : plansza) {
        for (auto &kolumna : rzad) {
            kolumna = "  ";
        }
    };
}

void Ekran::wstawZnak(std::string znak, int rzad, int kolumna) {
    plansza[rzad][kolumna] = znak;
}

void Ekran::wyswietl() {
    wyswietlBuffer(wstawZnakiGracza(templatka));
}

std::vector<std::vector<KolorowyZnak>> Ekran::wygenerujTemplatka() {
    std::vector<std::string> asciiPlansza;

    asciiPlansza.emplace_back("                                                                   \n");
    asciiPlansza.emplace_back(" 1xxxxxxxxxxxxxxxxxx3 ╔══════════════════════════════════════════╗ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx ║          Andrzej Bisewski 182619         ║ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx ╚══════════════════════════════════════════╝ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx  Tura: 19                                    \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back("                                                                   \n");

    std::vector<std::vector<KolorowyZnak>> kolorowaPlansza;

    for (std::string rzad : asciiPlansza) {
        std::vector<KolorowyZnak> kolorowaLinia;
        for (char kolumna : rzad) {
            kolorowaLinia.emplace_back(KolorowyZnak(std::string(1, kolumna)));
        }
        kolorowaPlansza.emplace_back(kolorowaLinia);
    }

    const unsigned int RZAD_MAPY = 1;
    const unsigned int KOLUMNA_MAPY = 1;
    const std::string colors[] = {"22", "22", "22", "22", "58", "28"};
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            int v1 = rand() % 6;
            auto color = colors[v1];
            kolorowaPlansza[RZAD_MAPY + rzad][KOLUMNA_MAPY + kolumna].ustawKolor(color);
        }
    };


    return kolorowaPlansza;
}

std::vector<std::vector<KolorowyZnak>> Ekran::wstawZnakiGracza(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza) {
    const unsigned int RZAD_MAPY = 1;
    const unsigned int KOLUMNA_MAPY = 1;
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            kolorowaPlansza[RZAD_MAPY + rzad][KOLUMNA_MAPY + kolumna].ustawZawartosc(plansza[rzad][kolumna]);
        }
    };

    return kolorowaPlansza;
}

void Ekran::wyswietlBuffer(const std::vector<std::vector<KolorowyZnak>> &linie) {
    for (const auto &linia : linie) {
        for (auto znak : linia) {
            std::cout << znak.toString();
        }
    }
    std::cout.flush();
    for (auto &rzad : plansza) {
        for (auto &kolumna : rzad) {
            kolumna = "⠀ ";
        }
    };
};

Ekran *Ekran::instancja() {
    static Ekran instancja;
    return &instancja;
}
