/* 
Aluno: Alysson Alexandre de Oliveira Araújo
Matricula: 474084
*/
/* 
Aluno: Fábio Luz Duarte Filho
Matricula: 474027
*/

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

        //Inserção de elementos de um arquivo para a lista
        void data_file_read_list(int array_size, int *array, const char *data_file_name);

        //Retorna true se a lista estiver vazia ou false, caso contrário
        bool is_empty();

        //Bubble Sort
        void bubbleSort ();

        //Remove todos os elementos da lista e deixa apenas o nó cabeça
        void clear();
};

#endif
