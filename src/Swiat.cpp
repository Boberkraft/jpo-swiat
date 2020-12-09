//
// Created by johnny on 22/11/2020.
//

#include "Swiat.h"
#include "iostream"

void Swiat::wykonajTure() {
    for (auto &organizm : organizmy) {
//        std::cout << "ruszam" << organizm << std::endl;
        if (organizm->zyje) {
            organizm->akcja();
        }
    }
    organizmy.erase(
            std::remove_if(
                    organizmy.begin(),
                    organizmy.end(),
                    [](Organizm *organizm) -> bool {
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
//    std::cout << "Umieszczam w wektorze" << organizm << std::endl;
    organizmy.push_back(organizm);
    organizm->zarejestrujSwiat(this);
}

void Swiat::idz(Organizm &ruszajacySie, Pozycja pozycja) {
    auto stojacy = znajdz(pozycja);

    if (stojacy == &ruszajacySie) {
        return; // LOL XD
    }

    if (stojacy) {
//        std::cout << "BITKA " << &ruszajacySie << std::endl;
        stojacy->kolizja(ruszajacySie);
    } else {
        ruszajacySie.pozycja = pozycja;
    }
}

Organizm *Swiat::znajdz(Pozycja pozycja) {

    for (auto organizm : organizmy) {
        if (organizm->zyje && organizm->pozycja == pozycja) {
            return organizm;
        }
    }
    return nullptr;
}

unsigned int Swiat::korygatorWspolrzednej(int wspolrzedna) {

}

Zwierze *Swiat::rozmnorz(Zwierze &pasywny, Zwierze &inicjator) {
    rozmnorz(reinterpret_cast<Organizm &>(pasywny), 2);
}

Roslina *Swiat::rozmnorz(Roslina &roslina) {
    rozmnorz(reinterpret_cast<Organizm &>(roslina), 2);
}

Organizm *Swiat::rozmnorz(Organizm &organizm, unsigned int zasieg) {
    Pozycja wolnaPozycja;
    bool znalezionoWolneMiejsce = znajdzWolneMiejsceObok(zasieg,
                                                         organizm.pozycja,
                                                         wolnaPozycja);
    if (!znalezionoWolneMiejsce) {
        return nullptr;
    }

    Organizm *dziecko = organizm.dziecko();
    dodajOrganizm(dziecko);
    idz(*dziecko, wolnaPozycja);
}

bool Swiat::znajdzWolneMiejsceObok(unsigned int zasieg, Pozycja pozycja, Pozycja &wybranaPozycja) {
    int proby[100]{-2};

    int wybranyRzad, wybranaKolumna;
    for (int iloscProb = 0; iloscProb < zasieg; iloscProb++) {
        wybranyRzad = -1;
        wybranaKolumna = -1;

        int wylosowanyKierunek = rand() % ((zasieg*2 + 1) * (zasieg*2 + 1));
        for (int i = 0; i < iloscProb; i++) {
            if (wylosowanyKierunek == *proby) {
                continue;
            }
        }
        proby[iloscProb] = wylosowanyKierunek;

        int x =  (wylosowanyKierunek / ((zasieg + 1) * 2) - zasieg/2);
        int y =  (wylosowanyKierunek % ((zasieg + 1) * 2) - zasieg/2);
        wybranaPozycja = Pozycja(pozycja.rzad() + x, pozycja.kolumna() + y);

        Organizm *zajety = znajdz(wybranaPozycja);

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
