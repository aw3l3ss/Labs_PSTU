#ifndef PRINT_H
#define PRINT_H

#include "object.h"
#include <string>

class Print : public Object {
    protected:
        std::string name;
        std::string author;
    public:
        Print(void);
        virtual ~Print(void);
        void show();
        void input();
        Print(std::string, std::string);
        Print(const Print&);
        std::string get_name() const { return name; }
        std::string get_author() const { return author; }
        void set_name(std::string n) { name = n; }
        void set_author(std::string a) { author = a; }
        Print& operator=(const Print&);
        void handle_event(const TEvent &e);
};

#endif