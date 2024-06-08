cmake_minimum_required(VERSION 3.27)
project(Obiektowe)

set(CMAKE_CXX_STANDARD 23)

add_executable(Obiektowe main.cpp
        UI/main.cpp
        UI/main.h
        src/Istoty.cpp
        include/Istoty.h
        src/Postacie.cpp
        include/Postacie.h
        src/Przedmioty.cpp
        include/Przedmioty.h
        src/Struktury.cpp
        include/Struktury.h
        src/Pojazdy.cpp
        include/Pojazdy.h)
