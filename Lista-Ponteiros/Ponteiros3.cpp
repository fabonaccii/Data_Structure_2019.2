/*Escreva um programa que leia um inteiro n seguido de n números inteiros e imprima
esses n números em ordem invertida (primeiro o último, depois o penúltimo, etc.) O
seu programa não deve impor quaisquer restrições ao valor de n.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Insira o número de elementos do vetor: ";
    cin >> n;
    int array[n];
    cout << "Insira os elementos do vetor: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    //Inverte o vetor partindo-o ao meio e trocando das extremidades ao centro:
    for (int i = 0; i < n/2; i++) {
        int aux = array[i];
        array[i] = array[n-1-i];
        array[n-1-i] = aux;
    }
    
    cout << endl << "Vetor invertido: " << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
