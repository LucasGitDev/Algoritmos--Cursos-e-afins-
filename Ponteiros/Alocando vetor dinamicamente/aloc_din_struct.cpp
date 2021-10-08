#include<iostream>
using namespace std;
struct dado
{
    int codigo;
    float preco;
};
int main()
{
    dado *produto; // ponteiro para a struct
    // Alocar memoria para a struct
    produto = new dado;
    // Inserir valores
    produto->codigo = 1;
    produto->preco = 1.50;
    // Mostrar valores inseridos
    cout << "Codigo: " << produto->codigo << endl;
    cout << "Preco: " << produto->preco << endl;
    // Liberar memoria
    delete produto;
    return 0;
} 