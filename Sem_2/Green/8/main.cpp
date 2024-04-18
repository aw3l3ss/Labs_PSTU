#include <iostream>
#include <vector>
#include <string>
#include "person.h"

void write_to_bin_file(const std::vector<Person*>& arr, std::string filename);
void read_from_bin_file(std::vector<Person*>& arr, std::string filename);
void delete_arr(std::vector<Person*>& arr);
void delete_by_age(std::vector<Person*>& arr);
void add_by_index(std::vector<Person*>& arr);
void print_arr(const std::vector<Person*>& arr);

int main() {
    std::vector<Person*> arr;
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    char ans = 'y';
    while (ans != 'n') {
        Person *p = create_person();
        std::string name, address, phone;
        int age;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter address: ";
        std::getline(std::cin, address);
        std::cout << "Enter phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cin.ignore();

        add_data_to_person(p, name, address, phone, age);
        arr.push_back(p);

        std::cout << "Do you want to add another person? (y/n): ";
        std::cin >> ans;
        std::cin.ignore();
    }

    write_to_bin_file(arr, filename);
    delete_arr(arr);

    read_from_bin_file(arr, filename);
    print_arr(arr);
    delete_by_age(arr);
    add_by_index(arr);
    write_to_bin_file(arr, filename);
    delete_arr(arr);

    read_from_bin_file(arr, filename);
    print_arr(arr);
    delete_arr(arr);

    return 0;
}

void write_to_bin_file(const std::vector<Person*>& arr, std::string filename) {
    FILE *file = fopen(filename.c_str(), "wb");

    int size = arr.size();
    fwrite(&size, sizeof(int), 1, file);

    for (Person* person : arr) {
        int tmp;

        tmp = get_name(person).length();
        fwrite(&tmp, sizeof(int), 1, file);
        fwrite(get_name(person).c_str(), sizeof(char), tmp, file);

        tmp = get_address(person).length();
        fwrite(&tmp, sizeof(int), 1, file);
        fwrite(get_address(person).c_str(), sizeof(char), tmp, file);

        tmp = get_phone(person).length();
        fwrite(&tmp, sizeof(int), 1, file);
        fwrite(get_phone(person).c_str(), sizeof(char), tmp, file);

        tmp = get_age(person);
        fwrite(&tmp, sizeof(int), 1, file);
    }

    fclose(file);
}

void read_from_bin_file(std::vector<Person*>& arr, std::string filename) {
    FILE *file = fopen(filename.c_str(), "rb");

    int size;
    fread(&size, sizeof(int), 1, file);

    for (int i = 0; i < size; i++) {
        Person *p = create_person();
        int tmp;

        fread(&tmp, sizeof(int), 1, file);
        std::string name;
        name.resize(tmp);
        fread(&name[0], sizeof(char), tmp, file);
        
        fread(&tmp, sizeof(int), 1, file);
        std::string address;
        address.resize(tmp);
        fread(&address[0], sizeof(char), tmp, file);

        fread(&tmp, sizeof(int), 1, file);
        std::string phone;
        phone.resize(tmp);
        fread(&phone[0], sizeof(char), tmp, file);

        fread(&tmp, sizeof(int), 1, file);
        
        add_data_to_person(p, name, address, phone, tmp);

        arr.push_back(p);
    }

    fclose(file);
}

void delete_arr(std::vector<Person*>& arr) {
    for (Person* person : arr) {
        delete_person(person);
    }

    arr.clear();
    arr.shrink_to_fit();
}

void delete_by_age(std::vector<Person*>& arr) {
    int age;
    std::cout << "Enter age to delete: ";
    std::cin >> age;

    auto it = arr.begin();
    while (it != arr.end()) {
        if (get_age(*it) == age) {
            delete_person(*it);
            it = arr.erase(it);
        } else {
            ++it;
        }
    }
}

void add_by_index(std::vector<Person*>& arr) {
    int index;
    std::cout << "Enter index to add: ";
    std::cin >> index;

    if (index < 0 || index > arr.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    Person *p = create_person();
    std::string name, address, phone;
    int age;

    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore();
    
    add_data_to_person(p, name, address, phone, age);
    arr.insert(arr.begin() + index + 1, p);
}

void print_arr(const std::vector<Person*>& arr) {
    for (Person* person : arr) {
        std::cout << "Name: " << get_name(person) << std::endl;
        std::cout << "Address: " << get_address(person) << std::endl;
        std::cout << "Phone: " << get_phone(person) << std::endl;
        std::cout << "Age: " << get_age(person) << std::endl;
        std::cout << std::endl;
    }
}
