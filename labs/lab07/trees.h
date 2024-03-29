#ifndef TREES_H_
#define TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef int Typeinfo;

// All the common functions for the trees

// Returns NULL to create a tree pointer
void *createTree(void);

// Returns the node of the tree with the right info, NULL if not found
void *searchTree(void *inputTree, Typeinfo info);

// Displays the tree in the terminal, input int determines mode, output int determines if the function was successful
// 1 - preFixadoE | 2 - preFixadoD | 3 - posFixadoE | 4 - posFixadoD
// 5 - CentralE |  6 - CentralD | 7 - emFixadoD
int displayTree(void *inputTree, int mode);

// Destroys the tree completely
void *destroyTree(void *inputTree);

Typeinfo getInfo(void *root);

int numberNodes(void *inputTree);

int heightTree(void *inputTree);

#endif