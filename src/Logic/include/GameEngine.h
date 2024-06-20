#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include <string>
#include "Board.h"
#include "Point.h"
#include "CreatureTurnQueue.h"
#include "../Creature/include/Creature.h"

using namespace std;
class GameEngine {
private:
    Board board;
    CreatureTurnQueue queue;
    struct creaturesOnBoard {
        Creature creature;
        string site;
        Point point;
    };
    vector<creaturesOnBoard> creaturesOnBoard;
public:
    void putCreaturesFromOneSideToBoard(vector<Creature>& creatures, bool site);
    GameEngine(vector<Creature>& myCreatures, vector<Creature>& enemyCreatures, Board* _board = nullptr);
    void putCreatureToBoard(vector<Creature>& myCreatures, vector<Creature>& enemyCreatures);
    bool canMove(int x, int y);
    bool canAttack(Creature& attacker, Creature& defender);
    void move(Point targetPoint);
    void pass();
    void attack(Point point);
};

#endif // GAMEENGINE_H
