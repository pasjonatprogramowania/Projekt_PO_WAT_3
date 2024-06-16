
#include <iostream>
#include <map>
#include <cmath>
#include <stdexcept>
#include "Point.h"
#include "../Creature/include/Creature.h"

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    Board(int i, int i1);
    void add(Point _point, Creature _creature);
    Creature getCreatureByPoint(Point _point);
    Point getPointByCreature(Creature _creature);
    void moveByCreature(Creature _creature, Point _newPoint);
    void move(Point _point, Point _newPoint);
    void pass(Creature _creature);
    bool canMove(Creature _creature, int _x, int _y);
    bool canAttack(Creature _attacker, Creature _defender);
    void reduceMovement(Creature _creature, int _x, int _y);
    bool isThatPointOnMap(int _x, int _y);
    bool isThisTileTaken(Point _point);
    bool operator==(const Board& other) const;
    int getWidth();

    int getHeight();

private:
    std::map<Point, Creature> map;
    int boardX;
    int boardY;
    bool equals(const Point& val, const Point& toAssert);
    bool equals(const Creature& val, const Creature& toAssert);
};

#endif // BOARD_H