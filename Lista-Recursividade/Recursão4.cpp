/*
    Author: Fábio Luz Duarte Filho
*/

#include <iostream>
using namespace std;

int binomial_coeficient (int n, int k) {
    if (n == k || k == 0 || n < 2) //Casos que retornam 1;
        return 1;
    else if (n == k+1 || k == 1) //Casos que retornam o próprio n;
        return n;
    else
        return binomial_coeficient(n-1, k-1)+binomial_coeficient(n-1, k); //Relação de Stifer;
}

int main (void) {
    int n;
    cout << "Insira o n: ";
    cin >> n;

    int k;
    cout << "Insira o k: ";
    cin >> k;

    //Print:
    cout << "Coeficiente Binomial: " << binomial_coeficient(n,k) << endl;
}
