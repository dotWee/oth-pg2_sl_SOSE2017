//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#ifndef PG2_SL_SOSE2017_FIELD_H
#define PG2_SL_SOSE2017_FIELD_H


#include <cstdlib>
#include "Stone.h"

#define FIELD_WIDTH_X 12
#define FIELD_HEIGHT_Y 22

class Field {

private:
    char buffer[FIELD_HEIGHT_Y][FIELD_WIDTH_X];
    Stone *currStone;
    Stone *nextStone;

    XyPair pos = XyPair(0, 0);
    XyPair size = pos;

public:
    Field();

    int pos_x();

    int pos_y();

    int size_x();

    int size_y();

    char getBuffer(XyPair coord);
};


#endif //PG2_SL_SOSE2017_FIELD_H
