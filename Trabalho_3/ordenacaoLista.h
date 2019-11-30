#ifndef ORDENACAO_LISTA_H
#define ORDENACAO_LISTA_H

struct Node;

class List {
    private:
        //Cabeçalho da lista
        Node *head;

    public:
        //Construtor
        List();

        //Destrutor
        ~List();

        //Insere um inteiro key ao final da lista
        void push_back (int key);

        //Remove elemento do final da lista e retorna seu valor
        int pop_back();

        //Insere um novo nó com valor key após o index-ésimo nó da lista
        void insert_after (int key, int index);

        //Remove da lista a primeira ocorrência do inteiro key
        void remove (int key);

        //Remove da lista todas as ocorrências do inteiro key
        void remove_all (int key);

        //Busca um valor e retorna um ponteiro
        Node *search (int key);

        //Remove da lista o nó apontado pelo ponteiro x
        void remove_node (Node *x);

        void data_file_read_list(int array_size, int *array, const char *data_file_name);


        /*Remove o index-ésimo nó da lista encadeada e retorna o seu valor.
        Caso o index-ésimo nó não exista, o programa libera memória alocada e
        finaliza*/
        int remove_node_at (int index);

        //Imprime os elementos da lista
        void print();

        // Imprime os elementos da lista em ordem inversa
        void print_reverse();

        //Retorna true se a lista estiver vazia ou false, caso contrário
        bool is_empty();

        //Bubble Sort
        void bubbleSort ();
        
        //Insertion Sort
        void insertionSort ();

        //Selection Sort
        //void selectionSort (List *list);

        //Merge Sort
        //void mergeSort (List *list);

        //Heap Sort
        //void heapSort (List *list);

        //Quick Sort
        //void quickSort (List *list);


        //Retorna o número de nós da lista
        int size();

        //Remove todos os elementos da lista e deixa apenas o nó cabeça
        void clear();

        //Concatena a lista atual com a lista "list2" passada por parâmetro.
        void concat (List *list2);

        //Retorna um ponteiro para uma cópia desta lista
        List *copy();

        //Copia os elementos do vetor array para a lista
        void copy_array (int *array, int array_size);

        //Determina se a lista passada por parâmetro é igual à lista em questão
        bool equal (List *list2);

        /*Recebe como parâmetro um valor inteiro "value" e divide a lista
        em duas, de forma à segunda lista começar no primeiro nó
        logo após a primeira ocorrência de "value" na lista original*/
        List *separate (int value);

        /*Recebe uma QX List como parâmetro e constrói uma nova lista
        com a intercalação dos nós da lista original com os nós
        da lista passada por parâmetro*/
        void merge_lists (List *list2);
};

#endif
