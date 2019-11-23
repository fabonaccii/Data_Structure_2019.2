#ifndef ORDENACAO_VETOR_H
#define ORDENACAO_VETOR_H

//struct NoArv;

//Função de troca auxiliar
void swap (int* x, int* y);

void max_heap(int* array, int size, int index);

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


//Merge Sort iterativo
void iteractiveMergeSort ();

//Merge Sort recursivo
void recursiveMergeSort (int *array, int begin, int end);

//Heap Sort iterativo
void iteractiveHeapSort(int* array, int size);

//Heap Sort recursivo
//recursiveHeapSort();

//Quick Sort iterativo
void iteractiveQuickSort ();

//Quick Sort recursivo
void recursiveQuickSort (int *array, int begin, int end);

#endif
