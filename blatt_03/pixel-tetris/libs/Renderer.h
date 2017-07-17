//
// Created by Lukas Wolfsteiner on 12.04.17.
//

#ifndef PG2_SL_SOSE2017_RENDERER_H
#define PG2_SL_SOSE2017_RENDERER_H


#include "Field.h"

class Renderer {

private:
    char screen_buffer[HEIGHT_Y][WIDTH_X];
    Field *field;
    Stone *stone;

    void screenBufferAdd(Field *field);

    void screenBufferAdd(Stone *stone);

    void screenBufferAdd(XyPair xyPair, char buffer);

public:
    Renderer();

public:
    void Render();

    void addObject(Field *field);

    void addObject(Stone *stone);
};


#endif //PG2_SL_SOSE2017_RENDERER_H
