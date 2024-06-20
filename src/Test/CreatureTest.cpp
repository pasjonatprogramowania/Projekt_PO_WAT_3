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
                    "TestCreature.cpp - Test konstruktora z pliku creature.cpp nie powiodl sie. Nieprawidlowe wartosci pol obiektu.");
        }
    }

    static void testApplyDamage() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        creature.applyDamage(50);
        if (creature.getCurrentHp() != 50 || creature.getAmount() != 2) {
            throw runtime_error(
                    "TestCreature.cpp - Test applyDamage z pliku creature.cpp nie powiodl sie. Nieprawidlowe wartosci po zastosowaniu obrazen.");
        }
    }

    static void testIsAlive() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        if (!creature.isAlive()) {
            throw runtime_error(
                    "TestCreature.cpp - Test isAlive z pliku creature.cpp nie powiodl sie. Stworzenie powinno byc zywe po utworzeniu.");
        }
        creature.applyDamage(200);
        if (creature.isAlive()) {
            throw runtime_error(
                    "TestCreature.cpp - Test isAlive z pliku creature.cpp nie powiodl sie. Stworzenie powinno byc martwe po otrzymaniu smiertelnych obrazen.");
        }
    }
    static void testAttack() {
        Creature attacker("Attacker", 10, 5, 100, 3, Range(5, 10), 2, 1);
        Creature defender("Defender", 10, 5, 100, 3, Range(5, 10), 2, 1);
        attacker.attack(defender);
        if (defender.getCurrentHp() != 95 && defender.getAmount() != 2) {
            throw runtime_error("TestCreature.cpp - Test attack z pliku creature.cpp nie powiodl sie. Defender nie otrzymal prawidlowych obrazen.");
        }
        if (defender.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test attack z pliku creature.cpp nie powiodl sie. Defender nie powinien byc w stanie kontratakowac.");
        }
    }

    static void testCanCounterAttack() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);

        if (!creature.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test canCounterAttack z pliku creature.cpp nie powiodl sie. Stworzenie powinno byc w stanie kontratakowac.");
        }
        creature.counterAttack(creature);
        if (creature.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test canCounterAttack z pliku creature.cpp nie powiodl sie. Stworzenie nie powinno byc w stanie kontratakowac.");
        }
    }

    static void testCounterAttack() {
        Creature creature1("Creature1", 10, 5, 100, 3, Range(5, 10), 2, 1);
        Creature creature2("Creature2", 10, 5, 100, 3, Range(5, 10), 2, 1);
        creature1.counterAttack(creature2);
        if (creature2.getCurrentHp() != 95 && creature2.getAmount() != 2) {
            throw runtime_error("TestCreature.cpp - Test counterAttack z pliku creature.cpp nie powiodl sie. Stworzenie 2 nie otrzymalo prawidlowych obrazen.");
        }
        if (creature2.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test counterAttack z pliku creature.cpp nie powiodl sie. Stworzenie 2 powinno byc w stanie kontratakowac tylko raz.");
        }
    }

    static void testResetCounterAttack() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        Creature creature2("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        creature.counterAttack(creature2);

        if (!creature.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test resetCounterAttack z pliku creature.cpp nie powiodl sie. Stworzenie nie powinno byc w stanie kontratakowac.");
        }

        creature.resetCounterAttack();

        if (!creature.canCounterAttack()) {
            throw runtime_error("TestCreature.cpp - Test resetCounterAttack z pliku creature.cpp nie powiodl sie. Stworzenie powinno byc w stanie kontratakowac.");
        }
    }
    static void runAllTests() {
        try {
            testConstructor();
            testApplyDamage();
            testIsAlive();
            testAttack();
            testCanCounterAttack();
            testResetCounterAttack();
            testCounterAttack();
            cout << "### Wszystkie testy z pliku TestCreature.cpp przeszly pomyslnie ###" << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};