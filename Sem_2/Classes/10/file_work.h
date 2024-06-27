#ifndef FILE_WORK
#define FILE_WORK

#include "time.h"

int make_file(const char *filename) {
    std::fstream stream(filename, std::ios::out|std::ios::trunc);
    if (!stream) {
        return -1;
    }

    int n;
    Time t;
    std::cout << "N?: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        stream << t << std::endl;
    }
    stream.close();
    return n;
}

int print_file(const char *filename) {
    std::fstream stream(filename, std::ios::in);
    if (!stream) {
        return -1;
    }

    Time t;
    int i = 0;

    while (stream >> t) {
        std::cout << t << std::endl;
        ++i;
    }

    stream.close();
    return i;
}

int del_file(const char *filename, int k) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(filename, std::ios::in);
    if (!stream) {
        return -1;
    }

    int i = 0;
    Time t;

    while (stream >> t) {
        if (stream.eof()) {
            break;
        }

        ++i;
    }

    if (i != k) {
        temp << t;
    }

    stream.close();
    temp.close();
    remove(filename);
    rename("temp", filename);
    return i;
}

int add_file(const char *filename, int k, Time tt) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(filename, std::ios::in);
    if (!stream) {
        return -1;
    }

    Time t;
    int i = 0, l = 0;

    while (stream >> t) {
        if (stream.eof()) {
            break;
        }

        ++i;
        if (i == k) {
            temp << tt;
            ++l;
        }
        temp << t;
    }

    stream.close();
    temp.close();
    remove(filename);
    rename("temp", filename);
    return l;
}

int add_end(const char *filename, Time tt) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(filename, std::ios::in);
    if (!stream) {
        return -1;
    }

    stream << tt;

    return 1;
}

int change_file(const char *filename, int k, Time tt) {
    std::fstream temp("temp", std::ios::out);
    std::fstream stream(filename, std::ios::in);
    if (!stream) {
        return -1;
    }

    Time t;
    int i = 0, l = 0;
    char x;

    while (stream >> x) {
        if (stream.eof()) {
            break;
        }

        ++i;

        if (i == k) {
            std::cout << t << " - is changing... Continue[y/n]?\n";
            std::cin >> x;
            if (x == 'n' || x == 'N') {
                break;
            }

            temp << tt;
            ++l;
        }

        else {
            temp << t;
        }
    }

    stream.close();
    temp.close();
    remove(filename);
    rename("temp", filename);
    return l;
}

#endif