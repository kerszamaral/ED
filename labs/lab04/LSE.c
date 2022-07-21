/* Ian Kersz - Cartão UFRGS: 00338368
Implementação das funções utilizadas no trabalho para a LSE.
*/

#include "LSE.h"

ptLSE *criaLista()
{
    return NULL; //retorna NULL para indicar que a lista está vazia
}

void print_list(ptLSE *ptLista) 
{
    if (ptLista == NULL)
    {
        printf("\nLista vazia\n"); //se a lista estiver vazia, imprime que está vazia
        return;
    }

    printf("\nLista: "); //imprime a lista
    while (ptLista->prox != NULL) //enquanto o ponteiro prox for diferente de NULL, imprime o numero do nó
    {
        printf("%d -> ", ptLista->num); // imprime o numero do nó
        ptLista = ptLista->prox; //ponteiro para o nó seguinte
    }
    printf("%d\n", ptLista->num); //imprime o numero do nó
}

void insere(ptLSE **ptLista, int valor) //Função maluca
{
    if (*ptLista == NULL) //Se a lista estiver vazia
    {
        *ptLista = (ptLSE *)malloc(sizeof(ptLSE)); //aloca memória para o nó
        (*ptLista)->num = valor; //atribui o valor ao nó
        (*ptLista)->prox = NULL; //atribui NULL ao ponteiro prox
        return; //retorna
    }

    int duplicado = 0; //variável que indica se o valor já está na lista
    ptLSE *aux = *ptLista; //ponteiro auxiliar para percorrer a lista
    ptLSE *ant = NULL; //ponteiro auxiliar para percorrer a lista
    ptLSE *antant = NULL; //ponteiro auxiliar para percorrer a lista

    while (aux != NULL) 
    {
        if (aux->num == valor)
        {
            duplicado = 1; //se o valor já está na lista, duplicado recebe 1
            break; //sai do loop
        }
        antant = ant; //atribui o ponteiro ant ao ponteiro antant
        ant = aux; //atribui o ponteiro aux ao ponteiro ant
        aux = aux->prox; //atribui o ponteiro prox ao ponteiro aux
    }

    if (duplicado == 1)
    {
        ptLSE *novoAnt = (ptLSE *)malloc(sizeof(ptLSE)); //aloca memória para o nó
        novoAnt->num = valor-1; //atribui o valor ao nó
        novoAnt->prox = aux; //atribui o ponteiro aux ao ponteiro prox
        if (ant == NULL)
        {
            *ptLista = novoAnt; //se o ant for NULL, atribui o ponteiro novoAnt ao ponteiro da lista
        }
        else
        {
            ant->prox = novoAnt; //se o ant não for NULL, atribui o ponteiro novoAnt ao ponteiro prox do ant
        }
        
        ptLSE *novoPost = (ptLSE *)malloc(sizeof(ptLSE)); //aloca memória para o nó
        novoPost->num = valor+1; //atribui o valor ao nó
        novoPost->prox = aux->prox; //atribui o ponteiro prox ao ponteiro prox do aux
        aux->prox = novoPost; //atribui o ponteiro novoPost ao ponteiro prox do aux
    }
    else
    {  
        ptLSE *livre = *ptLista; //ponteiro auxiliar para percorrer a lista
        *ptLista = (*ptLista)->prox; //atribui o ponteiro prox ao ponteiro da lista
        free(livre); //libera a memória do nó
        if (antant != NULL)
        {
            antant->prox = NULL; //se o antant não for NULL, atribui NULL ao ponteiro prox do antant
            free(ant); //libera a memória do nó
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
    ptLSE *novo = (ptLSE *)malloc(sizeof(ptLSE)); //aloca memória para o nó
    novo->num = valor; //atribui o valor ao nó
    novo->prox = *ptLista; //atribui o ponteiro da lista ao ponteiro prox do nó
    *ptLista = novo; //atribui o ponteiro novo ao ponteiro da lista
}