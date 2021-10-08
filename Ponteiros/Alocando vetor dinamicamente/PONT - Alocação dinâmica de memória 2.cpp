#include <iostream>
#include <iomanip>

using namespace std;

//Struct de notas e media
struct notas
{
    double nota1;
    double nota2;
    double nota3;
    double nota4;
    double media;
};


int main() {

    notas *alunos;//ponteiro para a struct de notas
    int tam; //tamanho do vetor
    int i;//Contador
    double media; // Media das medias

    cin >> tam;
    //Alocação de memoria
    alunos = new notas[tam];

    //Leitura de notas
    for(i=0; i < tam; i++) {
        cin >> alunos[i].nota1;
        cin >> alunos[i].nota2;
        cin >> alunos[i].nota3;
        cin >> alunos[i].nota4;

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3 + alunos[i].nota4) / 4;
    }

  
    //Calcular média das medias
    for(i = 0; i < tam; i++) { 
        media += alunos[i].media;
    }

    media = media / tam;

    //Mostrar média

    cout << fixed << setprecision(2) << media << endl;

    return 0;
}