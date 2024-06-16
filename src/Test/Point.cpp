#include <iostream>
#include "../Logic/include/Point.h"

class PointTest {
public:
    static void testConstructor() {
        Point p(3, 5);
        if (p.getX() != 3 || p.getY() != 5) {
            throw std::runtime_error("Point.cpp - Test konstruktora z pliku Point.cpp nie powiódł się. Nieprawidłowe wartości pól obiektu.");
        }
    }

    static void testDistance() {
        Point p1(0, 0);
        Point p2(3, 4);
        double expectedDistance = 5.0;
        double actualDistance = p1.distance(p2);
        if (std::abs(actualDistance - expectedDistance) > 0.001) {
            throw std::runtime_error("Point.cpp - Test metody distance z pliku Point.cpp nie powiódł się. Nieprawidłowa wartość odległości.");
        }
    }

    static void testLessThanOperator() {
        Point p1(1, 2);
        Point p2(2, 1);
        Point p3(1, 3);
        if (!(p1 < p2) || !(p1 < p3)) {
            throw std::runtime_error("Point.cpp - Test operatora < z pliku Point.cpp nie powiódł się. Nieprawidłowe porównanie punktów.");
        }
    }

    static void testEqualityOperator() {
        Point p1(1, 2);
        Point p2(1, 2);
        Point p3(3, 4);
        if (!(p1 == p2) || p1 == p3) {
            throw std::runtime_error("Point.cpp - Test operatora == z pliku Point.cpp nie powiódł się. Nieprawidłowe porównanie punktów.");
        }
    }

    static void testInequalityOperator() {
        Point p1(1, 2);
        Point p2(1, 2);
        Point p3(3, 4);
        if (p1 != p2 || !(p1 != p3)) {
            throw std::runtime_error("Point.cpp - Test operatora != z pliku Point.cpp nie powiódł się. Nieprawidłowe porównanie punktów.");
        }
    }

    static void runAllTests() {
        try {
            testConstructor();
            testDistance();
            testLessThanOperator();
            testEqualityOperator();
            testInequalityOperator();
            std::cout << "### Wszystkie testy z pliku Point.cpp przeszły pomyślnie ###" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            throw;
        }
    }
};
