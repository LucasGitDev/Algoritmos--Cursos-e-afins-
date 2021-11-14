#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int *v = NULL;
    int *p;
    int contadorParePositivo;
    
    cin >> N;
    v = new int[N];

    //varrer v com ponteiro para inteiro e atribuir valores
    for (p = v; p < v + N; p++) {
        cin >> *p; 
    }

    //varrer v com ponteiro para inteiro e buscar por elementos pares e positivos
    contadorParePositivo = 0; //contador de elementos pares e positivos
    for (p = v; p < v + N; p++) { // varrer v
        if (*p % 2 == 0 && *p > 0) {// se o elemento for par e positivo
            contadorParePositivo++; // incrementar contador
        }
    }

    cout << contadorParePositivo << endl;

    return 0;
}