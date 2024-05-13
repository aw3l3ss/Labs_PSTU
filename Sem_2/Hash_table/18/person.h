#ifndef PERSON_H
#define PERSON_H

#include <string>

typedef struct Person Person;

Person *init_person();
void add_data(Person *p, std::string full_name, std::string passport, std::string address);
std::string get_name(Person *p);
std::string get_passport(Person *p);
std::string get_address(Person *p);

std::string get_info(Person *p);
void set_info(Person *p, std::string info);

void delete_person(Person *p);

#endif