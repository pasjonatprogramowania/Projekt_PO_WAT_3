#ifndef CREATURETURNQUEUE_H
#define CREATURETURNQUEUE_H

#include <vector>
#include <map>
#include "../creature/include/Creature.h"
#include "Point.h"

using namespace std;

class CreatureTurnQueue {
private:
    map<Point, Creature> creatureMap;
    vector<Creature> creatureArray;
    vector<Creature> observersArray;

public:
    CreatureTurnQueue();
    void initQueue(map<Point, Creature> list);
    Creature getActiveCreature();
    void next(map<Point, Creature> list);
    void notifyObserver();
};

#endif // CREATURETURNQUEUE_H
