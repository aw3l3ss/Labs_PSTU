#include "vector.h"

Vector::Vector(int size, int element) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = element;
    }

    begin.elem = &data[0];
    end.elem = &data[size - 1];
}

Vector::Vector(const Vector &a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = a.data[i];
    }

    begin = a.begin;
    end = a.end;
}

Vector::~Vector() {
    delete[] data;
    data = 0;
    size = 0;
}

Vector &Vector::operator=(const Vector &a) {
    if (this == &a) {
        return *this;
    }

    if (data != 0) {
        delete[] data;
    }

    size = a.size;

    data = new int[size];

    for (int i = 0; i < size; ++i) {
        data[i] = a.data[i];
    }

    begin = a.begin;
    end = a.end;

    return *this;
}

int &Vector::operator[](int index) {
    if (index < size) {
        return data[index];
    }

    else {
        std::cout << "Error! Index > size" << std::endl;
    }
}

int Vector::operator()() {
    return size;
}

Vector Vector::operator*(const int k) {
    Vector temp(size);

    for (int i = 0; i < size; ++i) {
        temp.data[i] = data[i] * k;
    }

    return temp;
}

std::ostream &operator<<(std::ostream &out, const Vector &a) {
    for (int i = 0; i < a.size; ++i) {
        out << a.data[i] << " ";
    }

    return out;
}

std::istream &operator>>(std::istream &in, Vector &a) {
    for (int i = 0; i < a.size; ++i) {
        in >> a.data[i];
    }

    return in;
}