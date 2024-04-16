#include "person.h"

void write_to_bin_file(Person **arr, int size, std::string filename);
void read_from_bin_file(Person ***arr1, int *size, std::string filename);
void delete_arr(Person **arr, int size);
void delete_by_age(Person ***arr1, int *size);
void print_arr(Person **arr, int size);

int main() {
    Person **arr = (Person **) calloc(1, sizeof(Person*));
    int size = 1;

    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    char ans = 'y';

    while (ans != 'n') {
        Person *p = create_person();
        std::string name, adress, phone;
        int age;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        std::cout << "Enter adress: ";
        std::getline(std::cin, adress);
        std::cout << "Enter phone: ";
        std::getline(std::cin, phone);
        std::cout << "Enter age: ";
        std::cin >> age;

        add_data_to_person(p, name, adress, phone, age);

        arr[size - 1] = p;
        std::cout << "Do you want to add another person? (y/n): ";
        std::cin >> ans;

        if (ans == 'y') {
            arr = (Person **) realloc(arr, (++size) * sizeof(Person*));
        }

        getchar();
    }

    write_to_bin_file(arr, size, filename);
    delete_arr(arr, size);

    arr = (Person **) calloc(1, sizeof(Person*));
    read_from_bin_file(&arr, &size, filename);
    print_arr(arr, size);
    delete_by_age(&arr, &size);
    write_to_bin_file(arr, size, filename);
    delete_arr(arr, size);

    arr = (Person **) calloc(1, sizeof(Person*));
    read_from_bin_file(&arr, &size, filename);
    print_arr(arr, size);
    delete_arr(arr, size);

    return 0;
}

void write_to_bin_file(Person **arr, int size, std::string filename) {
    FILE *file = fopen(filename.c_str(), "wb");

    fwrite(&size, sizeof(int), 1, file);
    for (int i = 0; i < size; i++) {
        int len = get_name(arr[i]).length();
        fwrite(&len, sizeof(int), 1, file);
        fwrite(get_name(arr[i]).c_str(), sizeof(char), len, file);

        len = get_adress(arr[i]).length();
        fwrite(&len, sizeof(int), 1, file);
        fwrite(get_adress(arr[i]).c_str(), sizeof(char), len, file);

        len = get_phone(arr[i]).length();
        fwrite(&len, sizeof(int), 1, file);
        fwrite(get_phone(arr[i]).c_str(), sizeof(char), len, file);

        len = get_age(arr[i]);
        fwrite(&len, sizeof(int), 1, file);
    }

    fclose(file);
  }

void read_from_bin_file(Person ***arr1, int *size, std::string filename) {
    FILE *file = fopen(filename.c_str(), "rb");

    fread(size, sizeof(int), 1, file);

    Person **arr = (Person **) calloc(*size, sizeof(Person *));

    for (int i = 0; i < *size; i++) {
        int len;

        fread(&len, sizeof(int), 1, file);
        std::string name;
        name.resize(len);
        fread(&name[0], sizeof(char), len, file);

        fread(&len, sizeof(int), 1, file);
        std::string adress;
        adress.resize(len);
        fread(&adress[0], sizeof(char), len, file);

        fread(&len, sizeof(int), 1, file);
        std::string phone;
        phone.resize(len);
        fread(&phone[0], sizeof(char), len, file);

        int age;
        fread(&age, sizeof(int), 1, file);

        Person *p = create_person();
        add_data_to_person(p, name, adress, phone, age);

        arr[i] = p;
    }

    free(*arr1);

    *arr1 = arr;

    fclose(file);
}

void delete_arr(Person **arr, int size) {
    for (int i = 0; i < size; i++) {
        delete_person(arr[i]);
    }
    free(arr);
}

void delete_by_age(Person ***arr1, int *size) {
    Person **arr = (Person **) realloc(*arr1, *size * sizeof(Person *));

    int age;
    std::cout << "Input age for delete: ";
    std::cin >> age;

    int step = 0;

    for (int i = 0; i < *size - step; i++) {
        if (get_age(arr[i]) == age) {
            delete_person(arr[i]);
            ++step;
        }

        if (step > 0) {
            arr[i] = arr[i + step];
        }
    }

    *size -= step;

    arr = (Person **) realloc(arr, *size * sizeof(Person *));

    *arr1 = arr;
}

void print_arr(Person **arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Person " << i + 1 << ":" << std::endl;
        std::cout << "Name: " << get_name(arr[i]) << std::endl;
        std::cout << "Adress: " << get_adress(arr[i]) << std::endl;
        std::cout << "Phone: " << get_phone(arr[i]) << std::endl;
        std::cout << "Age: " << get_age(arr[i]) << std::endl;
        std::cout << std::endl;
    }
}
