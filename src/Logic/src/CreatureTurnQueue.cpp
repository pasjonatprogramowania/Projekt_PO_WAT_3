#include "../include/CreatureTurnQueue.h"
#include "../creature/include/Creature.h"
#include "../include/Point.h"

using namespace std;

CreatureTurnQueue::CreatureTurnQueue() {
    creatureMap = map<Point, Creature>();
    creatureArray = vector<Creature>();
    observersArray = vector<Creature>();
}

void CreatureTurnQueue::initQueue(map<Point, Creature> list) {
    creatureMap = list;
    creatureArray.clear();
    observersArray.clear();

    for (const auto& pair : list) {
        creatureArray.push_back(pair.second);
        observersArray.push_back(pair.second);
    }
}

Creature CreatureTurnQueue::getActiveCreature() {
    if (!creatureArray.empty()) {
        return creatureArray.front();
    }
    return Creature();
}

void CreatureTurnQueue::next(map<Point, Creature> list) {
    if (!creatureArray.empty()) {
        creatureArray.front().propertyChange();
        creatureArray.erase(creatureArray.begin());
        auto it = creatureMap.begin();
        if (it != creatureMap.end()) {
            creatureMap.erase(it->first);
        }

        if (creatureMap.empty()) {
            notifyObserver();
            initQueue(std::move(list));
        }
    }
}

void CreatureTurnQueue::notifyObserver() {
    for (auto& item : observersArray) {
        item.resetCounterAttack();
    }
}
