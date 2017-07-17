//
// Created by Lukas Wolfsteiner on 27.04.17.
//

#ifndef PG2_SL_SOSE2017_NODEPAD_H
#define PG2_SL_SOSE2017_NODEPAD_H

#define BUFFER_SIZE 100

class Notepad {
public:
    void notepad_create();

    void notepad_write(char *str);

    char *notepad_read();

private:
    char *text, buffer[BUFFER_SIZE];
};


#endif //PG2_SL_SOSE2017_NODEPAD_H