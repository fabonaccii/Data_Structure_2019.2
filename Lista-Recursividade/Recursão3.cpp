//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

void triangler (int *array, int n) {
    int auxiliar[n];

    for (int i = 0; i < n; i++)
        auxiliar[i] = array[i];
    //Caso base:
    if (n < 1)
        return;
    //Soma posições adjacentes:
    for (int i = 0; i < n; i++)
        array[i] += array[i+1];
    //Chama a função recursivamente:
    triangler(array, n-1);
    //Print do vetor empilhado:
    for (int i = 0; i < n; i++)
        cout << auxiliar[i] << " ";   
    cout << endl;
}

int main (void) {
    int n;
    cout << "Insira o número de elementos do vetor: ";
    cin >> n;

    //Cria vetor alocado dinamicamente:
    int *array = new int [n];

    cout << "Insira os elementos do vetor:" << endl;

    //Insere os elementos digitados no vetor:
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << endl;

    triangler(array, n);

    //Desaloca e anula o vetor:
    delete[] array;
    array = NULL;
}