#include <iostream>
using namespace std;

void binary (int n) {
    if (n <= 1) {
        cout << n << " ";
        return;
    }
    binary (n/2);
    cout << n%2 << " ";
}

int main (void) {
    int n;
    cin >> n;
    binary(n);
    cout << endl;
}