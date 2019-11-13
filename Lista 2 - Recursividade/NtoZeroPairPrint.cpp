#include <iostream>
using namespace std;

void n_to_zero_pair_print (int n) {
    if (n < 0) 
        return;
    if (n%2 == 0)
        cout << n << " ";
    n_to_zero_pair_print(n-1);
}

int main (void) {
    int n;
    cin >> n;
    n_to_zero_pair_print(n);
    cout << endl;
}