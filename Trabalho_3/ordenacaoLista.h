#ifndef ORDENACAO_LISTA_H
#define ORDENACAO_LISTA_H

struct Node;

class List {
    private:
        //Cabeçalho da lista
        Node* head;
    public:
        //Construtor
        List();

        //Destrutor
        ~List();

        //void data_file_read_list(int array_size, Node* list , const char *data_file_name);

        //Insere um inteiro key ao final da lista
        void pushBack (int key);

        //Remove elemento do final da lista e retorna seu valor
        int popBack();

        //Insere um novo nó com valor key após o index-ésimo nó da lista
        void insertAfter (int key, int index);

        //Busca um valor e retorna um ponteiro
        //Node *search (int key);

        //Imprime os elementos da lista
        void print();

        //Retorna true se a lista estiver vazia ou false, caso contrário
        bool isEmpty();

        //Retorna o número de nós da lista
        int size();

        //Remove todos os elementos da lista e deixa apenas o nó cabeça
        void clear();

        //Retorna um ponteiro para uma cópia desta lista
        //List *copy();

        //Copia os elementos do vetor array para a lista
        //void copyArray (int *array, int array_size);

        //Bubble Sort
        void bubbleSort (Node *list);

        //Insertion Sort
        //void insertionSort (List *list);

        //Selection Sort
        //void selectionSort (List *list);

        //Merge Sort
        //void mergeSort (List *list);

        //Heap Sort
        //void heapSort (List *list);

        //Quick Sort
        //void quickSort (List *list);
};

#endif
