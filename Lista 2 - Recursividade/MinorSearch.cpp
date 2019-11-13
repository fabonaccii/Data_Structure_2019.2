#include <iostream>
using namespace std;

int minor_search (int *array, int min, int index) {
    if (index < 0)
        return min;
    if (array[index] < min)
        min = array[index];
    minor_search (array, min, index-1);
}

int main (void) {
    int n;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << minor_search (array, array[n-1], n-2) << endl;
}