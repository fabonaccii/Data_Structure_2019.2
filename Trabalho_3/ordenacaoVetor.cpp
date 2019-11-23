#include <iostream>
#include "ordenacaoVetor.h"


void swap (int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}



void iteractiveBubbleSort (int *array, int size) {
    bool swapped;
    for (int i = 0; i < size-1; i++) {
        swapped = false;
        for (int j = size-1; j > i; j--)
            if (array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
                swapped = true;
            }
        if (swapped == false)
            break;
    }
}

void recursiveBubbleSort (int *array, int size) {
    if (size < 1)
        return;

    bool swapped = false;
    for (int i = 0; i < size-1; i++)
        if (array[i] > array[i+1]) {
            swap(&array[i], &array[i+1]);
            swapped = true;
        }
    
    if (swapped == false)
        return;
    recursiveBubbleSort(array, size-1);
}

void iteractiveInsertionSort (int *array, int size) {
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
    //Caso base onde será feita a verificação no vetor se o seu tamanho é menor ou igual a 1
    //Se for igual a 1, significa que o vetor possui um elemento, logo não é necessário a sua ordenação
    //se for igual a 0, o vetor está vazio, logo não há nada a fazer.
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


void merge (int *array, int begin, int middle, int end) {
    int iAux, jAux, kAux;
    int *aux_array = new int[end-begin+1]; //Vetor auxiliar
    iAux = begin; jAux = middle+1; kAux = 0;

    //Intercala array[begin..middle] e array[middle+1..end]
    while (iAux <= middle && jAux <= end) {
        if (array[iAux] <= array[jAux])
            aux_array[kAux++] = array[iAux++];
        else
            aux_array[kAux++] = array[jAux++];
    }
    while (iAux <= middle) aux_array[kAux++] = array[iAux++];
    while (jAux <= end) aux_array[kAux++] = array[jAux++];

    //Copia vetor ordenado aux para o vetor array
    for (iAux = begin; iAux <= end; iAux++)
        array[iAux] = aux_array[iAux-begin];

    delete[] aux_array;
}

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
    int i = begin-1;
    for (int j = begin; j <= end-1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return i+1;
}

void recursiveQuickSort (int *array, int begin, int end) {
    if (begin < end) {
        int middle = partitionate(array, begin, end);
        recursiveQuickSort(array, begin, middle-1);
        recursiveQuickSort(array, middle+1, end);
    }
}



void max_heap(int* array, int size, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&array[index],&array[largest]);
        max_heap(array, size, largest);
    }
}




void iteractiveHeapSort(int* array, int size){
     for (int i = size / 2 - 1; i >= 0; i--)
        max_heap(array, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        max_heap(array, i, 0);
    }    
}
