/*
    Author: Fábio Luz Duarte Filho
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include "Tree.h"
using namespace std;

int whichIsBigger (int* array, int size) {
    int bigger = array[0];
    for (int i = size-1; i > 0; i--)
        if (array[i] > bigger)
            bigger = array[i];
    return bigger;
}

int main () {
    ifstream input_file;
    ofstream output_file;
    input_file.open ("vetores.txt"); //Abre o arquivo de entrada
    output_file.open ("ordenados.txt"); //Abre o arquivo de saída

    string element;
    while (input_file.is_open()){
        //Captando a linha do tamanho do vetor
        input_file >> element;
        int size = stoi(element);
        if (size != 0){
            int height = treeHeight(size);
            int base_nodes = pow(2, height-1);
            int base_nodes_copy = base_nodes; //Backup de base_nodes
            int input_array[base_nodes];
            
            //Captando a linha do vetor
            for (int i = 0; i < size; i++){
                input_file >> element;
                int key = stoi(element);
                //Inserindo no vetor
                input_array[i] = key;
            } 

            //Determina o valor de epsilon (E)
            int epsilon = whichIsBigger(input_array, size) + 1; 

            //Insere no vetor os epsilon caso necessário
            if (size < base_nodes) {
                for (int x = size; x < base_nodes; x++)
                    input_array[x] = epsilon;
            }

            //Vetores auxiliares
            TreeNode* tree_array[base_nodes];
            TreeNode* tree_array_copy[base_nodes]; //Backup de tree_array

            //Criando folhas
            for (int j = 0; j < base_nodes; j++) {
                tree_array[j] = createNode(input_array[j], NULL, NULL);
                tree_array_copy[j] = tree_array[j];
            }

            TreeNode* root = tree_array[0];
            //Rearranjo dos vetores para ordenação em árvore
            while (getKey(root) != epsilon) {
                //Faz recuperação dos backups
                for (int y = 0; y < base_nodes_copy; y++) 
                    tree_array[y] = tree_array_copy[y];
                base_nodes = base_nodes_copy;

                //Faz as comparações de duas em duas folhas
                while (base_nodes > 1) {
                    int k = 0;
                    for (int l = 0; l < base_nodes; l+=2) {
                        tree_array[k] = nodesComparisonToCreate(tree_array[l], tree_array[l+1]); 
                        k++;
                    }
                    base_nodes /= 2;
                }
                
                //A raiz recebe o primeiro índice, que é o eMin
                root = tree_array[0];
                if (getKey(root) == epsilon)
                    break;
                else
                    output_file << getKey(root) << " "; //Imprime no arquivo de saída

                setKey(whichNodeIsSmaller(tree_array_copy, base_nodes_copy), epsilon); //Substitui a folha de menor valor por epsilon
            }
            output_file << endl;
            freeTree(root); //Libera memória alocada pela árvore
        }
        else
            input_file.close(); //Fecha o arquivo de entrada
    }
    output_file.close(); //Fecha o arquivo de saída
}
