#include "libs/Field.h"
#include "libs/Renderer.h"

int main() {
    Field field;
    Stone stone;
    Renderer renderer;

    renderer.addObject(&field);
    renderer.addObject(&stone);

    renderer.Render();

    return 0;
}