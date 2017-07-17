#pragma once

#include "xy_pair_type.h"

class Stone {
    char buffer[4][4] = {{' ', ' ', ' ', ' '},
                         {' ', ' ', ' ', ' '},
                         {' ', 'X', 'X', ' '},
                         {' ', 'X', 'X', ' '}};

    xy_pair pos;
    xy_pair size = {4, 4};
public:
    int size_x() { return size.x; };

    int size_y() { return size.y; };

    int pos_x() { return pos.x; };

    int pos_y() { return pos.y; };

    char getBuffer(xy_pair coord) { return buffer[coord.y][coord.x]; };

    Stone(xy_pair);

    ~Stone();
};

