#include <iostream>

using namespace std;

int main()
{

    // int a;

    // int *b;

    // a = 2;

    // b = &a; // & -> referencia de algo

    // *b = 3;

    // cout << "a = " << a << endl;

    // a = 4;
    // cout << "*b = " << *b << endl;

    int x, y;
    int *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    cout << x << "\n" << y << "\n" << p;

    return 0;
}