#ifndef PUNKT_H
#define PUNKT_H
using namespace std;
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

    void setY(int i);
    void setX(int i);
};

#endif // PUNKT_H
