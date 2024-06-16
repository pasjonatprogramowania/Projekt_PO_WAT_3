#include <iostream>
#include "../Logic/Creature/include/Creature.h"
using namespace std;
class CreatureTest {
public:
    static void testConstructor() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        if (creature.getName() != "Test creature" ||
            creature.getAttack() != 10 ||
            creature.getArmor() != 5 ||
            creature.getMaxHp() != 100 ||
            creature.getCurrentHp() != 100 ||
            creature.getMoveRange() != 3 ||
            creature.getDamage().getLowerPoint() != 5 ||
            creature.getDamage().getUpperPoint() != 10 ||
            creature.getAmount() != 2 ||
            creature.getAttackRange() != 1) {
            throw runtime_error(
                    "Creature.cpp - Test konstruktora z pliku creature.cpp nie powiódł się. Nieprawidłowe wartości pól obiektu.");
        }
    }

    static void testApplyDamage() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        creature.applyDamage(50);
        if (creature.getCurrentHp() != 50 || creature.getAmount() != 2) {
            throw runtime_error(
                    "Creature.cpp - Test applyDamage z pliku creature.cpp nie powiódł się. Nieprawidłowe wartości po zastosowaniu obrażeń.");
        }
    }

    static void testIsAlive() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        if (!creature.isAlive()) {
            throw runtime_error(
                    "Creature.cpp - Test isAlive z pliku creature.cpp nie powiódł się. Stworzenie powinno być żywe po utworzeniu.");
        }
        creature.applyDamage(200);
        if (creature.isAlive()) {
            throw runtime_error(
                    "Creature.cpp - Test isAlive z pliku creature.cpp nie powiódł się. Stworzenie powinno być martwe po otrzymaniu śmiertelnych obrażeń.");
        }
    }

    static void runAllTests() {
        try {
            testConstructor();
            testApplyDamage();
            testIsAlive();
            cout << "### Wszystkie testy z pliku Creature.cpp przeszły pomyślnie ###" << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};