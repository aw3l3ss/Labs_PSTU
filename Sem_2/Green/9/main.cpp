#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void copy(std::string f1, std::string f2);
void output(std::string f);
int cnt_symblos(std::string f);

int main() {
    std::string f1, f2;

    std::cout << "Enter first file name: ";
    std::getline(std::cin, f1);
    std::cout << "Enter second file name: ";
    std::getline(std::cin, f2);

    copy(f1, f2);

    std::cout << f1 << ":" << std::endl;
    output(f1);
    std::cout << std::endl;
    std::cout << f2 << ":" << std::endl;
    output(f2);
    std::cout << std::endl;
    std::cout << "Symbols in last word: " << cnt_symblos(f2) << std::endl;

    return 0;
}

void copy(std::string f1, std::string f2) {
    std::ifstream fin(f1);
    std::ofstream fout(f2);

    int i = 0;
    std::string line;
    while (std::getline(fin, line)) {
        if (i > 2) {
            fout << line << std::endl;
        }

        ++i;
    }

    fin.close();
    fout.close();
}

void output(std::string f) {
    std::ifstream fin(f);

    std::string line;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }

    fin.close();
}

int cnt_symblos(std::string f) {
    std::ifstream fin(f);

    std::string word, lastWord;
    while (fin >> word) {
        lastWord = word;
    }

    fin.close();

    if (lastWord[lastWord.length() - 1] == '.') {
        return lastWord.length() - 1;
    }
    
    return lastWord.length();
}
