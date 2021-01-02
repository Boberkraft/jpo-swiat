//
// Created by johnny on 22/11/2020.
//

#include "Swiat.h"
#include "iostream"

Swiat::Swiat() {
    tura = 1;
};

void Swiat::wykonajTure() {
    weryfikujCzyWszystkoGit();
    ustawKolejnoscWalk();

    auto size = organizmy.size();
    for (int i = 0; i < size; i++) {
        auto organizm = organizmy[i];
        if (organizm->zyje) {
//            std::cout << "ruszam" << organizm->znak << std::endl;

            organizm->akcja();
        }
    }
    usunMartweOrganizmy();

    tura += 1;
    Ekran().instancja()->wstawTure(tura);
}


void Swiat::ustawKolejnoscWalk() {

    std::sort(organizmy.begin(),
              organizmy.end(),
              [](Organizm *a, Organizm *b) -> bool {
                  if (a->jakaInicjatywa() == b->jakaInicjatywa()) {
                      return a->wiek() > b->wiek();
                  }
                  return a->jakaInicjatywa() > b->jakaInicjatywa();
              }
    );
}

void Swiat::usunMartweOrganizmy() {
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

unsigned int Swiat::ktoraTura() {
    return tura;
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

Zwierze *Swiat::rozmnorz(Zwierze &pasywny, Zwierze &inicjator) {
    if (rozmnorz(reinterpret_cast<Organizm &>(pasywny), 1)) {
        auto komunikat = std::vector<std::string>();
        komunikat.push_back(pasywny.znak);
        komunikat.emplace_back("\U0001f495");
        Ekran::instancja()->wstawKomunikat(komunikat);
    }
}

Roslina *Swiat::rozmnorz(Roslina &roslina) {
    if (rozmnorz(reinterpret_cast<Organizm &>(roslina), 2)) {
        auto komunikat = std::vector<std::string>();
        komunikat.push_back(roslina.znak);
        komunikat.emplace_back("\U0001F4A6");
        Ekran::instancja()->wstawKomunikat(komunikat);
    }
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
    return dziecko;
}

bool Swiat::znajdzWolneMiejsceObok(unsigned int zasieg, Pozycja pozycja, Pozycja &wybranaPozycja) {
    int proby[100]{-2};

    int wybranyRzad, wybranaKolumna;
    for (int iloscProb = 0; iloscProb < zasieg; iloscProb++) {
        wybranyRzad = -1;
        wybranaKolumna = -1;

        int wylosowanyKierunek = rand() % ((zasieg * 2 + 1) * (zasieg * 2 + 1));
        for (int i = 0; i < iloscProb; i++) {
            if (wylosowanyKierunek == *proby) {
                continue;
            }
        }
        proby[iloscProb] = wylosowanyKierunek;

        int x = (wylosowanyKierunek / ((zasieg + 1) * 2) - zasieg / 2);
        int y = (wylosowanyKierunek % ((zasieg + 1) * 2) - zasieg / 2);
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

void Swiat::weryfikujCzyWszystkoGit() {
    int ilosc_zyjacych = 0;

    for(int i = 0; i < organizmy.size(); i++) {
        auto organizm = organizmy[i];
        if (organizm->zyje) {
            ilosc_zyjacych +=1;
        }
    }

    if (0 == ilosc_zyjacych || ilosc_zyjacych > 400) {
        throw "Ilosc Zyjacych zwierzat sie nie zgadza!";
    }
}

