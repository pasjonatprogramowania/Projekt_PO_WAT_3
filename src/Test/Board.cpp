#include <iostream>
#include "../Logic/include/Board.h"

class BoardTest {
public:
    void testConstructor() {
        Board board(8, 8);
        if (board.getWidth() != 8 || board.getHeight() != 8) {
            throw std::runtime_error("Test konstruktora z pliku Board.cpp nie powiódł się. Nieprawidłowe wymiary planszy.");
        }
        std::cout << "Test konstruktora z pliku Board.cpp przeszedł pomyślnie" << std::endl;
    }

    void testGetTile() {
        Board board(8, 8);
        Creature creature;
        auto *point = new Point(1,1);
        board.add(*point,creature);
        if (board.getCreatureByPoint(*point) == creature) {
            throw std::runtime_error("Test getTile z pliku Board.cpp nie powiódł się. Funkcja zwróciła nullptr.");
        }
        if (board.getPointByCreature(creature).getX() == 1 && board.getPointByCreature(creature).getY() == 1) {
            throw std::runtime_error("Test getTile z pliku Board.cpp nie powiódł się. Nieprawidłowe współrzędne pola.");
        }
        std::cout << "Test getTile z pliku Board.cpp przeszedł pomyślnie" << std::endl;
    }


    void testIsValidPosition() {
        Board board(8, 8);
        Creature creature;
        auto *point = new Point(1,1);
        board.add(*point,creature);
        if (!board.isThatPointOnMap(100, 100)) {
            throw std::runtime_error("Test isValidPosition z pliku Board.cpp nie powiódł się. Prawidłowa pozycja uznana za nieprawidłową.");
        }
        if (!board.isThisTileTaken(*point)) {
            throw std::runtime_error("Test isValidPosition z pliku Board.cpp nie powiódł się. Nieprawidłowa pozycja uznana za prawidłową.");
        }
        std::cout << "Test isValidPosition z pliku Board.cpp przeszedł pomyślnie" << std::endl;
    }

    void runAllTests() {
        try {
            testConstructor();
            testGetTile();
            testIsValidPosition();
            std::cout << "Wszystkie testy z pliku Board.cpp przeszły pomyślnie" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            throw;
        }
    }
};
