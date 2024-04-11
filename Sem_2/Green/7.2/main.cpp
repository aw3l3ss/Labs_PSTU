#include <iostream>
#include <cstdarg>

using namespace std;

int Sum(int k, ...);

int main()
{
    srand(time(nullptr));

    int arr[12];

    for (int i = 0; i < 12; i++) {
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";

        if (i % 2 == 0) {
            cout << "* ";
        }

        else {
            if (i != 7) {
                cout << "+ ";
            }
        }
    }
    cout << "= " << Sum(8, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]) << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";

        if (i % 2 == 0) {
            cout << "* ";
        }

        else {
            if (i != 9) {
                cout << "+ ";
            }
        }
    }
    cout << "= " << Sum(10, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]) << endl;

    for (int i = 0; i < 12; i++) {
        cout << arr[i] << " ";

        if (i % 2 == 0) {
            cout << "* ";
        }

        else {
            if (i != 11) {
                cout << "+ ";
            }
        }
    }
    cout << "= " << Sum(12, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10], arr[11]) << endl;

    return 0;
}

int Sum (int k, ...) {
    va_list argList;
    va_start(argList, k);
    int s = 0;

    for (int i = 0; i < k; i += 2) {
        s += va_arg(argList, int) * va_arg(argList, int);
    }

    va_end(argList);
    
    return s;
}