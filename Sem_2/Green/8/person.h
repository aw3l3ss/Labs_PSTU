#ifndef PERSON_H
#define PERSON_H

#include <iostream>

typedef struct Person Person;

Person *create_person();
void add_data_to_person(Person *person, std::string name, std::string adress, std::string phone, int age);
std::string get_name(Person *person);
std::string get_address(Person *person);
std::string get_phone(Person *person);
int get_age(Person *person);
void delete_person(Person *person);

#endif
