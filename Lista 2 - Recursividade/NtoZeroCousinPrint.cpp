#include <iostream>
using namespace std;

void n_to_zero_cousin_print (int n) {
    if (n < 0) 
        return;
    int divisible_times = 0;
    for (int i = n; i > 0; i--)
        if (n%i == 0)
            divisible_times++;
    if (divisible_times == 2) 
        cout << n << " ";
    n_to_zero_cousin_print(n-1);
}

int main (void) {
    int n;
    cin >> n;
    n_to_zero_cousin_print(n);
    cout << endl;
}