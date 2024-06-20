#include <iostream>
#include "../Logic/include/Board.h"
using namespace std;
class BoardTest {
public:
    static void testConstructor() {
        Board board(8, 8);
        if (board.getWidth() != 8 || board.getHeight() != 8) {
            throw runtime_error("TestBoard.cpp - Test konstruktora z pliku TestBoard.cpp nie powiódł się. Nieprawidłowe wymiary planszy.");
        }
    }

    static void testGetTile() {
        Board board(8, 8);
        Creature creature;
        auto point = new Point(1, 1);
        board.add(*point,creature);
        if (board.getCreatureByPoint(*point).stats != creature.stats) {
            throw runtime_error("TestBoard.cpp - Test getTile z pliku TestBoard.cpp nie powiódł się. Funkcja zwróciła nullptr.");
        }
        if (board.getPointByCreature(creature).getX() != 1 || board.getPointByCreature(creature).getY() != 1) {
            throw runtime_error("TestBoard.cpp - Test getTile z pliku TestBoard.cpp nie powiódł się. Nieprawidłowe współrzędne pola.");
        }
    }


    static void testIsValidPosition() {
        Board board(8, 8);
        Creature creature;
        auto *point = new Point(1, 1);
        board.add(*point,creature);
        if (board.isThatPointOnMap(100, 100)) {
            throw runtime_error("TestBoard.cpp - Test isValidPosition z pliku TestBoard.cpp nie powiódł się. Prawidłowa pozycja uznana za nieprawidłową.");
        }
        if (!board.isThisTileTaken(*point)) {
            throw runtime_error("TestBoard.cpp - Test isValidPosition z pliku TestBoard.cpp nie powiódł się. Nieprawidłowa pozycja uznana za prawidłową.");
        }
    }

    static void runAllTests() {
        try {
            testConstructor();
            testGetTile();
            testIsValidPosition();
            cout << "### Wszystkie testy z pliku TestBoard.cpp przeszły pomyślnie ###" << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};
