//
// Created by Lukas Wolfsteiner on 26.04.17.
//

#include <iostream>
#include "StoneTest.h"

int StoneTest::test_spielstein_viereck() {
    int errors = 0;

    // Teste buffer
    for (int y = 0; y <= STONE_DIMENSION_DEFAULT; ++y) {
        for (int x = 0; x <= STONE_DIMENSION_DEFAULT; ++x) {

            if (y >= 2 && y <= 3 && x >= 2 && x <= 3) {
                char expected = 'X';
                char actual = stone.getBuffer(XyPair(x, y));

                if (expected == actual) {
                    // Alles gut
                } else {
                    std::cout << "test_spielstein_viereck: erwartet=" << expected << " eigentlich=" << actual
                              << " buffer-x=" << x << " buffer-y=" << y << "\n";
                    errors++;
                }
            } else {
                char expected = ' ';
                char actual = stone.getBuffer(XyPair(x, y));

                if (expected == actual) {
                    // Alles gut
                } else {
                    std::cout << "test_spielstein_viereck: erwartet=" << expected << " eigentlich=" << actual
                              << " buffer-x=" << x << " buffer-y=" << y << "\n";
                    errors++;
                }
            }
        }
    }

    return errors;
}

int StoneTest::test() {
    int errors = 0;

    // Teste Viereck
    errors += test_spielstein_viereck();

    return errors;
}

StoneTest::StoneTest(Stone stone) {
    this->stone = stone;
}
