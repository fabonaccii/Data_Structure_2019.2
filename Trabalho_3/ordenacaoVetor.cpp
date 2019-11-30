#include <iostream>
#include "ordenacaoVetor.h"

void swap (int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void iterativeBubbleSort (int *array, int size) {
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

void iterativeInsertionSort (int *array, int size) {
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
    
    recursiveInsertionSort(array, size-1);

    int k = size-2; 
    int aux = array[size-1];
    
    for(; array[k] > aux && k >= 0; k--) {
        array[k+1] = array[k];
    }
    array[k+1] = aux;
}

void iterativeSelectionSort (int *array, int size) {
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
    if (array[size-1] != array[major])
        swap (&array[size-1], &array[major]);

    recursiveSelectionSort(array, size-1);
}


void merge (int *array, int begin, int middle, int end) {
    int iAux, jAux, kAux;
    int *aux_array = new int[end-begin+1];
    iAux = begin; jAux = middle+1; kAux = 0;

    while (iAux <= middle && jAux <= end) {
        if (array[iAux] <= array[jAux])
            aux_array[kAux++] = array[iAux++];
        else
            aux_array[kAux++] = array[jAux++];
    }
    while (iAux <= middle) aux_array[kAux++] = array[iAux++];
    while (jAux <= end) aux_array[kAux++] = array[jAux++];

    for (iAux = begin; iAux <= end; iAux++)
        array[iAux] = aux_array[iAux-begin];

    delete[] aux_array;
}

void iterativeMergeSort (int *array, int size) {
   for (int curr_size = 1; curr_size <= size-1; curr_size *= 2) { 
       for (int left_start = 0; left_start < size-1; left_start += 2*curr_size) { 
           int middle = (left_start+curr_size-1 < size-1) ? left_start+curr_size-1 : size-1;
           int right_end = (left_start+2*curr_size-1 < size-1) ? left_start+2*curr_size-1 : size-1; 
           merge(array, left_start, middle, right_end); 
       }
    }
}

void recursiveMergeSort (int *array, int begin, int end) {
    if (begin < end) {
        int middle = (begin + end)/2;
        recursiveMergeSort(array, begin, middle);
        recursiveMergeSort(array, middle + 1, end);
        merge(array, begin, middle, end);
    }
}

void buildHeap (int *array, int size) {
    for (int l = 1; l < size; l++)
        for(int a = l + 1; a > 1 && array[a/2] < array[a]; a = a/2)
            swap(&array[a/2], &array[a]);
}

void sieve (int* array, int size){
    for(int k = 2; k <= size; k = k*2) {
        if (array[k] < array[k+1] && k < size)
            k++;
        // Nesse caso o k é o maior filho da divisão de k/2
        if (array[k/2] >= array[k])
            break;
        swap(&array[k/2], &array[k]);
    }
}

void iterativeHeapSort (int* array, int size){
    buildHeap(array,size);
    int x = size;
    while(x >= 2){
        swap(&array[1], &array[x]);
        sieve(array, x-1);
        x--;
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

void iterativeQuickSort(int *array, int begin, int end) { 
    int stack[end-begin+1];   
    int top = 0; 
    stack[top] = begin; 
    stack[++top] = end; 
  
    while (top >= 0) { 
        end = stack[top--]; 
        begin = stack[top--]; 
  
        int middle = partitionate(array, begin, end); 
  
        if (middle-1 > begin) { 
            stack[++top] = begin; 
            stack[++top] = middle-1; 
        } 
  
        if (middle+1 < end) { 
            stack[++top] = middle+1; 
            stack[++top] = end; 
        } 
    } 
} 

void recursiveQuickSort (int *array, int begin, int end) {
    while (begin < end) {
        int middle = partitionate(array, begin, end);
        if (middle-begin < end-middle) {
            recursiveQuickSort(array, begin, middle-1);
            begin = middle+1;
        }
        else {
            recursiveQuickSort(array, middle+1, end);
            end = middle-1;
        }
    }
}
