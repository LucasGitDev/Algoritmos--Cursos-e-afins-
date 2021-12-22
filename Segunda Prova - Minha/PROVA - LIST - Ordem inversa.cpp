#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> pilha; // ponteiro para a pilha
    int valor; // valor a ser inserido na pilha

    // Inserindo elementos na pilha
    cin >> valor;
    while (valor != 0)
    {
        pilha.push_back(valor);
        cin >> valor;
    }

    // Imprimindo elementos da pilha
    while (!pilha.empty())
    {
        cout << pilha.back() << " ";
        pilha.pop_back();
    }

    cout << endl;
    
    // Limpando a memória
    pilha.clear();

    return 0;
}