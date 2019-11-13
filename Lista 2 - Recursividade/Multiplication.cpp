#include <iostream>
using namespace std;

int multiplication (int a, int b) {
    if (b == 1)
        return a;
    return a + multiplication (a, b-1);
}

int main (void) {
    int a, b;
    cin >> a >> b;
    cout << multiplication (a, b) << endl;
}