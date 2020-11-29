//
// Created by johnny on 22/11/2020.
//

#include "Swiat.h"

#include "iostream"
void Swiat::wykonajTure() {
    for (auto organizm : organizmy) {
        organizm->akcja();
    }
}

void Swiat::rysujSwiat() {
    for (auto organizm : organizmy) {
        organizm->rysowanie();
    }
    Ekran::instancja()->wyswietl();
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
    organizm->zarejestrujSwiat(*this);
}

void Swiat::idz(Organizm &ruszajacySie, int rzad, int kolumna) {
    rzad = korygatorWspolrzednej(rzad);
    kolumna = korygatorWspolrzednej(kolumna);

    auto stojacy = znajdz(rzad, kolumna);

    if (stojacy) {
        stojacy->kolizja(ruszajacySie);
    } else {
        ruszajacySie.rzad = rzad;
        ruszajacySie.kolumna = kolumna;
    }
}

Organizm *Swiat::znajdz(int rzad, int kolumna) {
    rzad = korygatorWspolrzednej(rzad);
    kolumna = korygatorWspolrzednej(kolumna);

    for (auto organizm : organizmy) {
        if (organizm->rzad == rzad && organizm->kolumna == kolumna) {
            return organizm;
        }
    }
    return nullptr;
}

int Swiat::korygatorWspolrzednej(int wspolrzedna) {
    if (wspolrzedna >= 20) {
        return 0;
    } else if (wspolrzedna < 0) {
        return 19;
    } else {
        return wspolrzedna;
    }
}

Organizm *Swiat::rozmnorz(Organizm &pasywny, Organizm &inicjator) {
    int rzad = pasywny.rzad;
    int kolumna = pasywny.kolumna;

    int wolnyRzad, wolnaKolumna;
    bool znalezionoWolneMiejsce = znajdzWolneMiejsceObok(rzad, kolumna, wolnyRzad, wolnaKolumna);

    if (!znalezionoWolneMiejsce) {
        return nullptr;
    }

    auto dziecko = pasywny.dziecko();
    dodajOrganizm(dziecko);
    std::cout<<"Spawn{"<<wolnyRzad<<","<<wolnaKolumna<<"}"<<std::endl;

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
    auto it = std::find(organizmy.begin(), organizmy.end(), &organizm);
    organizmy.erase(it);
    std::cout << "ZABIJAM!" << std::endl;
    assert(1 == 2);
    delete &organizm;
}
