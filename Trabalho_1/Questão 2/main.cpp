/*
    Nome: Fábio Luz Duarte Filho
    Matrícula: 474027
    Curso: Ciência da Computação
*/

#include <iostream>
#include "QX_List.h"
using namespace std;

int main () {
    QX_List *list = new QX_List();

int option;
        cout << "--------------------------------------------------------------------------------------" << endl;
        cout << "0. Para encerrar o programa." << endl;
        cout << "1. Adiciona valor no final da lista." << endl;
        cout << "2. Remove elemento do final da lista e retorna seu valor." << endl;
        cout << "3. Insere um novo nó com valor key após o index-ésimo nó da lista." << endl;
        cout << "4. Remove a primeira ocorrência de um valor." << endl;
        cout << "5. Remove todas as ocorrência de um valor." << endl;
        cout << "6. Remove da lista o nó apontado pelo ponteiro x." << endl;
        cout << "7. Remove o index-ésimo nó da lista encadeada e retorna o seu valor." << endl;
        cout << "8. Imprime os valores da lista." << endl;
        cout << "9. Imprime os valores da lista ao contrário." << endl;
        cout << "10. Imprime se a lista está vazia ou não." << endl;
        cout << "11. Imprime o tamanho da lista." << endl;
        cout << "12. Limpa a lista removendo todos os seus elementos." << endl;
        cout << "13. Concatena uma segunda lista à lista atual." << endl;
        cout << "14. Cria uma cópia da lista atual." << endl;
        cout << "15. Copia para dentro da lista atual os elementos de um vetor." << endl;
        cout << "16. Determina se duas listas são iguais." << endl;
        cout << "17. Separa a lista atual em duas listas a partir da primeira ocorrência de um valor. (Código defeituoso)" << endl;
        cout << "18. Mistura na lista atual uma segunda lista." << endl;
        cout << "--------------------------------------------------------------------------------------" << endl;
    do {
        cout << endl << "Digite 19 para chamar o menu" << endl;
        cout << "Escolha uma opção: ";
        cin >> option;
        switch (option) {
            case 0:
                cout << endl << "Programa encerrado" << endl;
                break;

            case 1: {
                int value;
                cout << "Insira o valor a ser adicionado: ";
                cin >> value;
                list->push_back(value);
                cout << "Valor adicionado" << endl;
            }
                break;

            case 2: {
                cout << "O valor retirado foi: " << list->pop_back() << endl;
            }
                break;

            case 3: {
                int value;
                cout << "Insira o valor a ser adicionado(key): ";
                cin >> value;
                int index;
                cout << "Insira o índice(index): ";
                cin >> index;
                list->insert_after(value, index);
            }
                break;

            case 4: {
                int value;
                cout << "Insira o valor a ser removido: ";
                cin >> value;
                list->remove(value);
            }
                break;

            case 5: {
                int value;
                cout << "Insira o valor a ser removido de toda a lista: ";
                cin >> value;
                list->remove_all(value);
            }
                break;

            case 6: {
                int value;
                cout << "Insira o valor a ser removido: ";
                cin >> value;
                list->remove_node(list->search(value));
            }
                break;

            case 7: {
                int index;
                cout << "Insira o índice(index): ";
                cin >> index;
                if (index >= 0 && index < list->size())
                    list->remove_node_at(index);
                else
                    option = 0;
            }
                break;

            case 8: {
                cout << "Lista: ";
                list->print();
            }
                break;
            
            case 9: {
                cout << "Lista ao contrário: ";
                list->print_reverse();
            }
                break;

            case 10: {
                if (list->is_empty()) cout << "A lista está vazia" << endl;
                else cout << "A lista não está vazia" << endl;
            }
                break;
            
            case 11: {
                cout << "O tamanho da lista é: " << list->size() << endl;
            }
                break;

            case 12: {
                list->clear();
                cout << "A lista foi esvaziada" << endl;
            }
                break;

            case 13: {
                QX_List *list2 = new QX_List();
                list2->push_back(3);
                list2->push_back(4);
                list2->push_back(4);
                list2->push_back(2);
                cout << "A lista que será concatenada é: ";
                list2->print();
                list->concat(list2);
                cout << "A lista resultante é: ";
                list->print();
                cout << "A lista que foi concatenada, agora é: ";
                list2->print();
            }
                break;

            case 14: {
                cout << "A lista é: ";
                list->print();
                cout << "A cópia da lista é: ";
                (list->copy())->print();
            }
                break;

            case 15: {
                int array_size = 4;
                int array[] = {3,4,4,2};
                list->copy_array(array, array_size);
                cout << "A nova lista é: ";
                list->print();
            }
                break;

            case 16: {
                QX_List *list2 = new QX_List();
                list2->push_back(3);
                list2->push_back(4);
                list2->push_back(4);
                list2->push_back(2);
                cout << "A lista que será comparada é: ";
                list2->print();
                if (list->equal(list2))
                    cout << "São iguais" << endl;
                else
                    cout << "São diferentes" << endl;
            }
                break;

            case 17: {
                /*int forker;
                cout << "Insira o valor a partir do qual a lista será separada: ";
                cin >> forker;
                cout << "A separação da lista resultou em:" << endl;
                cout << "Primeira parte: ";
                list->print();
                cerr << "Segunda parte: ";
                (list->separate(forker))->print();*/
            }
                break;

            case 18: {
                QX_List *list2 = new QX_List();
                list2->push_back(3);
                list2->push_back(4);
                list2->push_back(4);
                list2->push_back(2);
                cout << "A lista que será misturada é: ";
                list2->print();
                list->merge_lists(list2);
                cout << "A lista resultante é: ";
                list->print();
                cout << "A lista que foi misturada, agora é: ";
                list2->print();
            }
                break;

            case 19: {
                cout << "--------------------------------------------------------------------------------------" << endl;
                cout << "0. Para encerrar o programa." << endl;
                cout << "1. Adiciona valor no final da lista." << endl;
                cout << "2. Remove elemento do final da lista e retorna seu valor." << endl;
                cout << "3. Insere um novo nó com valor key após o index-ésimo nó da lista." << endl;
                cout << "4. Remove a primeira ocorrência de um valor." << endl;
                cout << "5. Remove todas as ocorrência de um valor." << endl;
                cout << "6. Remove da lista o nó apontado pelo ponteiro x." << endl;
                cout << "7. Remove o index-ésimo nó da lista encadeada e retorna o seu valor." << endl;
                cout << "8. Imprime os valores da lista." << endl;
                cout << "9. Imprime os valores da lista ao contrário." << endl;
                cout << "10. Imprime se a lista está vazia ou não." << endl;
                cout << "11. Imprime o tamanho da lista." << endl;
                cout << "12. Limpa a lista removendo todos os seus elementos." << endl;
                cout << "13. Concatena uma segunda lista à lista atual." << endl;
                cout << "14. Cria uma cópia da lista atual." << endl;
                cout << "15. Copia para dentro da lista atual os elementos de um vetor." << endl;
                cout << "16. Determina se duas listas são iguais." << endl;
                cout << "17. Separa a lista atual em duas listas a partir da primeira ocorrência de um valor. (Código defeituoso)" << endl;
                cout << "18. Mistura na lista atual uma segunda lista." << endl;
                cout << "--------------------------------------------------------------------------------------" << endl;
            }
                break;
                
            default:
                cout << "Entrada inválida" << endl;
                break;
        }
    } while (option != 0);
    delete list;
}