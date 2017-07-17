#ifndef __BOOK__H__
#define __BOOK__H__

#include "Page.h"
#include <string>

class Book {
private:
    Page page[3];
    Page *active_book = &page[0];
public:
    void select_book(int);

    void write(std::string);

    std::string print();

    void close();

    Book();

    ~Book();
};

#endif // __PAGE__H__