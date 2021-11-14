#include <iostream>
#include <iomanip>

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

    //varrer v com ponteiro para inteiro e calcular media dos valores
    double media = 0;
    for (p = v; p < v + N; p++) {
        media += *p;
    }
    media /= N;

    cout << fixed << setprecision(2) << media << endl;

    delete[] v;
    return 0;
}