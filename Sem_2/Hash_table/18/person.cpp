#include "person.h"

struct Person {
    std::string full_name;
    std::string passport;
    std::string address;
};

Person *init_person() {
    return new Person;
}

void add_data(Person *p, std::string full_name, std::string passport, std::string address) {   
    p->full_name = full_name;
    p->passport = passport;
    p->address = address;
}

std::string get_name(Person *p) {
    return p->full_name;
}

std::string get_passport(Person *p) {
    return p->passport;
}

std::string get_address(Person *p) {
    return p->address;
}

void delete_person(Person *p) {
    delete p;
}

std::string get_info(Person *p) {
    return (p->full_name + "&" + p->passport + "&" + p->address);
}

void set_info(Person *p, std::string info) {
    int cnt = 0;
    std::string full_name, passport, address;
    for (int i = 0; i < info.size(); ++i) {
        if (info[i] != '&') {
            if (cnt == 0) {
                full_name += info[i];
            }     
            
            else if (cnt == 1) {
                passport += info[i];
            } 

            else if (cnt == 2) {
                address += info[i];
            }
        }

        else {
            ++cnt;
        }
    }

    p->full_name = full_name;
    p->passport = passport;
    p->address = address;
}