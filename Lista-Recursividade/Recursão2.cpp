//Nome: Fábio Luz Duarte Filho
//Matrícula: 474027
//Curso: Ciência da Computação

#include <iostream>
using namespace std;

int digit_sum (int num, int *sum) {
    //Se não decimal:
    if (num >= 1) {
    //Separa o último algarismo do número:
    *sum += num%10;
    //Chama a função retirando o último algarismo do número:
    digit_sum(num/10, sum);
    }
    return *sum;
}

int main (void) {
    int num;
    cout << "Insira o número: ";
    cin >> num;

    int sum = 0;

    //Print:
    cout << digit_sum(num, &sum) << endl;
}