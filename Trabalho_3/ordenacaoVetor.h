#ifndef ORDENACAO_VETOR_H
#define ORDENACAO_VETOR_H

//Função de troca auxiliar
void swap (int* x, int* y);

//Bubble Sort iterativo
void iteractiveBubbleSort (int* array, int size);

//Bubble Sort recursivo
void recursiveBubbleSort (int* array, int size);

//Insertion Sort iterativo
void iteractiveInsertionSort (int* array, int size);

//Insertion Sort recursivo
void recursiveInsertionSort (int* array, int size);

//Selection Sort iterativo
void iteractiveSelectionSort (int* array, int size);

//Selection Sort recursivo
void recursiveSelectionSort (int* array, int size);

//Função auxiliar do Merge Sort
void merge (int *array, int begin, int middle, int end);

//Merge Sort iterativo
void iteractiveMergeSort ();

//Merge Sort recursivo
void recursiveMergeSort (int *array, int begin, int end);

//Função auxiliar do Heap Sort
void maxHeap (int * array, int size, int index);

//Heap Sort iterativo
void iteractiveHeapSort (int *array, int size);

//Heap Sort recursivo
void recursiveHeapSort ();

//Funcão auxiliar do Quick Sort
int partitionate (int *array, int begin, int end);

//Quick Sort iterativo
void iteractiveQuickSort ();

//Quick Sort recursivo
void recursiveQuickSort (int *array, int begin, int end);

#endif
