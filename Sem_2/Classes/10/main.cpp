#include "time.h"
#include "file_work.h"

int main() {
    Time t, t1, t2;
    int k, c;

    char filename[30];

    do {
        std::cout << "\n1. Make file";
        std::cout << "\n2. Print file";
        std::cout << "\n3. Delete record from file";
        std::cout << "\n4. Add record to file";
        std::cout << "\n5. Change record in file";
        std::cout << "\n0. Exit\n";
        std::cin >> c;

        switch(c) {
            case 1:
                std::cout << "File name: ";
                std::cin >> filename;
                k = make_file(filename);
                if (k < 0) {
                    std::cout << "Can't make file";
                }
                break;
            case 2:
                std::cout << "File name: ";
                std::cin >> filename;
                if (k == 0) {
                    std::cout << "File is empty\n";
                }

                if (k < 0) {
                    std::cout << "Can't read file\n";
                }
                break;
            case 3:
                std::cout << "File name: ";
                std::cin >> filename;
                int nom;
                std::cout << "nom?";
                std::cin >> nom;
                k = del_file(filename, nom);
                if (k < 0) {
                    std::cout << "Can't delete record\n";
                }
                break;
            case 4:
                std::cout << "File name: ";
                std::cin >> filename;
                std::cout << "nom?";
                std::cin >> nom;
                std::cout << "New person: ";
                std::cin >> t1;
                k = add_file(filename, nom, t1);
                if (k < 0) {
                    std::cout << "Can't add record\n";
                }
                if (k == 0) {
                    k = add_end(filename, t1);
                }
                break;
            case 5:
                std::cout << "File name: ";
                std::cin >> filename;
                std::cout << "nom?";
                std::cin >> nom;
                std::cout << "New person: ";
                std::cin >> t2;
                k = change_file(filename, nom, t2);
                if (k < 0) {
                    std::cout << "\nCan't change record";
                }
                if (k == 0) {
                    std::cout << "\nNot such record";
                }
                break;
        }
    } while (c != 0);

    return 0;
}