// creature.cpp

#include <cmath>
#include "../include/Creature.h"
#include "../include/CreatureStatistics.h"

Creature::Creature(
        std::string _name,
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

//void creature::attack(creature* _defender) {
//    if (_defender->isAlive()) {
//        int damageToDeal = this->calculateDamage(this, _defender);
//        _defender->applyDamage(damageToDeal);
//        this->performAfterAttack(damageToDeal);
//        this->counterAttack(_defender);
//    }
//}

//void creature::counterAttack(creature* _defender) {
//    if (this->isAlive() && !_defender->stats->wasCounterAttack) {
//        int counterAttackDamageToDeal = this->calculateDamage(_defender, this);
//        this->applyDamage(counterAttackDamageToDeal);
//        _defender->stats->wasCounterAttack = true;
//        _defender->performAfterAttack(counterAttackDamageToDeal);
//    }
//}

void Creature::performAfterAttack(int _damageToDeal) {
    if (_damageToDeal) {
        return;
    }
}

void Creature::applyDamage(int _damageToDeal) {
    int totalAmountHp = this->getMaxHp() * (this->getAmount() - 1) + this->stats->currentHp - _damageToDeal;
    if (totalAmountHp <= 0) {
        this->stats->amount = 0;
        this->stats->currentHp = 0;
    } else {
        if (totalAmountHp % this->getMaxHp() == 0) {
            this->stats->currentHp = this->getMaxHp();
            this->stats->amount = totalAmountHp / this->getMaxHp();
        } else {
            this->stats->currentHp = totalAmountHp % this->getMaxHp();
            if (_damageToDeal >= 0) {
                this->stats->amount = std::floor(totalAmountHp / this->getMaxHp()) + 1;
            } else {
                this->stats->amount = std::floor(totalAmountHp / this->getMaxHp());
            }
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

std::string Creature::getName() {
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
    this->stats = new CreatureStatistics("Test", 10, 10, 100, 10,*rang, 10, 10);
}
bool Creature::operator==(const Creature& other) const {
    return this == &other;
}



