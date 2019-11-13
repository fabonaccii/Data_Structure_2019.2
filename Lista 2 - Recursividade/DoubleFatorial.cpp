#include <iostream>
using namespace std;

int double_fatorial (int n) {
    if (n < 1) 
        return 1;
    if ((n-2)%2 == 0) 
        n--;
    return n * double_fatorial(n-2);
}

int main (void) {
    int n;
    cin >> n;
    cout << double_fatorial(n) << endl;
}