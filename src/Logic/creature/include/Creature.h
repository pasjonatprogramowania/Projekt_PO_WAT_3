#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <memory>
#include "../../include/Range.h"
#include "CreatureStatistics.h"
using namespace std;
class Creature  {
public:
    Creature();

    Creature(string _name, int _attack, int _armor, int _maxHp, int _moveRange, Range _damage, int _amount,
                 int _attackRange);

    void attack(Creature _defender);
    void attack(Creature& attacker, Creature& defender);
    void counterAttack(Creature& _defender);
//    void performAfterAttack(int _damageToDeal);
    void applyDamage(int _damageToDeal);
    void propertyChange() {};
    bool isAlive();
    void resetCounterAttack();
    bool canCounterAttack();

    string getName();
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

#endif