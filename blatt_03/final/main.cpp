#include <iostream>
#include "Field.h"
#include "Stone.h"
#include "Renderer.h"

using namespace std;


int main() {
    Stone stone1({0, 0});
    Stone stone2({0, 13});
    Field field({0, 0}, &stone1, &stone2);
    Renderer renderer;

    renderer.addObject(field);
    renderer.addObject(stone1);
    renderer.addObject(stone2);

    renderer.Render();

    system("pause");

    return 0;
}