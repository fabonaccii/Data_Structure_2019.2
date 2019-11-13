#include <iostream>
using namespace std;

void russian (int a, int b, int *result) {
    if (a%2 == 1) *result += b;
    if (a == 1)
        return;
    russian (a/2, b*2, result);
}

int main (void) {
    int a, b, result = 0;
    cin >> a >> b;
    russian(a, b, &result);
    cout << result << endl;
}