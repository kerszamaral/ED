#ifndef LSE_H_
#define LSE_H_

/*
Interface da Lista Simples Encadeada em C e suas funções.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo ptLSE; //tipo do nó da lista
struct tipoNo { //estrutura do nó da lista
    int num; //numero do nó
    ptLSE *prox; //ponteiro para o nó seguinte
};

ptLSE *criaLista(); //cria a lista

void print_list(ptLSE *ptLista); //imprime a lista

void insere(ptLSE **ptLista, int valor); //Função maluca

void destroi(ptLSE **ptLista); //destroi a lista

void insere_normal(ptLSE **ptLista, int valor); //insere o valor na lista

#endif