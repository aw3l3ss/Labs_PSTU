#ifndef BOOK_H
#define BOOK_H

#include "print.h"

class Book : public Print {
    protected:
        int pages;
        std::string publishing_house;
    public:
        Book(void);
        ~Book(void);
        void show();
        void input();
        Book(std::string, std::string, int, std::string);
        Book(const Book &);
        Book &operator=(const Book &);
        int get_pages() const { return pages; };
        std::string get_publishing_house() const { return publishing_house; };
        void set_pages(int p) { pages = p; };
        void set_publishing_house(std::string ph) { publishing_house = ph; };
};

#endif