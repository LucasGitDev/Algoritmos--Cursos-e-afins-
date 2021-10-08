#include <iostream>

using namespace std;

int main() {

    int a;

    int *b;

    a = 2;

    b = &a; // & -> referencia de algo

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "b = " << b << endl;
    cout << "*b = " << *b << endl;


    return 0;
}