//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#ifndef PG2_SL_SOSE2017_FIELD_H
#define PG2_SL_SOSE2017_FIELD_H


#include <cstdlib>
#include "Stone.h"

#define FIELD_WIDTH_X 12
#define FIELD_HEIGHT_Y 22

#define NEXTSTONE_WIDTH_X 5
#define NEXTSTONE_HEIGHT_Y 5

static const int WIDTH_X = FIELD_WIDTH_X + NEXTSTONE_WIDTH_X;
static const int HEIGHT_Y = FIELD_HEIGHT_Y;

class Field {

private:
    char buffer[HEIGHT_Y][WIDTH_X];
    Stone *currStone;
    Stone *nextStone;

    XyPair pos = XyPair(0, 0);
    XyPair size = pos;

    void init_field();

    void init_nextStone();

public:
    Field();

    int pos_x();

    int pos_y();

    int size_x();

    int size_y();

    char getBuffer(XyPair coord);
};


#endif //PG2_SL_SOSE2017_FIELD_H
