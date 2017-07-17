//
// Created by Lukas Wolfsteiner on 25.04.17.
//

#ifndef PG2_SL_SOSE2017_FIELDTEST_H
#define PG2_SL_SOSE2017_FIELDTEST_H


#include "../libs/Field.h"

class FieldTest {

private:
    Field field;

    int test_spielfeld_ecke_links_unten();

    int test_spielfeld_ecke_rechts_unten();

    int test_spielfeld_wand_links();

    int test_spielfeld_wand_rechts();

    int test_spielfeld_wand_unten();

public:
    FieldTest(Field field);

    int test();
};


#endif //PG2_SL_SOSE2017_FIELDTEST_H
