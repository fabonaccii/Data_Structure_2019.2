/*
    Nome: Fábio Luz Duarte Filho
    Matrícula: 474027
    Curso: Ciência da Computação
*/

#ifndef QX_SEQLIST_H
#define QX_SEQLIST_H
#include <iostream>

class QX_SeqList {
    private:
        int *array = NULL;
        int array_size = 0;
        int array_cap = 0;

        //Retorna true se a lista estiver cheia ou false se não estiver
        bool is_full();

        //Redimensiona a lista, aumentado-a
        void redimensionate_plus();

        //Redimensiona a lista, diminuindo-a
        void redimensionate_minus();

    public:
        //Construtor: Constrói uma lista de capacidade igual ao valor passado como parâmetro
        QX_SeqList (int cap);

        //Destrutor: Destrói a lista, desalocando o espaço anteriormente alocado para ela
        ~QX_SeqList();

        //Retorna o tamanho da lista
        int size();

        //Retorna true se a lista estiver vazia ou false se não estiver
        bool is_empty();

        /*Busca pelo elemento do parâmetro e retorna o índice do primeiro nó que
          possua o elemento*/
        int search (int value);

        //Retorna o elemento existente no nó do índice repassado como parâmetro
        int at (int index);

        //Adiciona valor ao final da lista
        void push_back (int value);

        //Limpa a lista
        void clear();

        //Imprime os valores guardados na lista do começo ao fim
        void print();

        //Imprime os valores guardados na lista do fim ao começo
        void print_reverse();

        /*Remove da lista o primeiro nó que possuir o valor repassado
          no parâmetro*/
        void remove (int value);

        /*Remove da lista todos os nós que possuírem o valor repassado
          repassado no parâmetro*/
        void remove_all (int value);

        //Remove o último nó da lista e retorna o seu valor 
        int pop_back();
};
#endif