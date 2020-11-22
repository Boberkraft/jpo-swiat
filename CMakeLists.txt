cmake_minimum_required(VERSION 3.17)
project(jpo_swiat)

set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)

add_executable(jpo_swiat src/main.cpp src/Swiat.cpp src/Swiat.h src/Organizm.cpp src/Organizm.h src/organizm/Zwierze.cpp src/organizm/Zwierze.h src/organizm/Roslina.cpp src/organizm/Roslina.h src/organizm/zwierze/Wilk.cpp src/organizm/zwierze/Wilk.h src/organizm/zwierze/Owca.cpp src/organizm/zwierze/Owca.h src/organizm/zwierze/Zmija.cpp src/organizm/zwierze/Zmija.h src/organizm/zwierze/Zaba.cpp src/organizm/zwierze/Zaba.h src/organizm/zwierze/Leniwiec.cpp src/organizm/zwierze/Leniwiec.h src/organizm/roslina/Trawa.cpp src/organizm/roslina/Trawa.h src/organizm/roslina/Mlecz.cpp src/organizm/roslina/Mlecz.h src/organizm/roslina/Koka.cpp src/organizm/roslina/Koka.h)
target_link_libraries(jpo_swiat ${CURSES_LIBRARIES})
