#include "trees.h"

typedef struct Tree
{
    Typeinfo info;
    struct Tree *L;
    struct Tree *R;
} Tree;

void *createTree(void)
{
    return NULL;
}

void *searchTree(void *inputTree, Typeinfo info)
{
    Tree *root = (Tree *)inputTree;
    if (root == NULL)
    {
        return NULL; // Retorna NULL para indicar que o valor nao existe na arvore
    }
    

    if (info == root->info)
    {
        return root; // Retorna a raiz para indicar que o valor existe na arvore
    }

    if (info < root->info)
    {
        return searchTree(root->L, info); // Busca na esquerda
    }
    else if (info > root->info)
    {
        return searchTree(root->R, info); // Busca na direita
    }
    else
    {
        return NULL; // Retorna NULL para indicar que o valor nao existe na arvore
    }
}

void printTree(Tree *root, int level)
{
    if (root != NULL)
    { // Se a raiz nao for NULL
        for (int i = 0; i < level; i++)
        {
            printf("---"); // Imprime o numero de --- equivalente ao nivel da arvore
        }
        printf("%d\n", root->info); // Imprime o valor da raiz
    }
}

int displayTreeNum(Tree *root, int mode, int level)
{            // Versão de displayABP "privada" que é usada para indicar o nivel sem o usuario necessitar passar o nivel
    level++; // Incrementa o nivel
    if (root == NULL)
    {
        return 0; // Retorna 0 para indicar que nao existe nenhum valor na arvore
    }

    if (mode == 1) // preFixadoE
    {
        printTree(root, level);
        displayTreeNum(root->L, mode, level);
        displayTreeNum(root->R, mode, level);
    }
    else if (mode == 2) // preFixadoD
    {
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
    }
    else if (mode == 3) // posFixadoE
    {
        displayTreeNum(root->L, mode, level);
        displayTreeNum(root->R, mode, level);
        printTree(root, level);
    }
    else if (mode == 4) // posFixadoD
    {
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
        printTree(root, level);
    }
    else if (mode == 5) // CentralE
    {
        displayTreeNum(root->L, mode, level);
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
    }
    else if (mode == 6) // CentralD
    {
        displayTreeNum(root->R, mode, level);
        printTree(root, level);
        displayTreeNum(root->L, mode, level);
    }
    else if (mode == 6) // emFixadoD
    {
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
    }
    else
    {
        printf("Modo de impressão inválido\n"); // Imprime mensagem de erro
        return 0;                               // Retorna 0 para indicar que não foi possivel impirmir a arvore
    }
    return 1; // Retorna 1 para indicar que foi possivel imprimir todos os valores da arvore
}

int displayTree(void *inputTree, int mode)
{                  // Função para imprimir a arvore "publica" para a main
    int level = 0; // Nivel da arvore
    Tree *root = (Tree *)inputTree;
    if (root == NULL)
    {
        return 0; // Retorna 0 para indicar que nao existe nenhum valor na arvore
    }

    if (mode == 1) // preFixadoE
    {
        printTree(root, level);
        displayTreeNum(root->L, mode, level);
        displayTreeNum(root->R, mode, level);
    }
    else if (mode == 2) // preFixadoD
    {
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
    }
    else if (mode == 3) // posFixadoE
    {
        displayTreeNum(root->L, mode, level);
        displayTreeNum(root->R, mode, level);
        printTree(root, level);
    }
    else if (mode == 4) // posFixadoD
    {
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
        printTree(root, level);
    }
    else if (mode == 5) // CentralE
    {
        displayTreeNum(root->L, mode, level);
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
    }
    else if (mode == 6) // CentralD
    {
        displayTreeNum(root->R, mode, level);
        printTree(root, level);
        displayTreeNum(root->L, mode, level);
    }
    else if (mode == 6) // emFixadoD
    {
        printTree(root, level);
        displayTreeNum(root->R, mode, level);
        displayTreeNum(root->L, mode, level);
    }
    else
    {
        printf("Modo de impressão inválido\n"); // Imprime mensagem de erro
        return 0;                               // Retorna 0 para indicar que não foi possivel imprimir a arvore
    }
    return 1; // Retorna 1 para indicar que foi possivel imprimir todos os valores da arvore
}

void *destroyTree(void *inputTree)
{
    if (inputTree == NULL)
    {
        return inputTree;           // Retorna a arvore para indicar que nao existe nenhuma arvore para destruir
    }

    Tree *root = (Tree *)inputTree; // Converte o ponteiro para arvore
    root->L = destroyTree(root->L); // Destroi a arvore da esquerda
    root->R = destroyTree(root->R); // Destroi a arvore da direita
    free(root);                     // Libera a memoria da raiz
    root = NULL;                    // Seta a raiz para NULL
    return root;                    // Retorna NULL para indicar que foi possivel destruir a arvore
}

Typeinfo getInfo(void *inputNode)
{
    Tree *node = (Tree *)inputNode; // Converte o ponteiro para arvore
    return node->info;
}

int numberNodes(void *inputTree)
{
    if (inputTree == NULL)
    {
        return 0; // Retorna 0 para indicar que nao existe nenhum valor na arvore
    }
    Tree *root = (Tree *)inputTree; // Converte o ponteiro para arvore
    return 1 + numberNodes(root->L) + numberNodes(root->R); // Retorna o numero de nos da arvore
}

int heightTree(void *inputTree)
{
    if (inputTree == NULL)
    {
        return 0; // Retorna 0 para indicar que nao existe nenhum valor na arvore
    }

    Tree *root = (Tree *)inputTree; // Converte o ponteiro para arvore
    int left = heightTree(root->L);  // Calcula a altura da arvore da esquerda
    int right = heightTree(root->R); // Calcula a altura da arvore da direita
    return 1 + ((left > right) ? left : right); // Retorna a altura da arvore
}