#include <iostream>
using namespace std;

void n_k_combination (int initial_posit, int final_posit, int k, int p, int *MAX) {
    //Caso base:
    if (k == 0) {
        int auxiliar = p;
        int array[*MAX]; //Vetor para guardar os números a serem printados;
        for (int i = 0; i < *MAX; i++) {
            if (auxiliar == 0)
                break;
            array[*MAX-1-i] = auxiliar%10; //Vetor recebe o resto útil do auxiliar;
            auxiliar = auxiliar/10;
        }

        //Print da forma atual do vetor:
        for (int i = 0; i < *MAX; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    else
        if (initial_posit <= final_posit)
            for (int i = initial_posit; i < final_posit+1; i++)
                n_k_combination(i+1, final_posit, k-1, p*10+i, MAX); //Chama a função recursivamente;
}

int main (void) {
    int n;
    cout << "Insira o n: ";
    cin >> n;

    int k;
    cout << "Insira o k: ";
    cin >> k;

    int MAX = k; //MAX mantém uma constante para k;
    
    n_k_combination(1, n, k, 0, &MAX);
}