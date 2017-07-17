#include "Renderer.h"

#include "Field.h"
#include "Stone.h"
#include <iostream>

using namespace std;

void Renderer::screenBufferAdd() {
    for (MyList<Field>::iterator it = field_list.begin(); it != field_list.end(); ++it) {

        int y = 0;
        for (auto &&arr : it->getBuffer()) {
            int x = 0;
            for (auto &&var : arr) {
                screen_buffer[y][x] = var;
                ++x;
            }
            ++y;
        }
    }
    for (MyList<Stone>::iterator it = stone_list.begin(); it != stone_list.end(); ++it) {
        for (int y_glob = it->pos_y(), y_loc = 0; y_loc < it->size_y(); y_glob++, y_loc++) {
            for (int x_glob = it->pos_x(), x_loc = 0; x_loc < it->size_x(); x_glob++, x_loc++) {
                if (screen_buffer[y_glob][x_glob] == ' ') {
                    screen_buffer[y_glob][x_glob] = it->getBuffer({y_loc, x_loc});
                }
            }
        }
    }
}

void Renderer::Render() {
    screenBufferAdd();

    for (auto &&arr : screen_buffer) {
        for (auto &&var : arr) {
            cout << var;
        }
        cout << endl;
    }

}

void Renderer::addObject(Field &field) {
    field_list.push_back(ref(field));
}

void Renderer::addObject(Stone &stone) {
    stone_list.push_back(ref(stone));
}

Renderer::Renderer() {
}


Renderer::~Renderer() {
}
