#include <iostream>
using namespace std;

int fibonacci (int n) {
    if (n == 1) 
        return 0;
    if (n  <= 3)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main (void) {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}