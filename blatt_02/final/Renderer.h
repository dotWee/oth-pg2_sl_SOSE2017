#pragma once

#include "xy_pair_type.h"
#include <list>

class Field;

class Stone;


class Renderer {
    char screen_buffer[22][12];
    Field *field;
    Stone *stone;

    xy_pair size = {22, 12};

    void screenBufferAdd(Field *);

    void screenBufferAdd(Stone *);

public:
    void Render();

    void addObject(Field *);

    void addObject(Stone *);

    Renderer();

    ~Renderer();
};

