#include <iostream>
#include "libs/Field.h"
#include "test/FieldTest.h"
#include "test/StoneTest.h"

int main() {
    int errors = 0;

    // Teste Field-Klasse
    Field field;
    FieldTest fieldTest(field);
    int errors_field = fieldTest.test();
    std::cout << "Fehlerzahl der Field-Klasse: " << errors_field << "\n";
    errors += errors_field;

    // Teste Stone-Klasse
    Stone stone;
    StoneTest stoneTest(stone);
    int errors_stone = stoneTest.test();
    std::cout << "Fehlerzahl der Stone-Klasse: " << errors_stone << "\n";
    errors += errors_stone;

    return errors;
}