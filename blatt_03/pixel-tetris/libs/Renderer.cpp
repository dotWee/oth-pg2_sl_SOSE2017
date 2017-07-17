//
// Created by Lukas Wolfsteiner on 12.04.17.
//

#include <iostream>
#include "Renderer.h"

void Renderer::screenBufferAdd(Field *field) {

    // Für jede Zeile
    for (int y = 0; y <= HEIGHT_Y; ++y) {

        // Für jede Spalte
        for (int x = 0; x <= WIDTH_X; ++x) {
            XyPair xyPair = XyPair(x, y);
            char buffer = field->getBuffer(xyPair);

            screenBufferAdd(xyPair, buffer);
        }
    }
}

void Renderer::screenBufferAdd(Stone *stone) {

    // Für jede Zeile
    for (int y = 0; y <= HEIGHT_Y; ++y) {

        // Für jede Spalte
        for (int x = 0; x <= WIDTH_X; ++x) {
            XyPair xyPair = XyPair(x + stone->pos_x(), y + stone->pos_y());
            char buffer = stone->getBuffer(xyPair);

            screenBufferAdd(xyPair, buffer);
        }
    }
}

void Renderer::Render() {

    // Für jede Zeile
    for (int y = 0; y <= HEIGHT_Y; ++y) {

        // Für jede Spalte
        for (int x = 0; x <= WIDTH_X; ++x) {

            // Gib Char aus Buffer aus
            char value = screen_buffer[y][x];
            std::cout << value;

            // Gib Int-Wert von char zu Debug-Zwecken aus
            //std::cout << (char) 32 << (int) value;

            // Letzte Spalte -> Newline
            if (x == WIDTH_X) {
                std::cout << '\n';
            }
        }

    }
}

void Renderer::addObject(Field *field) {
    this->field = field;
    screenBufferAdd(field);
}

void Renderer::addObject(Stone *stone) {
    this->stone = stone;
    screenBufferAdd(stone);
}

Renderer::Renderer() {

}

void Renderer::screenBufferAdd(XyPair xyPair, char buffer) {
    screen_buffer[xyPair.getY()][xyPair.getX()] = buffer;
}
