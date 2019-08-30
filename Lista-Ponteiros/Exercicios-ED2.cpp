/*Escreva uma função mm que receba um vetor inteiro A com n elementos e os endereços
de duas variáveis inteiras, digamos min e max, e deposite nestas variáveis o valor de
um elemento mínimo e o valor de um elemento máximo do vetor. A função mm deve
seguir o seguinte protótipo: void mm(int A[], int n, int *min, int *max);
Assim como na questão anterior, nesta questão, escreva uma função main que use a
função mm.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

void mm (int A[], int n, int *min, int *max) {
    //"Seta" valores máximo e mínimo:
    *min = A[0];
    *max = A[n-1];
    //Altera ou não os valores de máximo e mínimo "setados" anteriormente:
    for (int i = 0; i < n; i++) {
        if (A[i] < *min) *min = A[i];
        if (A[i] > *max) *max = A[i];
    }
}

int main () {
    int n;
    cout << "Insira o número de elementos do vetor: ";
    cin >> n;
    //Cria vetor alocado dinamicamente:
    int *A = new int [n];
    cout << "Insira os elementos do vetor" << endl;
    //Insere os elementos digitados no vetor:
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int min, max;
    //Executa a função:
    mm (A, n, &min, &max);
    //Desaloca o vetor:
    delete[] A;
    //"Zera" o vetor para evitar vazamento de memória: 
    A = NULL;
    //Imprime os valores de máximo e mínimo:
    cout << "Mínimo: " << min << endl;
    cout << "Máximo: " << max << endl;
    return 0;
}