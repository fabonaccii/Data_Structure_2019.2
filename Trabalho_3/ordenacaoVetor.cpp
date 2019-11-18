#include <iostream>
#include "ordenacaoVetor.h"

void swap (int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void iteractiveBubbleSort (int* array, int size) {
    for (int i = 0; i < size-1; i++)
        for (int j = size-1; j > i; j--)
            if (array[j] < array[j-1])
                swap(&array[j], &array[j-1]);
}

void recursiveBubbleSort (int* array, int size) {
    if (size < 1) return;
    for (int i = 0; i < size-1; i++) {
        if (array[i] > array[i+1])
            swap(&array[i], &array[i+1]);
    }
    recursiveBubbleSort(array, size-1);
}

void iteractiveInsertionSort (int* array, int size) {
    for (int i = 1; i < size; i++) {
        int aux = array[i];
        int j = i-1;
        while (j >= 0 && array[j] > aux) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;
    }
}

void recursiveInsertionSort (int* array, int size) {
    if(size <= 1)
        return;
    
    int k = size-2; 
    int aux = array[size-1];

    recursiveInsertionSort(array, size-1);

    while(array[k] > aux && k >= 0) {
        array[k+1] = array[k];
        k--;
    }
    array[k+1] = aux;
}

void iteractiveSelectionSort (int *array, int size) {
    for (int i = 0; i < size; i++) {
        int minor = i;
        for (int j = i+1; j < size; j++) {     
            if (array[j] < array[minor]) minor = j;
        }
        if (array[i] != array[minor])
            swap(&array[i], &array[minor]);
    }
}

void recursiveSelectionSort (int* array, int size) {
    if (size <= 1)
        return;

    int major = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[major])
            major = i;
    }
    swap (&array[size-1], &array[major]);

    recursiveSelectionSort(array, size-1);
}
