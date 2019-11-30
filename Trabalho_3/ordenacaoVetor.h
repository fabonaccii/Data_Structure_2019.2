#ifndef ORDENACAO_VETOR_H
#define ORDENACAO_VETOR_H

//Função de troca auxiliar
void swap (int* x, int* y);

//Bubble Sort iterativo
void iterativeBubbleSort (int* array, int size);

//Bubble Sort recursivo
void recursiveBubbleSort (int* array, int size);

//Insertion Sort iterativo
void iterativeInsertionSort (int* array, int size);

//Insertion Sort recursivo
void recursiveInsertionSort (int* array, int size);

//Selection Sort iterativo
void iterativeSelectionSort (int* array, int size);

//Selection Sort recursivo
void recursiveSelectionSort (int* array, int size);

//Função auxiliar do Merge Sort
void merge (int *array, int begin, int middle, int end);

//Merge Sort iterativo
void iterativeMergeSort (int *array, int size);

//Merge Sort recursivo
void recursiveMergeSort (int *array, int begin, int end);

//Funções auxiliares do Heap Sort
void buildHeap (int *array, int size);
void sieve (int *array, int size);

//Heap Sort iterativo
void iterativeHeapSort (int *array, int size);

//Heap Sort recursivo
void recursiveHeapSort ();

//Funcão auxiliar do Quick Sort
int partitionate (int *array, int begin, int end);

//Quick Sort iterativo
void iterativeQuickSort (int *array, int begin, int end);

//Quick Sort recursivo
void recursiveQuickSort (int *array, int begin, int end);

#endif
