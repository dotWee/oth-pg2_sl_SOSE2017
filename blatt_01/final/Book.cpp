#include "Book.h"

using namespace std;


void Book::select_book(int sel) {
    active_book = &page[sel];

    return;
}

void Book::write(string str) {
    if (active_book != nullptr) {
        active_book->write(str);
    }
    return;
}

string Book::print() {
    string str = "";
    if (active_book != nullptr) {
        str = active_book->print();
    }
    return str;
}

void Book::close() {
    active_book = nullptr;

    exit(1);
}

Book::Book() {
}


Book::~Book() {
}
