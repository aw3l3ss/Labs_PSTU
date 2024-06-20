#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include "object.h"

class Pair: public Object{
    protected:
        int first;
        int second;
    public:
        Pair(void);
        ~Pair();
        Pair(int first, int second);
        Pair(const Pair &pair);
        
        int get_first();
        int get_second();
        void set_first(int first);
        void set_second(int second);

        void show();
        
        Pair operator + (const Pair &pair);
        
        friend std::istream &operator >> (std::istream &in, Pair &pair); 
        friend std::ostream &operator << (std::ostream &out, const Pair &pair);
};

#endif