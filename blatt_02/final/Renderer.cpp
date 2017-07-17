#include "Renderer.h"

#include "Field.h"
#include "Stone.h"
#include <iostream>

using namespace std;

void Renderer::screenBufferAdd(Field *field) {
    for (int y_glob = field->pos_y(), y_loc = 0; y_loc < field->size_y(); y_glob++, y_loc++) {
        for (int x_glob = field->pos_x(), x_loc = 0; x_loc < field->size_x(); x_glob++, x_loc++) {
            screen_buffer[y_glob][x_glob] = field->getBuffer({y_loc, x_loc});
        }
    }

}

void Renderer::screenBufferAdd(Stone *stone) {
    for (int y_glob = stone->pos_y(), y_loc = 0; y_loc < stone->size_y(); y_glob++, y_loc++) {
        for (int x_glob = stone->pos_x(), x_loc = 0; x_loc < stone->size_x(); x_glob++, x_loc++) {
            if (screen_buffer[y_glob][x_glob] == ' ') {
                screen_buffer[y_glob][x_glob] = stone->getBuffer({y_loc, x_loc});
            }
        }
    }

}

void Renderer::Render() {
    for (int y_glob = field->pos_y(), y_loc = 0; y_loc < field->size_y(); y_glob++, y_loc++) {
        for (int x_glob = field->pos_x(), x_loc = 0; x_loc < field->size_x(); x_glob++, x_loc++) {
            screen_buffer[y_glob][x_glob] = field->getBuffer({y_loc, x_loc});
        }
    }

    for (int y_glob = stone->pos_y(), y_loc = 0; y_loc < stone->size_y(); y_glob++, y_loc++) {
        for (int x_glob = stone->pos_x(), x_loc = 0; x_loc < stone->size_x(); x_glob++, x_loc++) {
            if (screen_buffer[y_glob][x_glob] == ' ') {
                screen_buffer[y_glob][x_glob] = stone->getBuffer({y_loc, x_loc});
            }
        }
    }

    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            cout << screen_buffer[y][x];
        }
        cout << endl;
    }

}

void Renderer::addObject(Field *field) {
    this->field = field;
}

void Renderer::addObject(Stone *stone) {
    this->stone = stone;
}

Renderer::Renderer() {
}


Renderer::~Renderer() {
}
