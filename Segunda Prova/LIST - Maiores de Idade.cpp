#include <iostream>
#include <list>

using namespace std;

int nMaiores(list<int> lista) {
    int n = 0;
    list<int>::iterator p; // iterador para varrer a lista
    for (p = lista.begin(); p != lista.end(); p++) { // percorre a lista
        if (*p >= 18) { // se o elemento for maior ou igual a 18
            n++; // incrementa o número de elementos maiores de idade
        }
    }
    return n;
}


int main()
{
    list<int> lista;       // ponteiro para a lista
    int idade;            // var aux para leitura dos dados a serem inseridos na lista e a procura


    // Inserindo elementos na lista
    cin >> idade;
    while (idade != 0)
    {
        lista.push_front(idade);
        cin >> idade;
    }

    // Mostrar resultado
    cout << nMaiores(lista) << " pessoas com 18 anos ou mais" << endl;

 
    // Liberando a memória utilizada pela lista
    while (!lista.empty())
        lista.pop_front();
    return 0;
}