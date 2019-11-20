#include <iostream>
#include "ordenacaoLista.h"

struct Node {
    int key;
    Node *next;
    Node *prev;
};

List::List() {
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
    cerr << "Lista vazia" << endl;
    return INT_MIN;
}

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
    else cerr << "Índice inválido" << endl;
}

Node* List::search (int key) {
    Node *aux = head->next;
    while(aux != head && aux->key != key)
        aux = aux->next; 
    return (aux == head) ? NULL : aux;
}

void List::print() {
    Node *aux = head->next;
    while (aux != head) {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

bool List::is_empty() {
    return (head->next == head);
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

List* List::copy() {
    List *list_copy = new List();
    Node *aux = head->next;
    while (aux != head) {
        list_copy->push_back(aux->key);
        aux = aux->next;
    }
    return list_copy;
}

void List::copy_array (int *array, int array_size) {
    for (int i = 0; i < array_size; i++)
        push_back(array[i]);
    cout << "Array copiado para a lista" << endl;
}


void List::bubbleSort (List *list) {

}

void List::insertionSort (List *list) {

}

void List::selectionSort (List *list) {

}

void List::mergeSort (List *list) {

}

void List::heapSort (List *list) {

}

void List::quickSort (List *list) {

}
