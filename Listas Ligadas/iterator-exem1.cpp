#include <iostream>
#include <list>

using namespace std;
int main()
{
    list<int> lista; // ponteiro para a lista    
    list<int>::iterator p; // iterador para varrer a lista    
    int x; // var aux para leitura dos dados a serem inseridos na lista    
    int soma; // soma dos elementos da lista    
    
    // Inserindo elementos na lista: 2 1 5 0    cin >> x;
    while(x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }
    // Mostrando os elementos da lista    
    //for(p=lista.begin();p!=lista.end();p++)     
    // cout << *p << endl;    
    
    // Calculando e mostrando a soma dos elementos da lista    
    soma = 0;
    for ( p = lista.begin(); p != lista.end(); p++ )
        soma += *p;
    cout << "soma = " << soma << endl;

    // Liberando a memória utilizada pela lista    
    while(!lista.empty())
        lista.pop_front();
    return 0;
}