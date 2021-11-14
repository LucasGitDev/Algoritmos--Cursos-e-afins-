#include <iostream>

using namespace std;

int main() {
    int N;
    int *v = NULL;
    int *p;
    
    cin >> N;
    v = new int[N];

    //varrer v com ponteiro para inteiro e atribuir valores
    for (p = v; p < v + N; p++) {
        cin >> *p;
    }

    //varrer v com ponteiro para inteiro e imprimir valores
    for (p = v; p < v + N; p++) {
        cout << *p << " ";
    }


    return 0;
}