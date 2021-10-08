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

    notas *aluno;//ponteiro para a struct de notas
    //Alocação de memoria
    aluno = new notas;

    //Leitura de notas
    cin >> aluno->nota1;
    cin >> aluno->nota2;
    cin >> aluno->nota3;
    cin >> aluno->nota4;

    //Calculo da média e armazenamento

    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3 + aluno->nota4) / 4;

    //Mostrar média

    cout << fixed << setprecision(2) << aluno->media << endl;

    return 0;
}