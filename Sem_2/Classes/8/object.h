#ifndef OBJECT_H
#define OBJECT_H

#include "event.h"

class Object {
    public:
        Object(void);
        virtual void show()=0;
        virtual void input()=0;
        virtual ~Object(void);
        virtual void handle_event(const TEvent& event)=0;
};

#endif