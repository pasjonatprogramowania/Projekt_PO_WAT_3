cmake_minimum_required(VERSION 3.27)
project(Obiektowe)
project(Test)
set(CMAKE_CXX_STANDARD 23)
add_executable(Obiektowe main.cpp
        src/Istoty.cpp
        include/Istoty.h
        src/Postacie.cpp
        include/Postacie.h
        src/Przedmioty.cpp
        include/Przedmioty.h
        src/Struktury.cpp
        include/Struktury.h
        src/Pojazdy.cpp
        include/Pojazdy.h
        src/Logic/src/Board.cpp
        src/Logic/include/Board.h
        src/Logic/src/Point.cpp
        src/Logic/include/Point.h
        src/Logic/creature/src/Creature.cpp
        src/Logic/creature/include/Creature.h
        src/Logic/creature/src/CreatureStatistics.cpp
        src/Logic/creature/include/CreatureStatistics.h
        src/Logic/src/Range.cpp
        src/Logic/include/Range.h
)


add_executable(Test
        src/Test/Creature.cpp
        src/Test/Board.cpp
        src/Test/Point.cpp
        src/Test/Range.cpp
        src/Test/CreatureStatistics.cpp
        src/Test/main.cpp
)

