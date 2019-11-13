#include <iostream>
using namespace std;

bool search (int *array, int x, int n) {
    if (n == 0)
        return false;
    for (int j = 0; j < n-1; j++)
            if (array[n-1] + array[j] == x)
                return true;
    search (array, x, n-1);
}

int main (void) {
    int n, x;
    cout << "Insira o n: ";
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = i+1;
    cout << "Insira o x: ";
    cin >> x;
    cout << search (array, x, n) << endl;
    
    delete[] array;
    array = NULL;
}