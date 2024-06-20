#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class Object {
    public:
        Object(void);
        ~Object(void);
        virtual void show()=0;
};

#endif