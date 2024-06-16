#include <iostream>
#include "../Logic/Creature/include/Creature.h"
class CreatureTest {
public:
    void testConstructor() {
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
            throw std::runtime_error(
                    "Test konstruktora z pliku creature.cpp nie powiódł się. Nieprawidłowe wartości pól obiektu.");
        }
        std::cout << "Test konstruktora z pliku creature.cpp przeszedł pomyślnie" << std::endl;
    }

    void testApplyDamage() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        creature.applyDamage(50);
        if (creature.getCurrentHp() != 50 || creature.getAmount() != 2) {
            throw std::runtime_error(
                    "Test applyDamage z pliku creature.cpp nie powiódł się. Nieprawidłowe wartości po zastosowaniu obrażeń.");
        }
        std::cout << "Test applyDamage z pliku creature.cpp przeszedł pomyślnie" << std::endl;
    }

    void testIsAlive() {
        Creature creature("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        if (!creature.isAlive()) {
            throw std::runtime_error(
                    "Test isAlive z pliku creature.cpp nie powiódł się. Stworzenie powinno być żywe po utworzeniu.");
        }
        creature.applyDamage(200);
        if (creature.isAlive()) {
            throw std::runtime_error(
                    "Test isAlive z pliku creature.cpp nie powiódł się. Stworzenie powinno być martwe po otrzymaniu śmiertelnych obrażeń.");
        }
        std::cout << "Test isAlive z pliku creature.cpp przeszedł pomyślnie" << std::endl;
    }

    void runAllTests() {
        try {
            testConstructor();
            testApplyDamage();
            testIsAlive();
            std::cout << "Wszystkie testy z pliku creature.cpp przeszły pomyślnie" << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            throw;
        }
    }
};