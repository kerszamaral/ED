#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

typedef int Typeinfo; // Tipo de dado para o valor da arvore

typedef struct AVL AVL; // Tipo de dado para a arvore

int insertABP(AVL **raiz, int info); // Funcao para inserir na arvore

int Factor(AVL *root); // Funcao para calcular o fator de balanceamento

int closestValue(AVL *root, int value); // Funcao para buscar o valor mais proximo

int insertAVL(AVL **root, Typeinfo info); // Funcao para inserir na arvore

int is_avl(AVL *a); // Funcao para verificar se a arvore é AVL

#endif // AVL_H_