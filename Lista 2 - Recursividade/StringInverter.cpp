#include <iostream>
#include <cstring>
using namespace std;

void string_inverter (char* string, int final, int begin, int size) {
    if (begin == size/2+1)
        return;
    char aux = string [begin];
    string[begin] = string[final];
    string[final] = aux;
    string_inverter (string, final-1, begin+1, size);
}

int main (void) {
    char s_aux[101];
    cin.getline (s_aux, 100);
    int n = strlen(s_aux);
    char *string = new char[n+1];
    for (int i = 0; i < n; i++)
        string[i] = s_aux[i];
    string[n] = '\0';
    string_inverter (string, n-1, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << string[i];
    cout << endl;
}