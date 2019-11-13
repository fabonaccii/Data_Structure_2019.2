#include <iostream>
using namespace std;

void swap (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void array_inverter (int *array, int n, int index) {
    if (index > n) 
        return;
            
    swap(array[index], array[n-1]);

    array_inverter(array, n-1, index+1);
}

int main (void) {
    int n;
    cin >> n;
    int *array = new int[n];

    for (int i = 0; i < n; i++) cin >> array[i];

    array_inverter(array, n, 0);
    
    for (int i = 0; i < n; i++) cout << array[i] << " ";
    cout << endl;
}