/*
    Nome: Fábio Luz Duarte Filho
    Matrícula: 474027
    Curso: Ciência da Computação
*/

#include <iostream>
#include <climits>
#include "QX_SeqList.h"
using namespace std;

int main () {
    int cap;
    cout << "-----------------------------------------" << endl;
    cout << "Insira a capacidade inicial da lista: ";
    cin >> cap;
    QX_SeqList list = QX_SeqList(cap);
    cout << "Lista criada" << endl << endl;

    int option;
        cout << "------------------------------------------" << endl;
        cout << "0. Para encerrar o programa." << endl;
        cout << "1. Tamanho da lista." << endl;
        cout << "2. Checa se a lista está vazia." << endl;
        cout << "3. Busca valor." << endl;
        cout << "4. Imprime valor no índice." << endl;
        cout << "5. Adiciona valor no final da lista." << endl;
        cout << "6. Esvazia a lista." << endl;
        cout << "7. Imprime os valores da lista." << endl;
        cout << "8. Imprime os valores da lista ao contrário." << endl;
        cout << "9. Remove a primeira ocorrência de um valor." << endl;
        cout << "10. Remove todas as ocorrência de um valor." << endl;
        cout << "11. Remove o último elemento da lista." << endl;
        cout << "------------------------------------------" << endl;
    do {
        cout << endl << "Digite 12 para chamar o menu" << endl;
        cout << "Escolha uma opção: ";
        cin >> option;
        switch (option) {
            case 0:
                cout << "Programa encerrado" << endl;
                break;

            case 1:
                cout << "O tamanho da lista é: " << list.size() << endl;
                break;

            case 2: {
                if (list.is_empty()) cout << "A lista está vazia" << endl;
                else cout << "A lista não está vazia" << endl;
            }
                break;

            case 3: {
                int value;
                cout << "Insira o valor a ser buscado: ";
                cin >> value;
                int result = list.search(value);
                if (result != INT_MIN) cout << "O valor encontra-se no índice: " << result << endl;
                else cout << "Valor não encontrado" << endl;           
            }
                break;

            case 4: {
                int index;
                cout << "Insira o índice: ";
                cin >> index;
                int result = list.at(index);
                if (result != INT_MIN) cout << "O valor no índice " << index << " é: " << list.at(index) << endl;
                else cout << "Índice inválido" << endl;
            }
                break;

            case 5: {
                int value;
                cout << "Insira o valor a ser adicionado: ";
                cin >> value;
                list.push_back(value);
                cout << "Valor adicionado" << endl;
            }
                break;

            case 6: {
                list.clear();
                cout << "A lista foi esvaziada" << endl;
            }
                break;

            case 7: {
                cout << "Lista: ";
                list.print();
            }
                break;

            case 8: {
                cout << "Lista ao contrário: ";
                list.print_reverse();
            }
                break;
            
            case 9: {
                int value;
                cout << "Insira o valor a ser removido: ";
                cin >> value;
                list.remove(value);
            }
                break;

            case 10: {
                int value;
                cout << "Insira o valor a ser removido de toda a lista: ";
                cin >> value;
                list.remove_all(value);
            }
                break;
            
            case 11: {
                cout << "O valor retirado foi: " << list.pop_back() << endl;
            }
                break;

            case 12: {
                cout << endl;
                cout << "------------------------------------------" << endl;
                cout << "0. Para encerrar o programa." << endl;
                cout << "1. Tamanho da lista." << endl;
                cout << "2. Checa se a lista está vazia." << endl;
                cout << "3. Busca valor." << endl;
                cout << "4. Imprime valor no índice." << endl;
                cout << "5. Adiciona valor no final da lista." << endl;
                cout << "6. Esvazia a lista." << endl;
                cout << "7. Imprime os valores da lista." << endl;
                cout << "8. Imprime os valores da lista ao contrário." << endl;
                cout << "9. Remove a primeira ocorrência de um valor." << endl;
                cout << "10. Remove todas as ocorrência de um valor." << endl;
                cout << "11. Remove o último elemento da lista." << endl;
                cout << "------------------------------------------" << endl;
            }
                break;
                
            default:
                cout << "Entrada inválida" << endl;
                break;
        }
    } while (option != 0);
}