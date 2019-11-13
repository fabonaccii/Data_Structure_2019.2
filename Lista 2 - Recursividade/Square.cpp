#include <iostream>
using namespace std;

int sqr (int k, int n) {
    if (n == 1)
        return k;
    return k * sqr(k, n-1);
}

int main (void) {
    int k, n;
    cin >> k >> n;
    cout << sqr(k, n) << endl;

}