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
        T &operator[](int index);
        int operator()();
        Vector operator*(const int elem);

        template <class U>
        friend std::ostream &operator<<(std::ostream &out, const Vector<U> &a);

        template <class U>
        friend std::istream &operator>>(std::istream &in, Vector<U> &a);
};

template <class T>
Vector<T>::Vector(int size, T elem) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = elem;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T> &a) {
    this->size = a.size;
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

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &a) {
    if (this == &a) {
        return *this;
    }

    if (data) {
        delete[] data;
    }

    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }

    return *this;
}

template <class T>
T &Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cout << "Index out of range!" << std::endl;
        static T tmp;
        return tmp;
    }
    return data[index];
}

template <class T>
int Vector<T>::operator()() {
    return size;
}

template <class T>
Vector<T> Vector<T>::operator*(const int elem) {
    Vector<T> result(size, T());
    for (int i = 0; i < size; i++) {
        result[i] = data[i] * elem;
    }
    return result;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &a) {
    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }
    return out;
}

template <class T>
std::istream &operator>>(std::istream &in, Vector<T> &a) {
    for (int i = 0; i < a.size; i++) {
        in >> a.data[i];
    }
    return in;
}

#endif