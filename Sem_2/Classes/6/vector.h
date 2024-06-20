#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Iterator {
    friend class Vector;
    private:
        int *elem;
    public:
        Iterator() {elem = 0;}
        Iterator(int elem) {this->elem = &elem;}
        Iterator(Iterator &it) {elem = it.elem;}
        bool operator==(const Iterator &it){return elem == it.elem;}
        bool operator!=(const Iterator &it){return elem != it.elem;}
        void operator-=(const int k){*elem -= k;}
        int operator*() {return *elem;};
};

class Vector {
    private:
        int size;
        int *data;
        Iterator begin;
        Iterator end;
    public:
        Vector(int size, int element = 0);
        Vector(const Vector &a);
        ~Vector();
        Vector &operator=(const Vector &a);
        int &operator[](int index);
        int operator()();
        Vector operator*(const int k);
        Vector operator-(const int k);
        Iterator first(){return begin;}
        Iterator last(){return end;}
        friend std::ostream &operator<<(std::ostream &, const Vector &a);
        friend std::istream &operator>>(std::istream &, Vector &a);
};

#endif