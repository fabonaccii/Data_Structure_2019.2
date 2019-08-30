/*Faça uma função MAX que recebe como entrada um inteiro n, uma matriz inteira
Anxn e devolve três inteiros: k, l e c, tal que:

• k  ́e o maior elemento de A e é igual a A[l][c].

Se o elemento máximo ocorrer mais de uma vez, indique em l e c qualquer uma das
possíveis posições. Use ponteiros para os argumentos.
Escreva uma função main que use a função MAX.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

void MAX (int n, int **A, int *k, int*l, int *c) {
    *k = A[0][0];
    *l = 1;
    *c = 1;
     for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (A[i][j] > *k) {
                *k = A[i][j];
                *l = i+1;
                *c = j+1;
            }
        }
    }
}

int main () {
    int n;
    cout << "Insira o número de linhas e colunas da matriz Anxn: ";
    cin >> n;
    //Aloca a matriz:
    int **A = new int *[n];
    for (int i = 0; i < n; i++){
        A[i] = new int [n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    int k, l, c;
    MAX (n, A, &k, &l, &c);
    //Desaloca a matriz:
    for (int i = 0; i < n; i++){
        delete[] A[i];
    }
    delete[] A;
    A = NULL;
    cout << endl << "Valor máximo: " << k << endl;
    cout << "Linha: " << l << endl << "Coluna: " << c << endl;
    return 0;
}