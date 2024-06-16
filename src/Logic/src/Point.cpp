#include "../include/Point.h"
#include <cmath>

Point::Point(int _x, int _y) : x(_x), y(_y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distance(const Point& _punkt) const {
    int dx = std::abs(x - _punkt.getX());
    int dy = std::abs(y - _punkt.getY());
    return std::sqrt(dx * dx + dy * dy);
}

bool operator<(const Point& p1, const Point& p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}
