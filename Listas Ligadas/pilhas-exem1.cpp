#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> pilha; // ponteiro para a pilha
    // Inserindo elementos na pilha
    pilha.push_front(2);
    pilha.push_front(1);
    pilha.push_front(5);
    // Removendo e mostrando os elementos da pilha
    while(!pilha.empty())
    {
        cout << *pilha.begin() << endl; // pilha.begin() aponta para o primeiro nó da lista
        pilha.pop_front(); // remove o primeiro nó da lista
    }
    return 0;
}