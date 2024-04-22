#include "list.h"

#include <fstream>

typedef struct Node {
    int data;
    Node* next;
} Node;

struct List {
    Node* head;
    Node* tail;
};

List *init_list() {
    List *list = (List *) calloc(1, sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

bool is_empty(List *list) {
    return list->head == NULL;
}

void push_back(List *list, int elem) {
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->data = elem;
    node->next = NULL;

    if (is_empty(list)) {
        list->head = node;
        list->tail = node;

        return;
    }
  
    list->tail->next = node;
    list->tail = node;
}

bool pop_back(List *list) {
    if (is_empty(list)) {
        return false;
    }

    Node *ptr = list->head, *prev_ptr = NULL;

    while (ptr->next) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == list->head) {
        list->head = NULL;
        list->tail = NULL;
    }

    else {
        list->tail = prev_ptr;
        prev_ptr->next = NULL;
        free(ptr);
    }

    return true;
}

void print_list(List *list) {
    if (is_empty(list)) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    Node *ptr = list->head;

    while (ptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void delete_list(List *list) {
    Node *ptr = list->head, *prev_ptr = NULL;

    while (ptr) {
        prev_ptr = ptr;
        ptr = ptr->next;
        free(prev_ptr);
    }

    free(list);
}

void delete_by_index(List *list, int n) {
    int i = 0;
    Node *ptr = list->head, *prev_ptr = NULL;
  
    while (i < n) {
        prev_ptr = ptr;
        ptr = ptr->next;
        ++i;
    }

    if (ptr == list->tail) {
        list->tail = prev_ptr;
    }

    if (ptr == list->head) {
        list->head = ptr->next;
    }

    else {
        prev_ptr->next = ptr->next;
    }

    free(ptr);
}

void add_by_index(List *list, int n, int k) {
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->data = k;
    
    if (is_empty(list)) {
        list->head = node;
        list->tail = node;
        node->next = NULL;
        
        return;
    }

    int i = 0;
    Node *ptr = list->head;

    while (i < n) {
        ptr = ptr->next;
        ++i;
    }
    
    node->next = ptr->next;
    ptr->next = node;

    if (ptr == list->tail) {
        list->tail = node;
    }
}

void write_list_to_file(List *list, std::string filename) {
    std::ofstream file(filename);

    Node *ptr = list->head;

    while (ptr) {
        file << ptr->data << " ";
        ptr = ptr->next;
    }

    file.close();
}

bool read_list_from_file(List *list, std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    int elem;
    while (file >> elem) {
        push_back(list, elem);
    }

    file.close();
    return true;
}