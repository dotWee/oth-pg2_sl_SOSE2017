//
// Created by Lukas Wolfsteiner on 11.04.17.
//

#include "XyPair.h"

int XyPair::getX() {
    return x;
}

int XyPair::getY() {
    return y;
}

XyPair::XyPair(int x, int y) {
    this->x = x;
    this->y = y;
}