//
// Created by johnny on 22/11/2020.
//

#include "Zwierze.h"
//
//
//podstawową formę ruchu w metodzie akcja() → każde typowe zwierze w swojej turze
//przesuwa się na wybrane losowo, sąsiednie pole,
//
//        rozmnażanie w ramach metody kolizja() → przy kolizji z organizmem tego samego gatunku
//        nie dochodzi do walki, oba zwierzęta pozostają na swoich miejscach, koło nich pojawia się trzecie zwierze, tego samego gatunku.


Zwierze::Zwierze() {
    znak = "\U0001F343";
//    znak = "\U0001F43E"; roslina

}

//void Zwierze::akcja() {
//
//}
//
//void Zwierze::kolizja() {
//
//}