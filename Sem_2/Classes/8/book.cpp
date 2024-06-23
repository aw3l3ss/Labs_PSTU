#include "book.h"

#include <iostream>

Book::Book(void) : Print() {
    pages = 0;
    publishing_house = "";
}

Book::~Book(void) {
}

void Book::show() {
    std::cout << "Name: " << name << ", Author: " << author << ", Pages: " << pages << ", Publishing House: " << publishing_house << std::endl;
}

void Book::input() {
    std::getchar();
    std::cout << "Enter book name: ";
    std::getline(std::cin, name);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter number of pages: ";
    std::cin >> pages;
    std::getchar();
    std::cout << "Enter publishing house: ";
    std::getline(std::cin, publishing_house);
}

Book::Book(std::string name, std::string author, int pages, std::string publishing_house) : Print(name, author) {
    this->pages = pages;
    this->publishing_house = publishing_house;
}

Book::Book(const Book& book) {
    name = book.name;
    author = book.author;
    pages = book.pages;
    publishing_house = book.publishing_house;
}

Book& Book::operator=(const Book& book) {
    if (&book == this) {
        return *this;
    }

    name = book.name;
    author = book.author;
    pages = book.pages;
    publishing_house = book.publishing_house;
    return *this;
}