#include <iostream>

using namespace std;

int main()
{
    char *respostas = NULL; // declarar respostas como um ponteiro nulo
    char *gabarito = NULL; // declarar gabarito como um ponteiro nulo
    char *p; // declarar p como um ponteiro
    int acertos = 0; // declarar acertos como zero
    int N; // declarar N como um inteiro
    int i; // declarar i como um inteiro

    N = 10; // atribuir 10 a N
    respostas = new char[N]; // alocar memória para respostas
    gabarito = new char[N]; // alocar memória para gabarito

    // ler respostar usando ponteiro
    for (p = respostas; p < respostas + N; p++) {
        cin >> *p;
    }

    // ler gabarito usando ponteiro
    for (p = gabarito; p < gabarito + N; p++) {
        cin >> *p;
    }

    // verificar acertos
    i = 0;
    for (p = respostas; p < respostas + N; p++) {
        if (*p == gabarito[i]) {
            acertos++;
        }
        i++;
    }

    // exibir acertos
    cout << acertos << " acertos" << endl;

    return 0;
}