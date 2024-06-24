#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

const int MAX_SIZE = 30;

class Vector {
    private:
        int size;
        int *beg;
    public:
        Vector() { size = 0; beg = 0; }
        Vector(int s);
        Vector(int s, int *mas);
        Vector(const Vector &v);
        ~Vector();
        const Vector &operator=(const Vector &v);
        int &operator[](int i);
        Vector &operator--();
        Vector operator--(int);

        friend std::ostream &operator<<(std::ostream &out, const Vector &v);
        friend std::istream &operator>>(std::istream &in, Vector &v);
};

#endif