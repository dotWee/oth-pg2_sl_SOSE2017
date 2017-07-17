#pragma once

#include "xy_pair_type.h"


class Stone;

class Field {
    char buffer[22][12] = {{'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xBA', ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    ' ',    '\xBA'},
                           {'\xC8', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xBC'},};

    Stone *currStone;
    Stone *nextStone;
    xy_pair pos = {0, 0};
    xy_pair size = {22, 12};

    void update();

public:
    void move(int);

    char getBuffer(xy_pair coord) { return buffer[coord.y][coord.x]; };

    int size_x() { return size.x; };

    int size_y() { return size.y; };

    int pos_x() { return pos.x; };

    int pos_y() { return pos.y; };

    Field(xy_pair);

    ~Field();
};

