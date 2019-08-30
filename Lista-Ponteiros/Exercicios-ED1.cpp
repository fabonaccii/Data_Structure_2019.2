/*Questão 1: Escreva um programa em C++ que possua uma função troca que recebe como entrada
duas variáveis inteiras e troca os seus valores. Os dois argumentos da função troca
devem ser passados por referência (ou seja, usando ponteiros). A função troca deve
obedecer o seguinte protótipo: void troca (int *a, int *b);
Escreva uma função main que use a função troca. O seu programa deve receber como
entrada os valores de a e b e deve retornar como saída os novos valores de a e b.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

void troca (int *a, int *b) {
    int c = *a; //Utiliza variável "c" (auxiliar);
    *a = *b;
    *b = c;
}

int main () {
    int a, b;
    //Recebe os valores:
    cin >> a;
    cin >> b;
    //Executa a função:
    troca (&a, &b);
    //Imprime os valores de a e b trocados:
    cout << endl << a << endl;
    cout << b << endl;
    return 0;
}