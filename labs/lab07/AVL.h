#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

typedef int Typeinfo;

typedef struct AVL AVL;

int insertABP(AVL **raiz, int info);

int Factor(AVL *root);

int closestValue(AVL *root, int value);

int insertAVL(AVL **root, Typeinfo info);

int is_avl(AVL *a);

#endif // AVL_H_