#include "LSE.h"

void print_list(ptLSE *ptLista)
{
    if (ptLista == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }

    printf("\nLista: ");
    while (ptLista->prox != NULL)
    {
        printf("%d -> ", ptLista->num);
        ptLista = ptLista->prox;
    }
    printf("%d\n", ptLista->num);
}

void insere(ptLSE **ptLista, int valor)
{
    if (*ptLista == NULL)
    {
        *ptLista = (ptLSE *)malloc(sizeof(ptLSE));
        (*ptLista)->num = valor;
        (*ptLista)->prox = NULL;
        return;
    }

    int duplicado = 0;
    ptLSE *aux = *ptLista;
    ptLSE *ant = NULL;
    ptLSE *antant = NULL;

    while (aux != NULL)
    {
        if (aux->num == valor)
        {
            duplicado = 1;
            break;
        }
        antant = ant;
        ant = aux;
        aux = aux->prox;
    }

    if (duplicado == 1)
    {
        ptLSE *novoAnt = (ptLSE *)malloc(sizeof(ptLSE));
        novoAnt->num = valor-1;
        novoAnt->prox = aux;
        if (ant == NULL)
        {
            *ptLista = novoAnt;
        }
        else
        {
            ant->prox = novoAnt;
        }
        
        ptLSE *novoPost = (ptLSE *)malloc(sizeof(ptLSE));
        novoPost->num = valor+1;
        novoPost->prox = aux->prox;
        aux->prox = novoPost;
    }
    else
    {  
        ptLSE *livre = *ptLista;
        *ptLista = (*ptLista)->prox;
        free(livre);
        if (antant != NULL)
        {
            antant->prox = NULL;
            free(ant);
        }
    }
}

void destroi(ptLSE **ptLista)
{
    ptLSE *aux;             // Criamos um ponteiro auxiliar para percorrer a lista
    while (*ptLista != NULL) // Enquanto a lista não estiver vazia, percorremos a lista
    {
        aux = *ptLista;           // O ponteiro auxiliar aponta para o item atual da lista
        *ptLista = (*ptLista)->prox; // O ponteiro da lista aponta para o próximo item da lista
        free(aux);               // Liberamos a memória do item atual da lista
    }
    *ptLista = NULL; // Retorna o ponteiro para NULL
}

void insere_normal(ptLSE **ptLista, int valor)
{
    ptLSE *novo = (ptLSE *)malloc(sizeof(ptLSE));
    novo->num = valor;
    novo->prox = *ptLista;
    *ptLista = novo;
}