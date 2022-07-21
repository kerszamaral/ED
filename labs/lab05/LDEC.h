#ifndef LDEC_H_
#define LDEC_H_

/*
Interface da Lista Duplamente Encadeada Circular em C e suas funções.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo ptLDEC; //tipo do nó da lista
struct tipoNo { //estrutura do nó da lista
    int num; //numero do nó
    ptLDEC *prox; //ponteiro para o nó seguinte
    ptLDEC *ant; //ponteiro para o nó anterior
};

ptLDEC *criaLista(); //cria a lista

void print_list(ptLDEC *ptLista); //imprime a lista

void insere(ptLDEC **ptLista, int valor); //Função maluca

void destroi(ptLDEC **ptLista); //destroi a lista

void insere_normal(ptLDEC **ptLista, int valor); //insere o valor na lista

#endif