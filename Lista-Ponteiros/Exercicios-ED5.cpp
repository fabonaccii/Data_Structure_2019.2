/*Implemente a seguinte função usando ponteiros:

char *strcpy(char *destino, char *origem)

Essa função copia a string origem em destino. Ela também supõe que o tamanho de
destino é maior ou igual ao de origem. O valor retornado é destino. Escreva uma
função main que use a função strcpy.*/

//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

char *strcpy (char *destino, char *origem) {
    for (int i = 0; origem[i] != 0; i++) {
        destino[i] = origem[i];
    }
    return destino;
}

int main () {
    char *origem = new char[100];
    cout << "Digite a palavra de origem: ";
    cin.getline (origem, 99);
    char *destino = new char [100]; 
    destino = strcpy (destino, origem);
    cout << "Palavra destino copiada: " << destino << endl;
    //Desaloca os vetores (strings):
    delete[] origem;
    delete[] destino;
    destino = NULL;
    origem = NULL;
    return 0;
}
