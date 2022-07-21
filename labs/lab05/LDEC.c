/* Ian Kersz - Cartão UFRGS: 00338368
Implementação das funções utilizadas no trabalho para a LDEC.
*/

#include "LDEC.h"

ptLDEC *criaLista()
{
    return NULL; // retorna NULL para indicar que a lista está vazia
}

void print_list(ptLDEC *ptLista)
{
    if (ptLista == NULL)
    {
        printf("\nLista vazia\n"); // se a lista estiver vazia, imprime que está vazia
        return;
    }

    printf("\nLista: "); // imprime a lista

    printf("%d", ptLista->num); // imprime o primeiro numero da lista

    ptLDEC *ptAux = ptLista->prox; // ponteiro auxiliar para percorrer a lista

    if (ptAux != ptLista)
    {
        do
        {
            printf(" -> %d", ptAux->num); // imprime o numero do nó
            ptAux = ptAux->prox;          // ponteiro auxiliar para percorrer a lista
        } while (ptAux != ptLista);       // enquanto a lista não for vazia, imprime o numero do nó
    }

    printf("\n"); // imprime um espaço para separar a lista
}

void insere(ptLDEC **ptLista, int valor) // Função maluca
{
    if (*ptLista == NULL) // Se a lista estiver vazia
    {
        ptLDEC *novo = (ptLDEC *)malloc(sizeof(ptLDEC)); // aloca memória para o nó
        novo->num = valor;                               // atribui o valor ao nó
        *ptLista = novo;                                 // atribui o ponteiro novo ao ponteiro da lista
        novo->prox = *ptLista;                           // atribui o ponteiro da lista ao ponteiro prox do novo
        novo->ant = *ptLista;                            // atribui o ponteiro da lista ao ponteiro ant do novo
        return;                                          // retorna
    }

    int duplicado = 0;        // variável que indica se o valor já está na lista
    ptLDEC *ptAux = *ptLista; // ponteiro auxiliar para percorrer a lista

    do
    {
        if (ptAux->num == valor)
        {
            duplicado = 1; // se o valor já está na lista, duplicado recebe 1
            break;         // sai do loop
        }
        ptAux = ptAux->prox;     // atribui o ponteiro prox ao ponteiro ptAux
    } while (ptAux != *ptLista); // enquanto a não chegarmos ao final da lista, percorre a lista

    if (duplicado == 1)
    {
        ptLDEC *novoAnt = (ptLDEC *)malloc(sizeof(ptLDEC)); // aloca memória para o nó
        novoAnt->num = valor - 1;                           // atribui o valor ao nó

        novoAnt->ant = ptAux->ant;  // atribui o ponteiro ant do nó ao ponteiro ant do nó anterior ao nó duplicado
        ptAux->ant->prox = novoAnt; // atribui o ponteiro novoAnt ao ponteiro ant do nó

        novoAnt->prox = ptAux; // atribui o ponteiro prox ao ponteiro novoAnt
        ptAux->ant = novoAnt;  // atribui o ponteiro novoAnt ao ponteiro ant do nó duplicado

        ptLDEC *novoPost = (ptLDEC *)malloc(sizeof(ptLDEC)); // aloca memória para o nó
        novoPost->num = valor + 1;                           // atribui o valor ao nó

        novoPost->prox = ptAux->prox; // atribui o ponteiro prox ao ponteiro novoPost
        ptAux->prox->ant = novoPost;  // atribui o ponteiro novoPost ao ponteiro prox do nó seguinte ao nó duplicado

        novoPost->ant = ptAux;  // atribui o ponteiro ant ao ponteiro novoPost
        ptAux->prox = novoPost; // atribui o ponteiro novoPost ao ponteiro prox do nó duplicado

        if (ptAux->ant->num < ptAux->num) // se o nó duplicado estiver no inicio da lista
        {
            *ptLista = novoAnt; // atribui o ponteiro novoAnt ao ponteiro da lista
        }
    }
    else
    {
        ptLDEC *inicio = *ptLista;       // ponteiro auxiliar para inicio da lista
        ptLDEC *final = (*ptLista)->ant; // ponteiro auxiliar para final da lista

        *ptLista = (*ptLista)->prox;  // atribui o ponteiro prox ao ponteiro da lista
        (*ptLista)->ant = final->ant; // atribui o ponteiro livre ao ponteiro ant do ponteiro prox da lista
        final->ant->prox = *ptLista;  // atribui o ponteiro prox do ponteiro ant da lista ao ponteiro prox do ponteiro livre

        if (inicio == final)
        {
            free(inicio);
            *ptLista = NULL;
            return;
        }

        free(inicio); // libera a memória do nó
        free(final);  // libera a memória do nó
    }
}

void destroi(ptLDEC **ptLista)
{
    ptLDEC *aux; // Criamos um ponteiro auxiliar para percorrer a lista

    (*ptLista)->ant->prox = NULL; // Atribuimos NULL ao ponteiro prox do nó anterior ao primeiro nó da lista

    while (*ptLista != NULL) // Enquanto a lista não estiver vazia, percorremos a lista
    {
        aux = *ptLista;              // O ponteiro auxiliar aponta para o item atual da lista
        *ptLista = (*ptLista)->prox; // O ponteiro da lista aponta para o próximo item da lista
        free(aux);                   // Liberamos a memória do item atual da lista
    }

    *ptLista = NULL; // Retorna o ponteiro para NULL
}

void insere_normal(ptLDEC **ptLista, int valor)
{
    ptLDEC *novo = (ptLDEC *)malloc(sizeof(ptLDEC)); // aloca memória para o nó
    novo->num = valor;                               // atribui o valor ao nó

    if (*ptLista == NULL) // se a lista estiver vazia
    {
        *ptLista = novo;       // atribui o ponteiro novo ao ponteiro da lista
        novo->prox = *ptLista; // atribui o ponteiro da lista ao ponteiro prox do novo
        novo->ant = *ptLista;  // atribui o ponteiro da lista ao ponteiro ant do novo
        return;                // retorna
    }

    novo->prox = *ptLista;       // atribui o ponteiro da lista ao ponteiro prox do nó
    novo->ant = (*ptLista)->ant; // atribui o ponteiro ant do ant ao ponteiro ant do nó

    (*ptLista)->ant->prox = novo; // atribui o ponteiro prox do ant ao ponteiro prox do nó
    (*ptLista)->ant = novo;       // atribui o ponteiro novo ao ponteiro ant do ant
    return;                       // retorna
}