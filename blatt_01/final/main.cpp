#include <iostream>

#include "Book.h"

using namespace std;


int main() {
    Book book;
    string str = "";

    while (true) {
        getline(cin, str);

        if (str.compare("/exit") == 0) {
            book.close();
        } else if (str.substr(0, 5).compare("/book") == 0) {
            book.select_book((int) (str.substr(5, 1)[0] - 0x30));
        } else if (str.compare("/print") == 0) {
            cout << book.print() << endl;
        } else {
            book.write(str);
        }

    }

    system("pause");

    return 0;
}