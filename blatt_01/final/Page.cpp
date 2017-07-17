#include "Page.h"

using namespace std;

void Page::write(string str) {
    buffer += str;

    return;
}

string Page::print() {
    return buffer;
}

Page::Page() {
}


Page::~Page() {
}
