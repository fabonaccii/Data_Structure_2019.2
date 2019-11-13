/*
    Author: Fábio Luz Duarte Filho
*/

#include <iostream>
#include <math.h>
#include "Tree.h"
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

//Cria nó
TreeNode* createNode (int key, TreeNode* left, TreeNode* right) {
    TreeNode* node = new TreeNode;
    node->key = key;
    node->left = left;
    node->right = right;
    return node;
}

//Libera memória alocada pela árvore
TreeNode* freeTree (TreeNode* node) {
    if (node != NULL) {
        node->left = freeTree(node->left);
        node->right = freeTree(node->right);
        delete node;
    }
    return NULL;
}

//Calcula a altura da árvore de n folhas
int treeHeight (int array_size) {
    return ceil(log2(array_size)) + 1;
}

//Retorna a chave de certo nó
int getKey (TreeNode* root) {
    return root->key;
}

//"Seta" chave em um certo nó
void setKey (TreeNode* node, int key) {
    node->key = key;
}

//Compara nós "irmãos" e cria nó pai com a chave menor
TreeNode* nodesComparisonToCreate (TreeNode* left, TreeNode* right) {
    if (left->key <= right->key)
        return createNode(left->key, left, right);
    else 
        return createNode(right->key, left, right);
}

//Retorna a nó de menor chave
TreeNode* whichNodeIsSmaller (TreeNode** array, int array_size) {
    int smaller = array[0]->key;
    TreeNode* returnable = array[0];
    for (int i = array_size-1; i >= 0; i--)
        if (array[i]->key < smaller) {
            smaller = array[i]->key;
            returnable = array[i];
        }
    return returnable;
}
