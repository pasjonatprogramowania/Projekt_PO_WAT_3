
#include "../include/Board.h"

Board::Board() {
    boardX = 20;
    boardY = 15;
}

void Board::add(Point _point, Creature _creature) {
    if (!isThatPointOnMap(_point.getX(), _point.getY()) || isThisTileTaken(_point)) {
        throw std::runtime_error("Invalid point or tile already taken");
    }

    map[_point] = _creature;
    if (!equals(_point, map.find(_point)->first)) {
        throw std::runtime_error("Key does not match the value that should be inserted");
    }
}

Creature Board::getCreatureByPoint(Point _point) {
    for (const auto& entry : map) {
        if (equals(entry.first, _point)) {
            return entry.second;
        }
    }
    throw std::runtime_error("creature not found at the specified point");
}

Point Board::getPointByCreature(Creature _creature) {
    for (const auto& entry : map) {
        if (equals(entry.second, _creature)) {
            return entry.first;
        }
    }
    throw std::runtime_error("Point not found for the specified creature");
}

void Board::moveByCreature(Creature _creature, Point _newPoint) {
    move(getPointByCreature(_creature), _newPoint);
}

void Board::move(Point _point, Point _newPoint) {
    if (!isThatPointOnMap(_newPoint.getX(), _newPoint.getY()) || isThisTileTaken(_newPoint)) {
        throw std::runtime_error("Invalid new point or tile already taken");
    }

    Creature creature = map[_point];
    map.erase(_point);
    map[_newPoint] = creature;
}

void Board::pass(Creature _creature) {
    for (auto& entry : map) {
        if (equals(entry.second, _creature)) {
            map[entry.first] = _creature;
            break;
        }
    }
}

bool Board::canMove(Creature _creature, int _x, int _y) {
    if (!isThatPointOnMap(_x, _y)) {
        return false;
    }

    Point pointToMoveCreature(_x, _y);
    Point currentCreaturePoint = getPointByCreature(_creature);

    double distance = currentCreaturePoint.distance(pointToMoveCreature);

    return distance <= _creature.getMoveRange() && !isThisTileTaken(pointToMoveCreature);
}

bool Board::canAttack(Creature _attacker, Creature _defender) {
    Point attackerPoint = getPointByCreature(_attacker);
    Point defenderPoint = getPointByCreature(_defender);

    double distance = attackerPoint.distance(defenderPoint);

    return std::floor(distance) <= _attacker.getAttackRange();
}

void Board::reduceMovement(Creature _creature, int _x, int _y) {
    if (!isThatPointOnMap(_x, _y)) {
        throw std::runtime_error("Point is outside the map");
    }

    Point pointToMoveCreature(_x, _y);
    Point currentCreaturePoint = getPointByCreature(_creature);

    double distance = currentCreaturePoint.distance(pointToMoveCreature);

    _creature.stats->moveRange -= distance;
}

bool Board::isThatPointOnMap(int _x, int _y) {
    return _x <= boardX && _y <= boardY;
}

bool Board::isThisTileTaken(Point _point) {
    return map.find(_point) != map.end();
}

bool Board::equals(const Point &val, const Point &toAssert) {
    return false;
}

bool Board::equals(const Creature &val, const Creature &toAssert) {
    return false;
}

Board::Board(int i, int i1) {
    boardX = i;
    boardY = i1;
}

int Board::getWidth() {
    return boardX;
}

int Board::getHeight() {
    return boardY;
}
