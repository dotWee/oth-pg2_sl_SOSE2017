//
// Created by Lukas Wolfsteiner on 27.04.17.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Book.h"

Book::Book() {
    // Definiere für jede Seite einen Text-Buffer
    for (int page = 0; page <= size(); page++) {
        pages[page] = (char *) malloc(sizeof(char) * BUFFER_SIZE);
    }
}

void Book::writeonpage(char *str, int page) {
    char *pagecontent = getpage(page);

    pages[page] = (char *) realloc(pagecontent, strlen(pagecontent) + 1 + strlen(str));
    strcat(getpage(page), str);
}

char *Book::getpage(int page) {
    if (page >= size()) {
        std::cout << "Warning! Page does not exist!";
        return NULL;
    }

    return pages[page];
}

int Book::size() {
    return PAGES;
}
