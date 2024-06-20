#include "../include/GameEngine.h"

GameEngine::GameEngine(std::vector<Creature>& myCreatures, std::vector<Creature>& enemyCreatures, Board* _board) {
    if (_board) {
        board = *_board;
    } else {
        board = Board();
    }
    queue = CreatureTurnQueue();
    putCreatureToBoard(myCreatures, enemyCreatures);
}

void GameEngine::putCreatureToBoard(std::vector<Creature>& myCreatures, std::vector<Creature>& enemyCreatures) {
    putCreaturesFromOneSideToBoard(myCreatures, false);
    putCreaturesFromOneSideToBoard(enemyCreatures, true);
    queue.initQueue(board.getMap());
}

void GameEngine::putCreaturesFromOneSideToBoard(std::vector<Creature>& creatures, bool site) {
    for (size_t i = 0; i < creatures.size(); ++i) {
        int newPointX = site ? 20 : 1;
        int newPointY = static_cast<int>(i) + 1;
        std::string creatureSite = site ? "enemy" : "player";
        Point newPoint(newPointX, newPointY);
        board.add(newPoint, creatures[i]);
        creaturesOnBoard.push_back({ creatures[i], creatureSite, newPoint });
    }
}

bool GameEngine::canMove(int x, int y) {
    return board.canMove(queue.getActiveCreature(), x, y);
}

bool GameEngine::canAttack(Creature& attacker, Creature& defender) {
    return board.canAttack(attacker, defender);
}

void GameEngine::move(Point targetPoint) {
    board.moveByCreature(queue.getActiveCreature(), targetPoint);
    for (auto& item : creaturesOnBoard) {
        if (item.creature == queue.getActiveCreature()) {
            item.point.setX(targetPoint.getX());
            item.point.setY(targetPoint.getY());
        }
    }
}

void GameEngine::pass() {
    queue.next(board.getMap());
    board.pass(queue.getActiveCreature());
}

void GameEngine::attack(Point point) {
    Creature activeCreature = queue.getActiveCreature();
    activeCreature.attack(board.getCreatureByPoint(point));
}
