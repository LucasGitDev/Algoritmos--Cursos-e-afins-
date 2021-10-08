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
    int tam; // tamanho escolhido para o vetor
    int i; // contador
    // Escolher o tamanho do vetor
    cin >> tam;
    // Alocar memoria para a struct
    produto = new dado[tam];   
    // Inserir valores
    for(i=0;i<tam;i++)
    {
        cin >> produto[i].codigo;
        cin >> produto[i].preco;
    }    
    // Mostrar valores inseridos
    for(i=0;i<tam;i++)
    {
        cout << "Codigo: " << produto[i].codigo << " ";
        cout << "Preco: " << produto[i].preco << endl;
    }    
    // Liberar memoria
    delete [] produto;
    return 0;
}