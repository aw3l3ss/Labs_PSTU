#include <iostream>
#include "hash_table.h"

std::string random_full_name();
std::string random_passport();
std::string random_address();
Hash_table *input(int *hash_table_size, int type);
void output(Hash_table *hash_table, int hash_table_size, int type);
void insert_element(Hash_table *hash_table, int hash_table_size);
void delete_element(Hash_table *hash_table, int hash_table_size);
void find_element(Hash_table *hash_table, int hash_table_size);

int main() {
    srand(time(NULL));

    int hash_table_size;

    Hash_table *hash_table = NULL;

    int ch = -1;
    while (ch != 0) {
        std::cout << std::endl << "1) Input hash table from console" << std::endl;
        std::cout << "2) Input hash table from file" << std::endl;
        std::cout << "3) Output hash table to console" << std::endl;
        std::cout << "4) Output hash table to file" << std::endl;
        std::cout << "5) Count of collisions" << std::endl;
        std::cout << "6) Clear hash table" << std::endl;
        std::cout << "7) Add element to hash table" << std::endl;
        std::cout << "8) Delete element from hash table by key" << std::endl;
        std::cout << "9) Find element in hash table by key" << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::cout << std::endl << "Enter your choice: ";
        std::cin >> ch;
        std::cout << std::endl;
        switch (ch) {
            case 0: 
                std::cout << "Exiting..." << std::endl;
                delete_hash_table(hash_table, &hash_table_size);
                break;
            case 1:
                if (hash_table != NULL) {
                    delete_hash_table(hash_table, &hash_table_size);
                    hash_table = NULL;
                }
                hash_table = input(&hash_table_size, 1);
                break;
            case 2:
                if (hash_table != NULL) {
                    delete_hash_table(hash_table, &hash_table_size);
                    hash_table = NULL;
                }
                hash_table = input(&hash_table_size, 2);
                break;
            case 3:
                output(hash_table, hash_table_size, 1);
                break;
            case 4:
                output(hash_table, hash_table_size, 2);
                break;
            case 5:
                std::cout << "Count of collisions: " << count_collisions(hash_table, hash_table_size) << std::endl;
                break;
            case 6:
                delete_hash_table(hash_table, &hash_table_size);
                hash_table = NULL;
                break;
            case 7:
                insert_element(hash_table, hash_table_size);
                break;
            case 8:
                delete_element(hash_table, hash_table_size);
                break;
            case 9:
                find_element(hash_table, hash_table_size);
                break;
            default:
                std::cout << "Invalid input" << std::endl;
        }
    }

    return 0;
}

std::string random_full_name() {
    std::string first_name[10] = {"Ivan", "Peter", "Alexander", "Michael", "Dmitry", "Vasily", "Nikolay", "Aleksey", "Sergey", "Vladimir"};
    std::string surname[10] = {"Ivanov", "Petrov", "Sidorov", "Mikhaylov", "Dmitriev", "Vasiliev", "Nikolaev", "Alekseev", "Sergeev", "Vladimirov"};
    std::string patronymic[10] = {"Ivanovich", "Petrovich", "Sidorovich", "Mikhaylovich", "Dmitrievich", "Vasilievich", "Nikolaevich", "Alekseevich", "Sergeevich", "Vladimirovich"};

    return (surname[rand() % 10] + " " + first_name[rand() % 10] + " " + patronymic[rand() % 10]);
}

std::string random_passport() {
    return std::to_string(rand() % 9000 + 1000) + " " + std::to_string(rand() % 900000 + 100000);
}

std::string random_address() {
    std::string address[11] = {"Mira", "Lenina", "Pushkina", "Lizi Chaikinoi", "Beliaeva", "Ekaterininskaia", "Popova", "Permskaia", "Sovetskaia", "9 Maia", "Lunacharskogo"};

    return (address[rand() % 11] + " " + std::to_string(rand() % 21 + 1));
}

Hash_table *input(int *hash_table_size, int type) {
    Hash_table *hash_table = NULL;

    if (type == 1) {
        std::cout << "Input hash table size: ";
        std::cin >> *hash_table_size;

        hash_table = init_hash_table(*hash_table_size);

        std::cout << "Input number of elements: ";
        int number_of_elements;
        std::cin >> number_of_elements;

        for (int i = 0; i < number_of_elements; ++i) {
            std::string full_name, passport, address;
            
            full_name = random_full_name();
            passport = random_passport();
            address = random_address();

            Person *person = init_person();
            add_data(person, full_name, passport, address);

            add_element_to_hash_table(hash_table, passport, get_info(person), *hash_table_size);

            delete_person(person);
        }
    }

    if (type == 2) {
        std::cout << "Input file name: ";
        std::string file_name;
        std::cin >> file_name;

        hash_table = read_from_file(hash_table_size, file_name);
    }

    return hash_table;
}

void output(Hash_table *hash_table, int hash_table_size, int type) {
    if (type == 1) {
        output_hash_table(hash_table, hash_table_size);
    }

    if (type == 2) {
        std::cout << "Input file name: ";
        std::string file_name;
        std::cin >> file_name;

        write_to_file(hash_table, hash_table_size, file_name);
    }
}

void insert_element(Hash_table *hash_table, int hash_table_size) {
    std::string full_name, passport, address;
            
    full_name = random_full_name();
    passport = random_passport();
    address = random_address();

    Person *person = init_person();
    add_data(person, full_name, passport, address);

    add_element_to_hash_table(hash_table, passport, get_info(person), hash_table_size);

    delete_person(person);
}

void delete_element(Hash_table *hash_table, int hash_table_size) {
    std::string key;
    std::cout << "Enter key: ";
    getchar();
    std::getline(std::cin, key);

    if(delete_element_from_hash_table(hash_table, hash_table_size, key)) {
        std::cout << "Element deleted" << std::endl;
    }

    else {
        std::cout << "Element not found" << std::endl;
    }
}

void find_element(Hash_table *hash_table, int hash_table_size) {
    std::string key;
    std::cout << "Enter key: ";
    getchar();
    std::getline(std::cin, key);

    Person *person = find_element_in_hash_table(hash_table, hash_table_size, key);

    if (person) {
        std::cout << get_name(person) << " | Passport: " << get_passport(person) << " | Address: " << get_address(person) << std::endl;
    }

    else {
        std::cout << "Element not found" << std::endl;
    }

    delete_person(person);
}