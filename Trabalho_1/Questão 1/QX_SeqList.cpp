/*
    Nome: Fábio Luz Duarte Filho
    Matrícula: 474027
    Curso: Ciência da Computação
*/

#include <iostream>
#include <climits>
#include "QX_SeqList.h"
using namespace std;

//Privates:

bool QX_SeqList::is_full() {
    return (array_size == array_cap);
}

void QX_SeqList::redimensionate_plus () {
    int aux[array_cap];
    for (int i = 0; i < array_size; i++)
        aux[i] = array[i];
    array = new int [array_cap*2];
    for (int i = 0; i < array_size; i++)
        array[i] = aux[i];
    array_cap *= 2;
}

void QX_SeqList::redimensionate_minus() {
    int aux[array_size];
    for (int i = 0; i < array_size; i++)
        aux[i] = array[i];
    array = new int [array_cap/2+array_cap%2];
    for (int i = 0; i < array_size; i++)
        array[i] = aux[i];
    array_cap = (array_cap/2+array_cap%2);
}

//Publics:

QX_SeqList::QX_SeqList (int cap) {
    if (cap > 0) {
        array = new int[0];
        array_cap = cap;
    } else cerr << "Entrada inválida" << endl;
}

QX_SeqList::~QX_SeqList() {
    if (array != NULL) {
        delete[] array;
        cout << "Lista destruída" << endl;
    }
}

int QX_SeqList::size() {
    return array_size;
}

bool QX_SeqList::is_empty() {
    return (array_size == 0);
}

int QX_SeqList::search (int value) {
    if (!is_empty()) {
        for (int i = 0; i < array_size; i++)
            if (array[i] == value)
                return i;
        return INT_MIN;
    } else {
        cerr << "Lista vazia" << endl;
        return INT_MIN;
    }
}

int QX_SeqList::at (int index) {
    if (index >= 0 && index <= array_size)
        return array[index];
    return INT_MIN;
}

void QX_SeqList::push_back (int value) {
    if (is_full())
        redimensionate_plus();
    array[array_size] = value;
    array_size++;  
}

void QX_SeqList::clear() {
    array_size = 0;
}

void QX_SeqList::print() {
    for (int i = 0; i < array_size; i++)
        cout << "[" << i << "]: " << array[i] << " ";
    cout << endl;
}

void QX_SeqList::print_reverse() {
    for (int i = array_size-1; i >= 0; i--)
        cout << "[" << i << "]: " << array[i] << " ";
    cout << endl;
}

void QX_SeqList::remove (int value) {
    int index = search(value);
    if (index >= 0) {
        for (int i = index; i < array_size-1; i++)
            array[i] = array[i+1];
        array_size--;
        if (array_cap >= 2.5*array_size)
            redimensionate_minus();
    }
    else cerr << "Valor não encontrado" << endl;
}

void QX_SeqList::remove_all (int value) {
    for (int i = array_size-1; i >= 0; i--)
        if (array[i] == value)
            remove(value);
}

int QX_SeqList::pop_back() {
    if (!is_empty()) {
        int returnable_value = array[array_size-1];
        array_size--;
        if (array_cap >= 2.5*array_size)
            redimensionate_minus();
        cout << "Valor removido" << endl;
        return returnable_value;
    } else {
        cerr << "Lista vazia" << endl;
        return INT_MIN;
    }
}