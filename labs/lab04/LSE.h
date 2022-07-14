#ifndef test_H_
#define test_H_

/*
Interface da Lista Simples Encadeada em C e suas funções.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo ptLSE;
struct tipoNo {
    int num;
    ptLSE *prox;
};

void print_list(ptLSE *ptLista);

void insere(ptLSE **ptLista, int valor);

void destroi(ptLSE **ptLista);

void insere_normal(ptLSE **ptLista, int valor);

#endif