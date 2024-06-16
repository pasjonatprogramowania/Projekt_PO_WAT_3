#ifndef PUNKT_H
#define PUNKT_H

class Point {
private:
    int x;
    int y;

public:
    Point(int _x, int _y);
    int getX() const;
    int getY() const;
    friend bool operator<(const Point& p1, const Point& p2);
    double distance(const Point &_punkt) const;
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
};

#endif // PUNKT_H
