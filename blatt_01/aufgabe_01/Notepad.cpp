//
// Created by Lukas Wolfsteiner on 27.04.17.
//

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Notepad.h"

void Notepad::notepad_create() {
    text = (char *) malloc(sizeof(char) * BUFFER_SIZE);

    while (true) {
        //fgets(buffer, BUFFER_SIZE, stdin);
        std::cin.getline(buffer, BUFFER_SIZE);

        // Wenn Buffer '/read' enthält, gib text aus
        if (strstr(buffer, "\\read")) {
            std::cout << notepad_read();
        }
            // Wenn Buffer '/exit' enthält, beende Schleife
        else if (strstr(buffer, "\\exit")) {
            break;
        } else {
            // Kopiere Text aus Buffer in die Zielvariable
            notepad_write(buffer);

            // Wenn text länger als maximal erlaubte Länge, beende Schleife
            if (strlen(text) > BUFFER_SIZE) {
                break;
            }
        }

    }
}

void Notepad::notepad_write(char *str) {
    text = (char *) realloc(text, strlen(text) + 1 + strlen(str));
    strcat(text, str);
}

char *Notepad::notepad_read() {
    return text;
}