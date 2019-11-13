/*
    Nome: Fábio Luz Duarte Filho
    Matrícula: 474027
    Curso: Ciência da Computação
*/

#include <iostream>
#include <climits>
#include "QX_List.h"
using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
};

Node* QX_List::search (int key) {
    Node *aux = head->next;
    while(aux != head && aux->key != key)
        aux = aux->next; 
    return (aux == head) ? NULL : aux;
}

QX_List::QX_List() {
    head = new Node;
    head->key = 0;
    head->next = head;
    head->prev = head;
}

QX_List::~QX_List() {
    clear();
    delete head;
    cout << "Lista destruída" << endl;
}

void QX_List::push_back (int key) {
        Node *added = new Node;
        (head->prev)->next = added;
        added->key = key;
        added->next = head;
        added->prev = head->prev;
        head->prev = added;
}

int QX_List::pop_back() {
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

void QX_List::insert_after (int key, int index) {
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

void QX_List::remove (int key) {
    Node *aux = head->next;
    while (aux != head) {
        if (aux->key == key) {
            (aux->prev)->next = aux->next;
            (aux->next)->prev = aux->prev;
            aux->next = NULL;
            aux->prev = NULL;
            delete aux;
            cout << "Valor removido" << endl;
            return;
        }
        aux = aux->next;
    }
    cerr << "Valor não encontrado" << endl;
}

void QX_List::remove_all (int key) {
    Node *aux = head->next;
    int flag = 0;
    while (aux != head) {
        if (aux->key == key) {
            Node *aux2 = aux;
            (aux2->prev)->next = aux2->next;
            (aux2->next)->prev = aux2->prev;
            aux = aux->next;
            aux2->next = NULL;
            aux2->prev = NULL;
            delete aux2;
            cout << "Valor removido" << endl;
            flag = 1;
        }
        else
            aux = aux->next;
    }
    if (flag == 0)
        cerr << "Valor não encontrado" << endl;
}

void QX_List::remove_node (Node *x) {
    (x->prev)->next = x->next;
    (x->next)->prev = x->prev;
    x->next = NULL;
    x->prev = NULL;
    delete x;
}

int QX_List::remove_node_at (int index) {
    Node *aux = head->next;
    for (int i = 0; i < index; i++)
        aux = aux->next;
    (aux->prev)->next = aux->next;
    (aux->next)->prev = aux->prev;
    int returnable = aux->key;
    aux->next = NULL;
    aux->prev = NULL;
    delete aux;
    return returnable;
}

void QX_List::print() {
    Node *aux = head->next;
    while (aux != head) {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

void QX_List::print_reverse() {
    Node *aux = head->prev;
    while (aux != head) {
        cout << aux->key << " ";
        aux = aux->prev;
    }
    cout << endl;
}

bool QX_List::is_empty() {
    return (head->next == head);
}

int QX_List::size() {
    int count = 0;
    Node *aux = head->next;
    while (aux != head) {
        count++;
        aux = aux->next;
    }
    return count;
}

void QX_List::clear() {
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

void QX_List::concat (QX_List *list2) {
    while (!list2->is_empty()) {
        Node *aux = (list2->head)->next;
        push_back(aux->key);
        list2->remove_node(aux);
    }
    cout << "Listas concatenadas com sucesso" << endl;
}

QX_List* QX_List::copy() {
    QX_List *list_copy = new QX_List();
    Node *aux = head->next;
    while (aux != head) {
        list_copy->push_back(aux->key);
        aux = aux->next;
    }
    return list_copy;
}

void QX_List::copy_array (int *array, int array_size) {
    for (int i = 0; i < array_size; i++)
        push_back(array[i]);
    cout << "Array copiado para a lista" << endl;
}

bool QX_List::equal (QX_List *list2) {
    if (size() != list2->size()) return false;    
    Node *aux1 = head->next;
    Node *aux2 = (list2->head)->next;
    while (aux1 != head && aux2 != list2->head) {
        if (aux1->key != aux2->key) return false;
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return true;
}

QX_List* QX_List::separate (int value) {
    Node *pre_fork = search(value);
    if (pre_fork != NULL) {
        Node *fork = pre_fork->next;
        QX_List *list2 = new QX_List();
        while (fork != head) {
            list2->push_back(fork->key);
            remove_node(fork);
        }
        return list2;
    }
    else { 
        cerr << "Valor não encontrado" << endl;
        return this;
    }
}

void QX_List::merge_lists (QX_List *list2) {
    int index = 0;
    while (!list2->is_empty()) {
        Node *aux2 = (list2->head)->next;
        insert_after(aux2->key, index);
        list2->remove_node(aux2);
        index += 2;
    }
    cout << "Listas misturadas com sucesso" << endl;
}