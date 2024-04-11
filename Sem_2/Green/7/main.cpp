#include <iostream>

using namespace std;

typedef struct Complex{
    int a;
    int b;
} Complex;

void format_print_complex(Complex a);
Complex subtract(Complex a, Complex b);
int subtract(int a, int b);

int main()
{
    int a, b;
    Complex c1, c2;
    cout << "Input two complex numbers (a1 b1 a2 b2, where a1 + b1*i and a2 + b2*i):" << endl;
    cin >> c1.a >> c1.b >> c2.a >> c2.b;
    cout << "The result is: ";
    format_print_complex(subtract(c1, c2));
    cout << endl;
    cout << "Input two integers:" << endl;
    cin >> a >> b;
    cout << "The result is: " << subtract(a, b) << endl;
    return 0;
}

void format_print_complex(Complex a){
    if (a.a == 0) {
        cout << a.b << "i";
    }

    else if (a.b == 0) {
        cout << a.a;
    }

    else {
        cout << a.a << " + " << a.b << "i" << endl;
    }
}

Complex subtract(Complex a, Complex b) {
    Complex c;
    c.a = a.a - b.a;
    c.b = a.b - b.b;
    
    return c;
}

int subtract(int a, int b) {
    return a - b;
}