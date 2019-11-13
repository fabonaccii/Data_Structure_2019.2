/*
    Author: Fábio Luz Duarte Filho
*/

#ifndef TREE_H
#define TREE_H

struct TreeNode;

//Cria nó
TreeNode* createNode (int key, TreeNode* left, TreeNode* right);

//Libera memória alocada pela árvore
TreeNode* freeTree (TreeNode* node);

//Calcula a altura da árvore de n folhas
int treeHeight (int array_size);

//Compara nós "irmãos" e cria nó pai com a chave menor
TreeNode* nodesComparisonToCreate (TreeNode* left, TreeNode* right);

//Retorna a chave de certo nó
int getKey (TreeNode* root);

//"Seta" chave em um certo nó
void setKey (TreeNode* node, int key);

//Retorna a nó de menor chave
TreeNode* whichNodeIsSmaller (TreeNode** array, int array_size);

#endif
