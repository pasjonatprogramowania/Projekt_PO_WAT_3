#include <iostream>
#include "../Logic/include/Range.h"

using namespace std;
class RangeTest {
public:
    static void testConstructor() {
        Range r(2, 5);
        if (r.getLowerPoint() != 2 || r.getUpperPoint() != 5) {
            throw runtime_error("Range.cpp - Test konstruktora z pliku Range.cpp nie powiódł się. Nieprawidłowe wartości pól obiektu.");
        }
    }

    static void testDefaultConstructor() {
        Range r;
        if (r.getLowerPoint() != 0 || r.getUpperPoint() != 0) {
            throw runtime_error("Range.cpp - Test konstruktora domyślnego z pliku Range.cpp nie powiódł się. Nieprawidłowe wartości pól obiektu.");
        }
    }

    static void testGetLowerPoint() {
        Range r(2, 5);
        if (r.getLowerPoint() != 2) {
            throw runtime_error("Range.cpp - Test metody getLowerPoint z pliku Range.cpp nie powiódł się. Nieprawidłowa wartość dolnego punktu.");
        }
    }

    static void testGetUpperPoint() {
        Range r(2, 5);
        if (r.getUpperPoint() != 5) {
            throw runtime_error("Range.cpp - Test metody getUpperPoint z pliku Range.cpp nie powiódł się. Nieprawidłowa wartość górnego punktu.");
        }
    }

    static void runAllTests() {
        try {
            testConstructor();
            testDefaultConstructor();
            testGetLowerPoint();
            testGetUpperPoint();
            cout << "### Wszystkie testy z pliku Range.cpp przeszły pomyślnie ###" << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};
