// creature.h

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "../../include/Range.h"
#include "CreatureStatistics.h"

class Creature {
public:
    Creature();

    Creature(std::string _name, int _attack, int _armor, int _maxHp, int _moveRange, Range _damage, int _amount,
             int _attackRange);

    void attack(Creature* _defender);
    void counterAttack(Creature* _defender);
    void performAfterAttack(int _damageToDeal);
    void applyDamage(int _damageToDeal);
    void propertyChange() {};
    bool isAlive();
    void resetCounterAttack();
    bool canCounterAttack();

    // Getters
    std::string getName();
    int getAttack();
    int getArmor();
    int getMaxHp();
    int getCurrentHp();
    int getMoveRange();
    int getMaxRange();
    Range getDamage();
    int getAmount();
    int getAttackRange();
    CreatureStatistics* stats;
    bool operator==(const Creature& other) const;
    bool operator!=(const Creature& other) const;

};

#endif // CREATURE_H