//
// Created by Lukas Wolfsteiner on 26.04.17.
//

#ifndef PG2_SL_SOSE2017_STONETEST_H
#define PG2_SL_SOSE2017_STONETEST_H


#include "../libs/Stone.h"

class StoneTest {

private:
    Stone stone;

    int test_spielstein_viereck();

public:
    StoneTest(Stone stone);

    int test();

};


#endif //PG2_SL_SOSE2017_STONETEST_H
