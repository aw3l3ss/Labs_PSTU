#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class T>
class Vector {
    private:
        int size;
        T *data;
    public:
        Vector(int size, T elem);
        Vector(const Vector<T> &a);
        ~Vector();
        Vector &operator=(const Vector<T> &a);
        int &operator[](int index);
        int operator()();
        Vector operator*(const T elem);
        friend std::ostream &operator<< <>(std::ostream &out, const Vector<T> &a);
        friend std::istream &operator>> <>(std::istream &in, Vector<T> &a);
};

template <class T>
Vector<T>::Vector(int size, T elem) {
    this.size = size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = elem;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T> &a) {
    this.size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    delete[] data;
    data = 0;
}



#endif