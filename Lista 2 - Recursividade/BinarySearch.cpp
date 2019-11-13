#include <iostream>
using namespace std;

string binary_search (int *array, int begin, int final, int x) {
    int central = (begin+final)/2;
    if (begin > final) return "Não encontrado";
    if (x == array[central]) return "Encontrado";
    if (x < array[central]) return binary_search(array, begin, central-1, x);
    if (x > array[central]) return binary_search(array, central+1, final, x);
}

int main (void) {
    int n;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = i+1;
    int x;
    cin >> x;
    cout << binary_search(array, 0, n-1, x) << endl;
}