/*
    Author: Fábio Luz Duarte Filho
*/

#include <iostream>
using namespace std;

int min_to_max (int n, int *array, int *min, int *max) {
    //Caso base:
    if (n == 1)
        return *max-*min; //Retorno do máximo - mínimo;
    else {
        if (array[n-2] < *min) *min = array[n-2];
        if (array[n-2] > *max) *max = array[n-2];
        min_to_max (n-1, array, min, max);
    }
}

int main (void) {
    int n;
    cout << "Insira o número de elementos do vetor: ";
    cin >> n;

    //Cria vetor alocado dinamicamente:
    int *array = new int[n];

    cout << "Insira os elementos do vetor:" << endl;

    //Insere os elementos digitados no vetor:
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    //"Seta" valores de min e max como o último elemento do vetor
    int min = array[n-1], max = array[n-1];

    //Prints:
    for (int i = 0; i < n; i++) cout << "[" << i << "]: " << array[i] << " ";
    cout << endl;
    cout << "Diferença entre o máximo e o mínimo: " << min_to_max(n, array, &min, &max) << endl;
    cout << "Mínimo: " << min << endl;
    cout << "Máximo: " << max << endl;

    //Desaloca e anula o vetor:
    delete[] array;
    array = NULL;
}
