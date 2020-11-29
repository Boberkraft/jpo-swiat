cmake_minimum_required(VERSION 3.17)
project(jpo_swiat)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        jpo_swiat
        src/Ekran/KolorowyZnak.cpp
        src/Ekran/KolorowyZnak.h
        src/organizmy/zwierzeta/Wilk.cpp
        src/organizmy/zwierzeta/Wilk.h
        src/organizmy/zwierzeta/Owca.cpp
        src/organizmy/zwierzeta/Owca.h
        src/organizmy/zwierzeta/Zmija.cpp
        src/organizmy/zwierzeta/Zmija.h
        src/organizmy/zwierzeta/Zaba.cpp
        src/organizmy/zwierzeta/Zaba.h
        src/organizmy/zwierzeta/Leniwiec.cpp
        src/organizmy/zwierzeta/Leniwiec.h
        src/organizmy/rosliny/Trawa.cpp
        src/organizmy/rosliny/Trawa.h
        src/organizmy/rosliny/Mlecz.cpp
        src/organizmy/rosliny/Mlecz.h
        src/organizmy/rosliny/Koka.cpp
        src/organizmy/rosliny/Koka.h
        src/organizmy/Zwierze.cpp
        src/organizmy/Zwierze.h
        src/organizmy/Roslina.cpp
        src/organizmy/Roslina.h
        src/Organizm.cpp
        src/Organizm.h
        src/main.cpp
        src/Swiat.cpp
        src/Swiat.h
        src/Ekran.cpp
        src/Ekran.h
)
target_link_libraries(jpo_swiat)
