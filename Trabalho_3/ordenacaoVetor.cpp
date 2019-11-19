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

/*
void merge (int *array, int begin, int middle, int end) {
    int iAux, jAux, kAux;
    int *aux = new int[end-begin+1]; //Vetor auxiliar
    iAux = begin; jAux = middle+1; kAux = 0;

    //Intercala array[begin..middle] e array[middle+1..end]
    while (iAux <= middle && jAux <= end) {
        if (array[iAux] <= array[jAux])
            aux[kAux++] = array[iAux++];
        else
            aux[kAux++] = array[jAux++];
    }
    while (iAux <= middle) aux[kAux++] = array[iAux++];
    while (jAux <= end) aux[kAux++] = array[jAux++];

    //Copia vetor ordenado aux para o vetor array
    for (iAux = begin; iAux <= end; iAux++)
        array[iAux] = aux[iAux-begin];

    delete[] aux;
}
*/

/*
void recursiveMergeSort (int *array, int begin, int end) {
    if (begin < end) {
        int middle = (begin + end)/2;
        recursiveMergeSort(array, begin, middle);
        recursiveMergeSort(array, middle + 1, end);
        merge(array, begin, middle, end);
    }
}

int partitionate (int *array, int begin, int end) {
    int pivot = array[end];
    int i = begin;
    for (int k = begin; k < end; k++) {
        if (array[k] <= pivot) {
            swap(array[k], array[i]);
            i++;
        }
    }
    array[end] = array[i];
    array[i] = pivot;
    return i;
}

void recursiveQuickSort (int *array, int begin, int end) {
    if (begin < end) {
        int middle = partitionate(array, begin, end);
        recursiveQuickSort(array, begin, middle-1);
        recursiveQuickSort(array, middle+1, end);
    }
}
*/
