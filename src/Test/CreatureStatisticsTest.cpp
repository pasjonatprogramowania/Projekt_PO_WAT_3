#include <iostream>
#include "../Logic/Creature/include/CreatureStatistics.h"
using namespace std;
class CreatureStatisticsTest {
public:
    static void testConstructor() {
        CreatureStatistics stats("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        if (stats.name != "Test creature" ||
            stats.attack != 10 ||
            stats.armor != 5 ||
            stats.maxHp != 100 ||
            stats.currentHp != 100 ||
            stats.moveRange != 3 ||
            stats.damage.getLowerPoint() != 5 ||
            stats.damage.getUpperPoint() != 10 ||
            stats.amount != 2 ||
            stats.attackRange != 1 ||
            stats.wasCounterAttack != false) {
            throw runtime_error("TestCreatureStatistics.cpp - Test konstruktora z pliku TestCreatureStatistics.cpp nie powiodl sie. Nieprawidlowe wartosci pol obiektu.");
        }
    }

    static void testCopyConstructor() {
        CreatureStatistics stats1("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        CreatureStatistics stats2 = stats1;
        if (stats2.name != "Test creature" ||
            stats2.attack != 10 ||
            stats2.armor != 5 ||
            stats2.maxHp != 100 ||
            stats2.currentHp != 100 ||
            stats2.moveRange != 3 ||
            stats2.damage.getLowerPoint() != 5 ||
            stats2.damage.getUpperPoint() != 10 ||
            stats2.amount != 2 ||
            stats2.attackRange != 1 ||
            stats2.wasCounterAttack != false) {
            throw runtime_error("TestCreatureStatistics.cpp - Test konstruktora kopiujacego z pliku TestCreatureStatistics.cpp nie powiodl sie. Nieprawidlowe wartosci pol skopiowanego obiektu.");
        }
    }

    static void testAssignmentOperator() {
        CreatureStatistics stats1("Test creature", 10, 5, 100, 3, Range(5, 10), 2, 1);
        CreatureStatistics stats2("Other creature", 15, 8, 120, 4, Range(8, 12), 3, 2);
        stats2 = stats1;
        if (stats2.name != "Test creature" ||
            stats2.attack != 10 ||
            stats2.armor != 5 ||
            stats2.maxHp != 100 ||
            stats2.currentHp != 100 ||
            stats2.moveRange != 3 ||
            stats2.damage.getLowerPoint() != 5 ||
            stats2.damage.getUpperPoint() != 10 ||
            stats2.amount != 2 ||
            stats2.attackRange != 1 ||
            stats2.wasCounterAttack != false) {
            throw runtime_error("TestCreatureStatistics.cpp - Test operatora przypisania z pliku TestCreatureStatistics.cpp nie powiodl sie. Nieprawidlowe wartosci pol przypisanego obiektu.");
        }

    }

    static void runAllTests() {
        try {
            testConstructor();
            testCopyConstructor();
            testAssignmentOperator();
            cout << "### Wszystkie testy z pliku TestCreatureStatistics.cpp przeszly pomyslnie ###" << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};
