#include "print.h"

#include <iostream>

Print::Print(void) {
    name = "";
    author = "";
}

Print::~Print(void) {
}

void Print::show() {
    std::cout << "Name: " << name << ", Author: " << author << std::endl;
} 

void Print::input() {
    std::getchar();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
}

Print::Print(std::string name, std::string author) {
    this->name = name;
    this->author = author;
}

Print::Print(const Print &other) {
    name = other.name;
    author = other.author;
}

Print& Print::operator=(const Print& other) {
    if (this == &other) {
        return *this;
    }

    name = other.name;
    author = other.author;

    return *this;
}

void Print::handle_event(const TEvent &e) {
    if (e.what == evMessage) {
        switch (e.command) {
            case cmGet:
                std::cout << "Name: " << name << std::endl;
                break;
        }
    }
}