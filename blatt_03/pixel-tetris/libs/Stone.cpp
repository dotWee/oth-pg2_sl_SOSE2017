//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#include "Stone.h"

int Stone::pos_x() {
    return pos.getX();
}

int Stone::pos_y() {
    return pos.getY();
}

int Stone::size_x() {
    return size.getX();
}

int Stone::size_y() {
    return size.getY();
}

char Stone::getBuffer(XyPair coord) {
    return buffer[coord.getY()][coord.getX()];
}

Stone::Stone() {
    for (int y = 0; y <= STONE_DIMENSION_DEFAULT; ++y) {
        for (int x = 0; x <= STONE_DIMENSION_DEFAULT; ++x) {

            if (y >= 2 && y <= 3 && x >= 2 && x <= 3) {
                buffer[y][x] = 'X';
            } else {
                buffer[y][x] = ' ';
            }
        }
    }
}