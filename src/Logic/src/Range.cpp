#include "../include/Range.h"

Range::Range(int _lower, int _upper) : lowerPoint(_lower), upperPoint(_upper) {}

int Range::getLowerPoint() const {
    return lowerPoint;
}

int Range::getUpperPoint() const {
    return upperPoint;
}

Range::Range() {

}
