#include <iostream>
using namespace std;

void n_to_zero_print (int n) {
    if (n < 0) 
        return;
    cout << n << " ";
    n_to_zero_print(n-1);
}

int main (void) {
    int n;
    cin >> n;
    n_to_zero_print(n);
    cout << endl;
}