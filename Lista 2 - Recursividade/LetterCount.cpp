#include <iostream>
#include <cstring>
using namespace std;

int letter_count (char *word, char *letter, int *how_many_times, int index) {
    if (index == 0)
        return *how_many_times;
    if (word[index] == *letter) 
        *how_many_times += 1;
    letter_count (word, letter, how_many_times, index-1);
}

int main (void) {
    char aux[101];
    cin.getline (aux, 100);
    int n = strlen(aux);
    char *word = new char[n+1];
    for (int i = 0; i < n; i++)
        word[i] = aux[i];
    word[n] = '\0';
    char letter;
    cin >> letter;
    int how_many_times = 0;
    cout << letter_count (word, &letter, &how_many_times, n-1) << endl;
    delete[] word;
    word = NULL;
}