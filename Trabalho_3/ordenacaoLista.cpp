#include <iostream>
#include "ordenacaoLista.h"
#include <climits>

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

int List::pop_back() {
    if (!is_empty()) {
        int returnable_value = (head->prev)->key;
        Node *aux = head->prev;
        (aux->prev)->next = head;
        head->prev = aux->prev;
        delete aux;
        return returnable_value;
    }
    return INT_MIN;
}
/*
void List::insert_after (int key, int index) {
    if (index >= 0 && index < size()) {
        Node *aux = head->next;
        for (int i = 0; i < index; i++)
            aux = aux->next;
        Node *added = new Node;
        added->key = key;
        added->next = aux->next;
        added->prev = aux;
        (aux->next)->prev = added;
        aux->next = added;
    }
}
*/

void List::print() {
    Node *aux = head->next;
    while (aux != head) {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

int List::size() {
    int count = 0;
    Node *aux = head->next;
    while (aux != head) {
        count++;
        aux = aux->next;
    }
    return count;
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
    else
        cerr << "A lista já está vazia" << endl;
}





void List::bubbleSort() {
    
    //Verifica se a lista possui apenas um elemento
    Node* list = head;
    if(list->next == list && list->prev == list){
        return;
    }
    /*
    É criado dois node onde o last vai guardar o último elemento e o aux vai guardar o primeiro elemento da lista
    */
    Node* last = list->prev;
    Node* aux = list->next;
    while(aux!= list){
        Node* aux2= last;
        while(aux2!= aux){
            if((aux2->prev)->key > aux2->key){
                swap((aux2->prev)->key,aux2->key);
            }
            aux2 = aux2->prev;
        }
        aux = aux->next;
    }
}


//Não está funcionando
void List::insertionSort () {
    //se a lista estiver vazia:
    Node* list = head;
    if(list->next== list && list->prev ==list){
        return;
    }

    //Se a lista tiver 2 elementos na lista
    if((list->next)->next == list){
        if(list->next->key > (list->next)->next->key){
            swap(list->next->key, (list->next)->next->key);
            return;
        }
    }


    //Quando a lista possuir 3 ou mais elementos
    for(Node* aux = (list->next)->next; aux!= list; aux = aux->next){
        int Key_aux = aux->key;
        Node* aux2 = list->next;
        while(aux2->key >= list->next->key && aux2->key > Key_aux){
            aux2->next->key = aux2->key;
            aux2 = aux2->prev;
        }
        aux2->next->key = Key_aux;
        aux2 = aux2->next;
    }
    
} 
    
    /*
    for(Node* aux = list->next; aux!=list; aux = aux->next){
        Node* aux_prev = list->prev;
        Node* aux_next = list->next;

        while(aux_next->key < aux_prev->key && aux_prev->next != list){

                


        }

    
    }*/


    void listSelectionSort () {

    }

void listMergeSort () {

}

void listHeapSort () {

}

void listQuickSort () {

}
