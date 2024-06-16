// creatureStatistics.h

#ifndef CREATURESTATISTICS_H
#define CREATURESTATISTICS_H

#include <string>
#include "../../include/Range.h"

class CreatureStatistics {
public:
    CreatureStatistics(std::string _name, int _attack, int _armor, int _maxHp, int _moveRange, Range _damage,
                       int _amount, int _attackRange);

// Getters
    std::string getName();
    int getAttack();
    int getArmor();
    int getMaxHp();
    int getMoveRange();
    int getMaxRange();
    Range getDamage();
    int getAmount();
    int getAttackRange();

    std::string name;
    int attack;
    int armor;
    int maxHp;
    int moveRange;
    int maxRange;
    Range damage;
    int amount;
    int currentHp;
    bool wasCounterAttack;
    int attackRange;
};

#endif // CREATURESTATISTICS_H

