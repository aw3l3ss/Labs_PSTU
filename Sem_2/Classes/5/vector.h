#ifndef VECTOR_H
#define VECTOR_H

#include "object.h"

class Vector {
    private:
        Object **beg;
        int size;
        int cur;
    public:
        Vector(void);
        Vector(int);
        ~Vector(void);
        void add_object(Object *);
        friend std::ostream& operator<<(std::ostream&, const Vector&);
};

#endif