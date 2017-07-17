//
// Created by Lukas Wolfsteiner on 27.04.17.
//

#ifndef PG2_SL_SOSE2017_BOOK_H
#define PG2_SL_SOSE2017_BOOK_H


#define BUFFER_SIZE 100
#define PAGES 3

class Book {
public:
    Book();

    void writeonpage(char *str, int page);

    char *getpage(int page);

    int size();

private:
    char *pages[];
};

#endif //PG2_SL_SOSE2017_BOOK_H
