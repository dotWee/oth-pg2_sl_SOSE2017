//
// Created by Lukas Wolfsteiner on 27.04.17.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Notepad.h"

void Notepad::notepad_run() {
    notepad_create();

    while (true) {
        // Alternativ: fgets(buffer, BUFFER_SIZE, stdin);
        std::cin.getline(buffer, BUFFER_SIZE);

        // Wenn Buffer '\debug' enthält, gib Debug Nachricht aus
        if (strstr(buffer, "\\debug")) {
            notepad_debug();
        }

            // Wenn Buffer '\page' enthält, wechlse Seite
        else if (strstr(buffer, "\\book")) {
            char pagevalue = strstr(buffer, "\\book")[5];
            currentpage = atoi(&pagevalue);

            printf("Switched to page %d", currentpage);
            currentpage--;
        }

            // Wenn Buffer '\read' enthält, gib text aus
        else if (strstr(buffer, "\\read")) {
            std::cout << notepad_read();
        }

            // Wenn Buffer '\exit' enthält, beende Schleife
        else if (strstr(buffer, "\\exit")) {
            break;
        }

            // Kopiere Text aus Buffer in die Zielvariable
        else {
            notepad_write(buffer);

            // Wenn text länger als maximal erlaubte Länge, beende Schleife
            if (strlen(notepad_read()) > BUFFER_SIZE) {
                break;
            }
        }

    }
}

void Notepad::notepad_debug() {
    printf("[DEBUG] current-page=%d content=%s\n", currentpage, notepad_read());
}

void Notepad::notepad_create() {
    currentpage = 0;
    book;
}

void Notepad::notepad_write(char *str) {
    book.writeonpage(str, currentpage);
}

char *Notepad::notepad_read() {
    return book.getpage(currentpage);
}
