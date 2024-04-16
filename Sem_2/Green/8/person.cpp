#include "person.h"

struct Person {
    std::string name;
    std::string address;
    std::string phone;
    int age;
};

Person *create_person() {
    return (Person *) calloc(1, sizeof(Person));
}

void add_data_to_person(Person *person, std::string name, std::string adress, std::string phone, int age) {
    person->name = name;
    person->address = adress;
    person->phone = phone;
    person->age = age;
}

std::string get_name(Person *person) {
    return person->name;
}

std::string get_adress(Person *person) {
    return person->address;
}

std::string get_phone(Person *person) {
    return person->phone;
}

int get_age(Person *person) {
    return person->age;
}

void delete_person(Person *person) {
    free(person);
}
