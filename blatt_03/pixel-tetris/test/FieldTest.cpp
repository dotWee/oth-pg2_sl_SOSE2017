//
// Created by Lukas Wolfsteiner on 25.04.17.
//

#include <iostream>
#include "FieldTest.h"

FieldTest::FieldTest(Field field) {
    this->field = field;
}

int FieldTest::test_spielfeld_ecke_links_unten() {
    int errors = 0;

    // Teste untere linke Ecke
    char expected = '+';
    char actual = field.getBuffer(XyPair(0, FIELD_HEIGHT_Y));
    if (expected == actual) {
        // Alles gut
    } else {
        std::cout << "test_spielfeld_ecke_links_unten: erwartet=" << expected << " eigentlich=" << actual
                  << " buffer-x=" << 0 << " buffer-y=" << FIELD_HEIGHT_Y << "\n";
        errors++;
    }

    return errors;
}

int FieldTest::test_spielfeld_ecke_rechts_unten() {
    int errors = 0;

    // Teste untere rechte Ecke
    char expected = '+';
    char actual = field.getBuffer(XyPair(FIELD_WIDTH_X, FIELD_HEIGHT_Y));
    if (expected == actual) {
        // Alles gut
    } else {
        std::cout << "test_spielfeld_ecke_rechts_unten: erwartet=" << expected << " eigentlich=" << actual
                  << " buffer-x=" << FIELD_WIDTH_X << " buffer-y=" << FIELD_HEIGHT_Y << "\n";
        errors++;
    }

    return errors;
}

int FieldTest::test_spielfeld_wand_links() {
    int errors = 0;

    // Teste linke Spielfeldwand
    char expected = '|';
    for (int y = 0; y < FIELD_HEIGHT_Y; ++y) {
        char actual = field.getBuffer(XyPair(0, y));
        if (expected == actual) {
            // Alles gut
        } else {
            std::cout << "test_spielfeld_wand_links: erwartet=" << expected << " eigentlich=" << actual << " buffer-x="
                      << 0 << " buffer-y=" << y << "\n";
            errors++;
        }
    }

    return errors;
}

int FieldTest::test_spielfeld_wand_rechts() {
    int errors = 0;

    // Teste rechte Spielfeldwand
    char expected = '|';
    for (int y = 0; y < FIELD_HEIGHT_Y; ++y) {
        char actual = field.getBuffer(XyPair(FIELD_WIDTH_X, y));
        if (expected == actual) {
            // Alles gut
        } else {
            std::cout << "test_spielfeld_wand_rechts: erwartet=" << expected << " eigentlich=" << actual << " buffer-x="
                      << FIELD_WIDTH_X << " buffer-y=" << y << "\n";
            errors++;
        }
    }

    return errors;
}

int FieldTest::test_spielfeld_wand_unten() {
    int errors = 0;

    // Teste untere Spielfeldwand
    char expected = '-';
    for (int x = 1; x < FIELD_WIDTH_X; ++x) {
        char actual = field.getBuffer(XyPair(x, FIELD_HEIGHT_Y));
        if (expected == actual) {
            // Alles gut
        } else {
            std::cout << "test_spielfeld_wand_unten: erwartet=" << expected << " eigentlich=" << actual << " buffer-x="
                      << x << " buffer-y=" << FIELD_HEIGHT_Y << "\n";
            errors++;
        }
    }

    return errors;
}

int FieldTest::test() {
    int errors = 0;

    // Teste Ecken
    errors += test_spielfeld_ecke_links_unten();
    errors += test_spielfeld_ecke_rechts_unten();

    // Teste Wände
    errors += test_spielfeld_wand_links();
    errors += test_spielfeld_wand_rechts();
    errors += test_spielfeld_wand_unten();

    return errors;
}
