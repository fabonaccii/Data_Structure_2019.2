/* 
Aluno: Alysson Alexandre de Oliveira Araújo
Matricula: 474084
 
Aluno: Fábio Luz Duarte Filho
Matricula: 474027
*/

#include <iostream>
#include "ordenacaoLista.h"
#include <climits>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
};

List::List(){
    head = new Node;
    head->key = 0;
    head->next = head;
    head->prev = head;
}

List::~List() {
    clear();
    delete head;
    cout << "Lista destruída" << endl;
}


void List::push_back (int key) {
    Node *added = new Node;
    (head->prev)->next = added;
    added->key = key;
    added->next = head;
    added->prev = head->prev;
    head->prev = added;
}

bool List::is_empty() {
    return (head->next == head);
}

void List::clear() {
    if (!is_empty()) {
        Node *aux_forward;
        Node *aux_back;
        while (!is_empty()) {
            aux_back = head->prev;
            head->prev = aux_back->prev;
            aux_forward = head->next;
            head->next = aux_forward->next;
            delete aux_forward;
            if (!is_empty())
                delete aux_back;
        }
    }
}

void List::print() {
    Node *aux = head->next;
    while (aux != head) {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

void List::bubbleSort() {
    //Verifica se a lista possui apenas um elemento
    Node* list = head;
    if(list->next == list && list->prev == list)
        return;
    /*
    É criado dois node onde o last vai guardar o último elemento e o aux vai guardar o primeiro elemento da lista
    */
    Node* last = list->prev;
    Node* aux = list->next;
    while(aux != list){
        Node* aux2 = last;
        while(aux2 != aux){
            if((aux2->prev)->key > aux2->key){
                swap((aux2->prev)->key,aux2->key);
            }
            aux2 = aux2->prev;
        }
        aux = aux->next;
    }
}

void List::data_file_read_list(int array_size, int *array, const char *data_file_name) {	
	ifstream in_file(data_file_name, ios::binary);
	
    Node* list = new Node;
    list = head;
	
	for (int i = 0; i < array_size; i++){
		in_file.read((char*)&array[i], sizeof(int));
		push_back(array[i]);
	}
}
