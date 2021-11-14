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

    //varrer v com ponteiro para inteiro e encontrar maior valor
    int maior = *v; //inicializar maior com o primeiro valor
    for (p = v; p < v + N; p++) { //varrer v
        if (*p > maior) { //se o valor atual for maior que o maior
            maior = *p; //atribuir o valor atual ao maior
        }
    }

    cout << maior << endl;
    return 0;
}