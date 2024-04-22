#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef struct List List;

List *init_list();
bool is_empty(List *list);
void push_back(List *list, int elem);
bool pop_back(List *list);
void print_list(List *list);
void delete_list(List *list);

void delete_by_index(List *list, int n);
void add_by_index(List *list, int n, int k);

void write_list_to_file(List *list, std::string filename);
bool read_list_from_file(List *list, std::string filename);

#endif