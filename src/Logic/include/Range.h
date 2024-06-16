#ifndef ZAKRES_H
#define ZAKRES_H

class Range {
private:
    int lowerPoint;
    int upperPoint;

public:
    Range();
    Range(int _dolny, int _gorny);
    int getLowerPoint() const;
    int getUpperPoint() const;
};

#endif // ZAKRES_H
