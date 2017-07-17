//
// Created by wol32832 on 29.03.2017.
//
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

namespace blatt_01_aufgabe_03 {
#define BUFFER_SIZE 100
#define PAGES 3

    class Page {
    public:
        void write(string text) {
            cout << text << endl;
        }

        string print() {
            return buffer;
        }

    private:
        string buffer;
    };

    class Book {
    public:
        void select_book(int page) {
            currentpage = pages[page];
        }

        void write(string text) {
            currentpage.write(text);
        }

        string print() {
            return currentpage.print();
        }

        void close() {
            free(pages);
            exit(0);
        }

    private:
        Page pages[PAGES];
        Page currentpage = pages[0];
    };

    class Notepad {
    public:
        void notepad_run() {
            notepad_create();

            while (true) {
                // Alternativ: fgets(buffer, BUFFER_SIZE, stdin);
                cin.getline(buffer, BUFFER_SIZE);

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
                    cout << notepad_read();
                }

                    // Wenn Buffer '\exit' enthält, beende Schleife
                else if (strstr(buffer, "\\exit")) {
                    break;
                }

                    // Kopiere Text aus Buffer in die Zielvariable
                else {
                    notepad_write(buffer);

                    // Wenn text länger als maximal erlaubte Länge, beende Schleife
                    if (notepad_read().length() > BUFFER_SIZE) {
                        break;
                    }
                }

            }
        }

    private:
        char buffer[BUFFER_SIZE];
        int currentpage;
        Book book;

        void notepad_create() {
            currentpage = 0;
        }

        void notepad_write(char *str) {
            book.write(str);
        }

        void notepad_debug() {
            printf("[DEBUG] current-page=%d content=%s\n", currentpage, notepad_read().data());
        }

        string notepad_read() {
            book.select_book(currentpage);
            return book.print();
        }
    };
}

int main() {
    std::cout << "Gib einen Text ein:\n";

    blatt_01_aufgabe_03::Notepad notepad;
    notepad.notepad_run();

    return 0;
}