#include "list.h"

void init_with_rand_numbers(List *list, int n);

int main() {
    srand(time(nullptr));
    
    List *list = init_list();
    int n = rand() % 9 + 2;
    init_with_rand_numbers(list, n);
    print_list(list);
    
    int n1 = rand() % n;
    std::cout << "Delete " << n1 << " element" << std::endl;
    delete_by_index(list, n1);
    print_list(list);

    n1 = rand() % (n - 1);
    int k = rand() % 4 + 2;
    std::cout << "Add " << k << " elements after " << n1 << " element" << std::endl;

    for (int i = 0; i < k; ++i) {
        add_by_index(list, n1, rand() % 100);
        ++n1;
    }
    print_list(list);

    std::cout << "Input file name: ";
    std::string filename;
    std::getline(std::cin, filename);
    write_list_to_file(list, filename);

    delete_list(list);
    list = init_list();
    print_list(list);

    read_list_from_file(list, filename);
    print_list(list);

    delete_list(list);
    
    return 0;
}

void init_with_rand_numbers(List *list, int n) {
    for (int i = 0; i < n; ++i) {
        push_back(list, rand() % 100);
    }
}