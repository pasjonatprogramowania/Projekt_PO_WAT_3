
#include "../include/CreatureStatistics.h"

CreatureStatistics::CreatureStatistics(std::string _name, int _attack, int _armor, int _maxHp, int _moveRange,
                                               Range _damage, int _amount, int _attackRange) {
    this->name = _name;
    this->attack = _attack;
    this->armor = _armor;
    this->maxHp = _maxHp;
    this->moveRange = _moveRange;
    this->maxRange = _moveRange;
    this->damage = _damage;
    this->amount = _amount;
    this->currentHp = _maxHp;
    this->wasCounterAttack = false;
    this->attackRange = _attackRange;
}

std::string CreatureStatistics::getName() {
    return this->name;
}

int CreatureStatistics::getAttack() {
    return this->attack;
}

int CreatureStatistics::getArmor() {
    return this->armor;
}

int CreatureStatistics::getMaxHp() {
    return this->maxHp;
}

int CreatureStatistics::getMoveRange() {
    return this->moveRange;
}

int CreatureStatistics::getMaxRange() {
    return this->maxRange;
}

Range CreatureStatistics::getDamage() {
    return this->damage;
}

int CreatureStatistics::getAmount() {
    return this->amount;
}

int CreatureStatistics::getAttackRange() {
    return this->attackRange;
}

