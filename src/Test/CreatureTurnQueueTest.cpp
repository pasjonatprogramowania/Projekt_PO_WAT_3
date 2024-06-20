#include <iostream>
#include <map>
#include "../logic/include/CreatureTurnQueue.h"
#include "../logic/creature/include/Creature.h"
#include "../logic/include/Point.h"

using namespace std;

class CreatureTurnQueueTest {
public:
    static void testInitQueue() {
        CreatureTurnQueue queue;
        map<Point, Creature> creatureList = {
                { Point(0, 0), Creature("Creature1", 10, 5, 100, 3, Range(5, 10), 1, 1) },
                { Point(1, 1), Creature("Creature2", 15, 8, 120, 3, Range(6, 12), 1, 1) },
        };

        queue.initQueue(creatureList);
        Creature activeCreature = queue.getActiveCreature();

        if (activeCreature.getName() != "Creature1") {
            throw runtime_error("TestCreatureTurnQueue.cpp - Test initQueue nie powiodl sie. Pierwsze stworzenie w kolejce jest nieprawidlowe.");
        }
    }

    static void testGetActiveCreature() {
        CreatureTurnQueue queue;
        map<Point, Creature> creatureList = {
                { Point(0, 0), Creature("Creature1", 10, 5, 100, 3, Range(5, 10), 1, 1) },
        };

        queue.initQueue(creatureList);
        Creature activeCreature = queue.getActiveCreature();

        if (activeCreature.getName() != "Creature1") {
            throw runtime_error("TestCreatureTurnQueue.cpp - Test getActiveCreature nie powiodl sie. Aktywne stworzenie jest nieprawidlowe.");
        }
    }

    static void testNext() {
        CreatureTurnQueue queue;
        map<Point, Creature> creatureList = {
                { Point(0, 0), Creature("Creature1", 10, 5, 100, 3, Range(5, 10), 1, 1) },
                { Point(1, 1), Creature("Creature2", 15, 8, 120, 3, Range(6, 12), 1, 1) },
        };

        queue.initQueue(creatureList);
        queue.next(creatureList);
        Creature activeCreature = queue.getActiveCreature();

        if (activeCreature.getName() != "Creature2") {
            throw runtime_error("TestCreatureTurnQueue.cpp - Test next nie powiodl sie. Nastepne stworzenie w kolejce jest nieprawidlowe.");
        }

        queue.next(creatureList);
        activeCreature = queue.getActiveCreature();

        if (activeCreature.getName() != "Creature1") {
            throw runtime_error("TestCreatureTurnQueue.cpp - Test next reset kolejki nie powiodl sie. Kolejka nie zostala poprawnie zresetowana.");
        }
    }


    static void runAllTests() {
        try {
            testInitQueue();
            testGetActiveCreature();
            testNext();
            cout << "### Wszystkie testy z pliku TestCreatureTurnQueue.cpp przeszly pomyslnie ###" << endl;
        } catch (const exception &e) {
            cerr << e.what() << endl;
            throw;
        }
    }
};

