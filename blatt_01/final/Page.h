#ifndef __PAGE__H__
#define __PAGE__H__

#include <string>

class Page {
private:
    std::string buffer = "";

    void write(std::string);

    std::string print();

    friend class Book;

public:
    Page();

    ~Page();
};

#endif // __PAGE__H__