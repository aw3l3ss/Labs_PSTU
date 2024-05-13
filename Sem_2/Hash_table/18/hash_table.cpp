#include "hash_table.h"
#include "hash.h"
#include <iostream>
#include <fstream>

struct Node {
    std::string key;
    std::string value;
    Node *next;
};

struct Hash_table {
    Node **table;
};

Hash_table *init_hash_table(int size) {
    Hash_table *hash_table = new Hash_table;
    hash_table->table = new Node*[size];
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

void add_element_to_hash_table(Hash_table *hash_table, std::string key, std::string value, int hash_table_size) {
    Node *node = new Node;
    node->key = key;
    node->value = value;
    node->next = NULL;

    int hash = get_hash(key, hash_table_size);

    if (hash_table->table[hash] == NULL) {
        hash_table->table[hash] = node;
    } 
    
    else {
        Node *current = hash_table->table[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

Person *find_element_in_hash_table(Hash_table *hash_table, int hash_table_size, std::string key) {
    int hash = get_hash(key, hash_table_size);

    if (hash_table->table[hash] == NULL) {
        return NULL;
    }

    Node *current = hash_table->table[hash];

    while (current->key != key && current != NULL) {
        current = current->next;
    }

    if (current->key == key) {
        Person *person = init_person();
        set_info(person, current->value);
        return person;
    }

    return NULL;
}

bool delete_element_from_hash_table(Hash_table *hash_table, int hash_table_size, std::string key) {
    int hash = get_hash(key, hash_table_size);

    if (hash_table->table[hash] == NULL) {
        return false;
    }

    Node *current = hash_table->table[hash], *prev;
    while (current->key != key && current != NULL) {
        prev = current;
        current = current->next;
    }

    if (current->key == key) {
        if (current == hash_table->table[hash]) {
            hash_table->table[hash] = current->next;
        }
        else {
            prev->next = current->next;
        }
        delete current;
        return true;
    }
    
    return false;
}

void output_hash_table(Hash_table *hash_table, int hash_table_size) {
    for (int i = 0; i < hash_table_size; i++) {
        Node *current = hash_table->table[i];
        int j = 0;

        while (current != NULL) {
            Person *person = init_person();
            set_info(person, current->value);

            std::cout << i << " " << j << " || Key: " << current->key << " || Name: "
                      << get_name(person) << " | Passport: " << get_passport(person) << " | Address: " << get_address(person) << std::endl;

            delete_person(person);

            current = current->next;
            ++j;
        }
    }
}

int count_collisions(Hash_table *hash_table, int hash_table_size) {
    int collisions = 0;

    for (int i = 0; i < hash_table_size; i++) {
        Node *current = hash_table->table[i];

        if (current != NULL) {
            current = current->next;

            while (current != NULL) {
                current = current->next;
                ++collisions;
            }
        }
    }

    return collisions;
}

void write_to_file(Hash_table *hash_table, int hash_table_size, std::string file_name) {
    std::ofstream file;
    file.open(file_name);

    file << hash_table_size << std::endl;
    for (int i = 0; i < hash_table_size; i++) {
        Node *current = hash_table->table[i];
        
        while (current != NULL) {
            file << current->key << "|" << current->value << std::endl;
            current = current->next;
        }
    }

    file.close();
}

Hash_table *read_from_file(int *hash_table_size, std::string file_name) {
    std::ifstream file;
    file.open(file_name);

    file >> *hash_table_size;

    Hash_table *hash_table = init_hash_table(*hash_table_size);
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::string key;
        std::string value;

        int i = 0;
        while (line[i] != '|') {
            key += line[i];
            ++i;
        }
        ++i;
        for (; i < line.length(); ++i) {
            value += line[i];
        }

        add_element_to_hash_table(hash_table, key, value, *hash_table_size);
    }

    file.close();
    return hash_table;
}

void delete_hash_table(Hash_table *hash_table, int *hash_table_size) {
    if (hash_table) {
        for (int i = 0; i < *hash_table_size; i++) {
            Node *current = hash_table->table[i];
            Node *next;

            while (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] hash_table->table;
        delete hash_table;
        *hash_table_size = 0;
    }
}