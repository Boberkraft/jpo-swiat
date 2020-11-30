//
// Created by johnny on 22/11/2020.
//

#include "Swiat.h"
#include "iostream"

void Swiat::wykonajTure() {
    for (auto &organizm : organizmy) {
        std::cout << "ruszam" << organizm << std::endl;
        if (organizm->zyje) {
            organizm->akcja();
        }
    }
    organizmy.erase(
            std::remove_if(
                    organizmy.begin(),
                    organizmy.end(),
                    [](Organizm* organizm) -> bool {
                        return !organizm->zyje;
                    }
            ),
            organizmy.end()
    );
}

void Swiat::rysujSwiat() {
    for (auto organizm : organizmy) {
        organizm->rysowanie();
    }
    Ekran::instancja()->wyswietl();
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    std::cout << "Umieszczam w wektorze" << organizm << std::endl;
    organizmy.push_back(organizm);
    organizm->zarejestrujSwiat(this);
}

void Swiat::idz(Organizm &ruszajacySie, int rzad, int kolumna) {
    rzad = korygatorWspolrzednej(rzad);
    kolumna = korygatorWspolrzednej(kolumna);

    auto stojacy = znajdz(rzad, kolumna);

    if (stojacy == &ruszajacySie) {
        return; // LOL XD
    }

    if (stojacy) {
        std::cout << "BITKA " << &ruszajacySie << std::endl;
        stojacy->kolizja(ruszajacySie);
    } else {
        std::cout << "Ide " << &ruszajacySie << std::endl;
        ruszajacySie.rzad = rzad;
        ruszajacySie.kolumna = kolumna;
    }
}

Organizm *Swiat::znajdz(int rzad, int kolumna) {
    rzad = korygatorWspolrzednej(rzad);
    kolumna = korygatorWspolrzednej(kolumna);

    for (auto organizm : organizmy) {
        if (organizm->zyje && organizm->rzad == rzad && organizm->kolumna == kolumna) {
            return organizm;
        }
    }
    return nullptr;
}

unsigned int Swiat::korygatorWspolrzednej(int wspolrzedna) {
    int rem = wspolrzedna % 20;
    rem = (rem >= 0) ? rem : rem + 20;
    return rem;
}

Zwierze *Swiat::rozmnorz(Zwierze &pasywny, Zwierze &inicjator) {
    rozmnorz(reinterpret_cast<Organizm &>(pasywny));
}

Roslina *Swiat::rozmnorz(Roslina &roslina) {
    rozmnorz(reinterpret_cast<Organizm &>(roslina));
}

Organizm *Swiat::rozmnorz(Organizm &organizm) {
    int rzad = organizm.rzad;
    int kolumna = organizm.kolumna;

    int wolnyRzad, wolnaKolumna;
    bool znalezionoWolneMiejsce = znajdzWolneMiejsceObok(rzad, kolumna, wolnyRzad, wolnaKolumna);

    if (!znalezionoWolneMiejsce) {
        return nullptr;
    }

    Organizm *dziecko = organizm.dziecko();
    dodajOrganizm(dziecko);
    idz(*dziecko, wolnyRzad, wolnaKolumna);
}

bool Swiat::znajdzWolneMiejsceObok(int rzad, int kolumna, int &wybranyRzad, int &wybranaKolumna) {
    int proby[4]{-2};

    for (int iloscProb = 0; iloscProb < 4; iloscProb++) {
        wybranyRzad = -1;
        wybranaKolumna = -1;

        int wylosowanyKierunek = rand() % 4;
        for (int i = 0; i < iloscProb; i++) {
            if (wylosowanyKierunek == *proby) {
                continue;
            }
        }
        proby[iloscProb] = wylosowanyKierunek;

        switch (wylosowanyKierunek) {
            case 0:
                wybranyRzad = rzad - 1;
                wybranaKolumna = kolumna;
                break;
            case 1:
                wybranyRzad = rzad + 1;
                wybranaKolumna = kolumna;
                break;
            case 2:
                wybranyRzad = rzad;
                wybranaKolumna = kolumna - 1;
                break;
            case 3:
                wybranyRzad = rzad;
                wybranaKolumna = kolumna + 1;
                break;
        }

        wybranyRzad = korygatorWspolrzednej(wybranyRzad);
        wybranaKolumna = korygatorWspolrzednej(wybranaKolumna);
        Organizm *zajety = znajdz(wybranyRzad, wybranaKolumna);

        if (zajety) {
            continue;
        } else {
            return true; // OK!
        }
    }
    return false;
}

void Swiat::zabij(Organizm &organizm) {
    organizm.zyje = false;
}
