#include <iostream>
#include "../Logic/include/Range.h"

using namespace std;
class RangeTest {
public:
    static void testConstructor() {
        Range r(2, 5);
        if (r.getLowerPoint() != 2 || r.getUpperPoint() != 5) {
            throw runtime_error("Range.cpp - Test konstruktora z pliku Range.cpp nie powiodl sie. Nieprawidlowe wartosci pol obiektu.");
        }
    }

    static void testDefaultConstructor() {
        Range r;
        if (r.getLowerPoint() != 0 || r.getUpperPoint() != 0) {
            throw runtime_error("Range.cpp - Test konstruktora domyslnego z pliku Range.cpp nie powiodl sie. Nieprawidlowe wartosci pol obiektu.");
        }
    }

    static void testGetLowerPoint() {
        Range r(2, 5);
        if (r.getLowerPoint() != 2) {
            throw runtime_error("Range.cpp - Test metody getLowerPoint z pliku Range.cpp nie powiodl sie. Nieprawidlowa wartosc dolnego punktu.");
        }
    }

    static void testGetUpperPoint() {
        Range r(2, 5);
        if (r.getUpperPoint() != 5) {
            throw runtime_error("Range.cpp - Test metody getUpperPoint z pliku Range.cpp nie powiodl sie. Nieprawidlowa wartosc gornego punktu.");
        }
    }

    static void runAllTests() {
        try {
            testConstructor();
            testDefaultConstructor();
            testGetLowerPoint();
            testGetUpperPoint();
            cout << "### Wszystkie testy z pliku Range.cpp przeszly pomyslnie ###" << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};
