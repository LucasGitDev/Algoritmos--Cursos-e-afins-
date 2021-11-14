#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> venda;
    list<int> estoque;
    int N; // operações
    int i; // contador
    int produto;

    cin >> N;

    i = 0;
    for (i = 0; i < N; i++)
    {
        int op;
        cin >> op; // 1 para inserir na lista de venda, 2 para inserir na lista de estoque
        if (op == 1)
        {
            cin >> produto;             // produto a ser inserido na lista de venda
            estoque.push_front(produto); // inserindo na lista de estoque
        }
        else if (op == 2)
        {
            if (!estoque.empty()) // se a lista de estoque não estiver vazia
            {
                produto = estoque.back(); // pega o primeiro elemento da lista de estoque
                estoque.pop_back();       // remove o primeiro elemento da lista de estoque
                venda.push_front(produto);  // inserindo na lista de venda
            }
        }
    }

    cout << "Estoque: ";

    for (list<int>::iterator it = estoque.begin(); it != estoque.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    cout << "Venda: ";

    for (list<int>::iterator it = venda.begin(); it != venda.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    while(!venda.empty())
    {
        venda.pop_front();
    }

    while(!estoque.empty())
        estoque.pop_front();

    return 0;
}