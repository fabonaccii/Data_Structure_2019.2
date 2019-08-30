//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

void positive_sum (int n, int *array, int *sum) {
    //Caso base:
    if (n < 1) 
        return;
    else {
        //Se positivo:
        if (array[n-1] > 0)
            //Soma à variável "sum" a última posição do vetor:
            *sum += array[n-1];
        //Chama a função recursivamente diminuindo o tamanho do vetor:
        positive_sum (n-1, array, sum);
    }
}

int main (void) {
    int n;
    cout << "Insira o número de elementos do vetor: ";
    cin >> n;

    int sum = 0;

    //Cria vetor alocado dinamicamente:
    int *array = new int [n];

    cout << "Insira os elementos do vetor:" << endl;

    //Insere os elementos digitados no vetor:
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    //Chama a função:
    positive_sum(n, array, &sum);

    //Prints:
    for (int i = 0; i < n; i++) cout << "[" << i << "]: " << array[i] << " ";
    cout << endl;
    cout << "Soma dos positivos: " << sum << endl;
    
    //Desaloca e anula o vetor:
    delete[] array;
    array = NULL;
}