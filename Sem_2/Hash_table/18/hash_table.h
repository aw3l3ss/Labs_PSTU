#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include "person.h"

typedef struct Hash_table Hash_table;
Hash_table *init_hash_table(int size);
void add_element_to_hash_table(Hash_table *hash_table, std::string key, std::string value, int hash_table_size);
bool delete_element_from_hash_table(Hash_table *hash_table, int hash_table_size, std::string key);
Person *find_element_in_hash_table(Hash_table *hash_table, int hash_table_size, std::string key);
void output_hash_table(Hash_table *hash_table, int hash_table_size);
int count_collisions(Hash_table *hash_table, int hash_table_size);
void write_to_file(Hash_table *hash_table, int hash_table_size, std::string file_name);
Hash_table *read_from_file(int *hash_table, std::string file_name);
void delete_hash_table(Hash_table *hash_table, int *hash_table_size);

#endif