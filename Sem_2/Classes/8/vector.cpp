#include "vector.h"

#include <iostream>
#include "print.h"
#include "book.h"

Vector::Vector() {
    beg = 0;
    cur = 0;
    size = 0;
}

Vector::Vector(int size) {
    beg = new Object*[size];
    cur = 0;
    this->size = size;
}

Vector::~Vector() {
    if (beg != 0) {
        delete[] beg;
    }

    beg = 0;
    cur = 0;
    size = 0;
}

void Vector::add() {
    Object *p;
    std::cout << "1. Print\n2. Book" << std::endl;
    int ch;
    std::cin >> ch;

    if (ch == 1) {
        Print *a = new (Print);
        a->input();

        p = a;

        if (cur < size) {
            beg[cur++] = p;
        }
    }

    else if (ch == 2) {
        Book *a = new (Book);
        a->input();
        p = a;
        if (cur < size) {
            beg[cur++] = p;
        }
    }

    else {
        std::cout << "Invalid choice" << std::endl;
        return;
    }
}

void Vector::show() {
    if (cur == 0) {
        std::cout << "Vector is empty" << std::endl;
        return;
    }

    Object **p = beg;
    for (int i = 0; i < cur; i++) {
        (*p)->show();
        ++p;
    }
}

int Vector::operator()() {
    return cur;
}

void Vector::del() {
    if (cur == 0) {
        std::cout << "Vector is empty" << std::endl;
        return;
    }

    cur--;
}

void Vector::handle_event(const TEvent &e) {
    if (e.what == evMessage) {
        if (e.a < 0 || e.a >= cur) {
            std::cout << "Invalid index" << std::endl;
            return;
        }

        else {
            Object **p = beg;
            for (int i = 0; i < e.a; ++i) {
                ++p;
            }
            (*p)->handle_event(e);
        }
    }
}