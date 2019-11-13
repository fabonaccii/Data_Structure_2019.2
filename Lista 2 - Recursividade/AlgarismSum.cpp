#include <iostream>
using namespace std;

int algarism_sum (int n) {
    if (n == 0) return 0;
    return n%10 + algarism_sum (n/10);
}

int main (void) {
    int n;
    cin >> n;
    cout << algarism_sum (n) << endl;
}