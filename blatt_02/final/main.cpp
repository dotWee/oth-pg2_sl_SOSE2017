#include <iostream>
#include "Field.h"
#include "Stone.h"
#include "Renderer.h"

int main() {
    Stone stone1({0, 0});
    Field field({0, 0});
    Renderer renderer;

    renderer.addObject(&field);
    renderer.addObject(&stone1);

    renderer.Render();

    system("pause");

    return 0;
}