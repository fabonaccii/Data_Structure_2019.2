/*Implemente a seguinte função usando ponteiros:

int strcmp(char *str1, char *str2)

Essa função retorna 0 se str1 == str2, retorna −1 se str1 < str2 e retorna 1 de
str1 > str2.
Escreva uma função main que use a função strcmp.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

int strcmp (char *str1, char *str2) {
    int resultado = 0;
    for (int i = 0; str1[i] != 0 || str2[i] != 0 ; i++) {
        if (str1[i] < str2[i]) {
            resultado = 1;
            break;
        } 
        if (str1[i] > str2[i]) {
            resultado = -1;
            break;
        }
    }
    return resultado;
}

int main () {
    char *str1 = new char[100];
    cout << "Digite a primeira palavra: ";
    cin.getline (str1, 99);

    char *str2 = new char [100]; 
    cout << "Digite a segunda palavra: ";
    cin.getline (str2, 99);

    int resultado = strcmp (str1, str2);
    cout << "Resultado: " << resultado << endl;

    delete[] str1;
    delete[] str2;
    str1 = NULL;
    str2 = NULL;
    return 0;
}
