#include <iostream>
#include <string>
#include <vector>

typedef struct Person {
    std::string full_name;
    std::string home_address;
    std::string phone_number;
    int age;
} Person;

void writePersonToFile(std::vector<Person> &persons, std::string filename);
void readPersonFromFile(std::vector<Person> &persons, std::string filename);
void format(std::vector<Person> &persons);
void print(std::vector<Person> &persons);

int main() {
    std::vector<Person> persons;
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    while (true) {
        getchar();

        Person person;

        std::cout << "Enter full name: ";
        std::getline(std::cin, person.full_name);
        std::cout << "Enter home address: ";
        std::getline(std::cin, person.home_address);
        std::cout << "Enter phone number: ";
        std::getline(std::cin, person.phone_number);
        std::cout << "Enter age: ";
        std::cin >> person.age;

        persons.push_back(person);

        std::cout << "Add one more? (y/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }
    }

    writePersonToFile(persons, filename);
    readPersonFromFile(persons, filename);    
    print(persons);

    format(persons);

    writePersonToFile(persons, filename);
    readPersonFromFile(persons, filename);
    print(persons);

    return 0;
}

void writePersonToFile(std::vector<Person> &persons, std::string filename) {
    FILE *f = fopen(filename.c_str(), "wb");
    size_t size = persons.size();

    fwrite(&size, sizeof(size_t), 1, f);

    for (size_t i = 0; i < size; i++) {
        size_t length;
        Person person = persons[i];

        length = person.full_name.size();
        fwrite(&length, sizeof(size_t), 1, f);
        fwrite(person.full_name.c_str(), sizeof(char), length, f);

        length = person.home_address.size();
        fwrite(&length, sizeof(size_t), 1, f);
        fwrite(person.home_address.c_str(), sizeof(char), length, f);

        length = person.phone_number.size();
        fwrite(&length, sizeof(size_t), 1, f);
        fwrite(person.phone_number.c_str(), sizeof(char), length, f);

        fwrite(&person.age, sizeof(int), 1, f);
    }

    fclose(f);
}

void readPersonFromFile(std::vector<Person> &persons, std::string filename) {
    FILE *f = fopen(filename.c_str(), "rb");
    size_t size = persons.size();

    fread(&size, sizeof(size_t), 1, f);
    persons.resize(size);
    
    for (size_t i = 0; i < size; i++) {
        size_t length;
        Person person = persons[i];

        fread(&length, sizeof(size_t), 1, f);
        person.full_name.resize(length);
        fread(person.full_name.data(), sizeof(char), length, f);

        fread(&length, sizeof(size_t), 1, f);
        person.home_address.resize(length);
        fread(person.home_address.data(), sizeof(char), length, f);

        fread(&length, sizeof(size_t), 1, f);
        person.phone_number.resize(length);
        fread(person.phone_number.data(), sizeof(char), length, f);

        fread(&person.age, sizeof(int), 1, f);
    }

    fclose(f);
}

void format(std::vector<Person> &persons) {
    int index;
    std::cout << "Enter index to delete: ";
    std::cin >> index;

    size_t size = persons.size();

    for (size_t i = index + 1; i < size; i++) {
        persons[i - 1] = persons[i];
    }
    --size;

    persons.resize(size); 

    std::cout << "Enter index to insert: ";
    std::cin >> index;
    int cnt;
    std::cout << "Enter number of persons to insert: ";
    std::cin >> cnt;

    persons.resize(size + cnt);
    for (size_t i = index + cnt + 1; i < size + cnt; i++) {
        persons[i] = persons[i - cnt];
    }

    getchar();

    for (size_t i = index + 1; i < index + cnt + 1; i++) {
        Person person;

        std::cout << "Enter full name: ";
        std::getline(std::cin, person.full_name);
        std::cout << "Enter home address: ";
        std::getline(std::cin, person.home_address);
        std::cout << "Enter phone number: ";
        std::getline(std::cin, person.phone_number);
        std::cout << "Enter age: ";
        std::cin >> person.age;

        persons[i] = person;
    }
}

void print(std::vector<Person> &persons) {
    for (size_t i = 0; i < persons.size(); i++) {
        std::cout << persons[i].full_name << std::endl;
        std::cout << persons[i].home_address << std::endl;
        std::cout << persons[i].phone_number << std::endl;
        std::cout << persons[i].age << std::endl << std::endl;
    }
}