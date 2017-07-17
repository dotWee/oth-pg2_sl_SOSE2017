#pragma once

#include <list>
#include <array>
#include "xy_pair_type.h"
#include "List.h"

class Field;

class Stone;


class Renderer {
    std::array<std::array<char, 18>, 22> screen_buffer;
    MyList<Field> field_list;
    MyList<Stone> stone_list;

    void screenBufferAdd();

public:
    void Render();

    void addObject(Field &);

    void addObject(Stone &);


    Renderer();

    ~Renderer();
};

