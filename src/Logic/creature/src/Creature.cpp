// creature.cpp

#include <cmath>
#include "../include/Creature.h"
#include "../include/CreatureStatistics.h"

using namespace std;
Creature::Creature(
        string _name,
        int _attack,
        int _armor,
        int _maxHp,
        int _moveRange,
        Range _damage,
        int _amount,
        int _attackRange
) {
    this->stats = new CreatureStatistics(_name, _attack, _armor, _maxHp, _moveRange, _damage, _amount,
                                             _attackRange);
}


void Creature::counterAttack(Creature& _defender) {
    if (this->isAlive() && !_defender.stats->wasCounterAttack) {
        int damageToDeal = _defender.getDamage().getLowerPoint();
        this->applyDamage(damageToDeal);
        _defender.stats->wasCounterAttack = true;
//        _defender.performAfterAttack(damageToDeal); // przyszla implementacja
    }
}

//void Creature::performAfterAttack(int _damageToDeal) {
//    if (_damageToDeal) {
//        return;
//    }
//}

void Creature::applyDamage(int _damageToDeal) {
    int totalAmountHp = this->getMaxHp() * (this->getAmount() - 1) + this->stats->currentHp - _damageToDeal;

    if (totalAmountHp <= 0) {
        this->stats->amount = 0;
        this->stats->currentHp = 0;
    } else {
        this->stats->amount = totalAmountHp / this->getMaxHp();
        this->stats->currentHp = totalAmountHp % this->getMaxHp();
        if (this->stats->currentHp > 0) {
            this->stats->amount += 1;
        } else if (this->stats->amount == 0) {
            this->stats->currentHp = 0;
        }
    }
}

bool Creature::isAlive() {
    return this->getAmount() > 0;
}

void Creature::resetCounterAttack() {
    this->stats->wasCounterAttack = false;
}

bool Creature::canCounterAttack() {
    return !this->stats->wasCounterAttack;
}

string Creature::getName() {
    return this->stats->name;
}

int Creature::getAttack() {
    return this->stats->attack;
}

int Creature::getArmor() {
    return this->stats->armor;
}

int Creature::getMaxHp() {
    return this->stats->maxHp;
}

int Creature::getCurrentHp() {
    return this->stats->currentHp;
}

int Creature::getMoveRange() {
    return this->stats->moveRange;
}

int Creature::getMaxRange() {
    return this->stats->maxRange;
}

Range Creature::getDamage() {
    return this->stats->damage;
}

int Creature::getAmount() {
    return this->stats->amount;
}
int Creature::getAttackRange() {
    return this->stats->attackRange;
}

Creature::Creature() {
    auto *rang = new Range(1, 1);
    this->stats = new CreatureStatistics("", 10, 10, 100, 10, *rang, 10, 10);
}
bool Creature::operator==(const Creature& other) const {
    return this == &other;
}

bool Creature::operator!=(const Creature &other) const {
    return this != &other;
}

void Creature::attack(Creature& attacker, Creature& defender) {
    if (defender.isAlive()) {
        int damageToDeal = attacker.getDamage().getLowerPoint();
        defender.applyDamage(damageToDeal);
//        attacker.performAfterAttack(damageToDeal);
        attacker.counterAttack(defender);
    }
}
void Creature::attack(Creature _defender) {
    if (_defender.isAlive()) {
        int damageToDeal = this->getDamage().getLowerPoint();
        _defender.applyDamage(damageToDeal);
//        this->performAfterAttack(damageToDeal);
        this->counterAttack(_defender);
    }
}





