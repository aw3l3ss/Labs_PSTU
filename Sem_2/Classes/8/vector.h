#ifndef VECTOR_H
#define VECTOR_H

#include "object.h"

class Vector {
    protected:
        Object **beg;
        int size;
        int cur;
    public:
        Vector(void);
        Vector(int);
        ~Vector(void);
        void add();
        void del();
        void show();
        int operator()();
        void handle_event(const TEvent &e);
};

#endif