#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> fila; // ponteiro para a fila

    // Inserindo elementos na fila

    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(5);
    // Removendo e mostrando os elementos da fila
    while (!fila.empty())
    {
        cout << *fila.begin() << endl; // fila.begin() aponta para o primeiro nó da lista
        fila.pop_front();              // remove o primeiro nó da lista
    }
    return 0;
}