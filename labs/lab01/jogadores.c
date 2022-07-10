/* Ian Kersz - Cartão UFRGS: 00338368
09.07.22
Implementação de uma TAD para armazenar dados de jogadores de futebol.

Implementação da TAD:
*/

#include "jogadores.h"

Jogadores *atribui_dados(Jogadores *jogador)
{
    if (jogador == NULL) //Testamos se a TAD está vazia, caso sim criamos o primeiro item
    {
        jogador = (Jogadores *)malloc(sizeof(Jogadores)); //Alocamos memória para o primeiro item da lista
        jogador->prox = NULL; //O primeiro item da lista aponta para NULL
    }
    else //Caso a lista não esteja vazia criamos um novo item ao final dela
    {
        Jogadores *aux = jogador; //Criamos um ponteiro auxiliar para percorrer a lista
        while (aux->prox != NULL) //Enquanto o ponteiro auxiliar não apontar para NULL, percorremos a lista
        {
            aux = aux->prox; //O ponteiro auxiliar aponta para o próximo item da lista
        }
        aux->prox = (Jogadores *)malloc(sizeof(Jogadores)); //Alocamos memória para o novo item da lista
        aux = aux->prox; //O ponteiro auxiliar aponta para o novo item da lista
        aux->prox = NULL; //O novo item da lista aponta para NULL
    }

    Jogadores *aux = jogador; //Criamos um ponteiro auxiliar para percorrer a lista
    while (aux->prox != NULL) // Enquanto o ponteiro auxiliar não apontar para NULL, percorremos a lista
    {
        aux = aux->prox; // O ponteiro auxiliar aponta para o próximo item da lista
    }
    printf("Digite o nome do jogador: "); //Lê o nome do jogador
    scanf("%s", aux->nome);
    printf("Digite a idade do jogador: "); //Lê a idade do jogador
    scanf("%d", &aux->idade);
    printf("Digite o numero de gols do jogador: "); //Lê o número de gols do jogador
    scanf("%d", &aux->num_gols);
    printf("Digite o numero de faltas do jogador: "); //Lê o número de faltas do jogador
    scanf("%d", &aux->num_faltas);
    printf("Digite o numero de passes errados do jogador: "); //Lê o número de passes errados do jogador
    scanf("%d", &aux->num_passes_errados);
    printf("Digite o numero de passes corretos do jogador: "); //Lê o número de passes corretos do jogador
    scanf("%d", &aux->num_passes_corretos);
    printf("\n");

    return jogador; //Retorna o ponteiro para o primeiro item da lista de jogadores
}

void exibe_estatisticas(Jogadores *jogador)
{
    if (jogador == NULL) //Testa se a lista não está vazia
    {
        printf("Lista vazia!\n");
        return;
    }
    
    Jogadores *ptAux = jogador; //Criamos um ponteiro auxiliar para percorrer a lista
    while (1)
    {
        printf("Nome do jogador: %s\n", ptAux->nome); //Exibe o nome do jogador
        printf("Idade do jogador: %d\n", ptAux->idade); //Exibe a idade do jogador
        printf("Numero de gols do jogador: %d\n", ptAux->num_gols); //Exibe o número de gols do jogador
        printf("Numero de faltas do jogador: %d\n", ptAux->num_faltas); //Exibe o número de faltas do jogador
        printf("Porcentagem de passes corretos: %d\n\n", ptAux->num_passes_corretos / (ptAux->num_passes_errados + ptAux->num_passes_corretos)); //Exibe a porcentagem de passes corretos do jogador
        if (ptAux->prox == NULL) //O loop roda até o final da lista, que é quando o item atual aponta para NULL
        {
            break;
        }
        ptAux = ptAux->prox; //O ponteiro auxiliar aponta para o próximo item da lista
    }
    
    return;
}

void eh_o_bom(Jogadores *jogador)
{
    if (jogador == NULL) //Testa se a lista não está vazia
    {
        printf("Lista vazia!\n");
        return;
    }
    printf("Digite o nome do jogador: "); //Lê o nome do jogador
    char nome[50];
    scanf("%s", nome); //Pega a Input
    
    Jogadores *ptAux = jogador; //Criamos um ponteiro auxiliar para percorrer a lista
    while (1)
    {
        if (strcmp(ptAux->nome, nome) == 0) //Testa se o nome do jogador é o mesmo que o digitado
        {
            printf("O jogador eh bom? "); //Exibe a mensagem de pergunta

            if (ptAux->num_passes_corretos / (ptAux->num_passes_errados + ptAux->num_passes_corretos) > 0.5 && ptAux->num_faltas > 2) //Testa se o jogador "eh bom"
            {
                printf("Sim"); //Exibe a mensagem de resposta
            }
            else
            {
                printf("Nao"); //Exibe a mensagem de resposta
            }
            
            break; //Sai do loop
        }
        if (ptAux->prox == NULL) //O loop roda até o final da lista, que é quando o item atual aponta para NULL
        {
            printf("Jogador nao encontrado!\n"); //Exibe a mensagem de erro
            break;
        }
        ptAux = ptAux->prox; //O ponteiro auxiliar aponta para o próximo item da lista
    }
}

Jogadores *destroi(Jogadores *jogador)
{
    Jogadores *ptAux; //Criamos um ponteiro auxiliar para percorrer a lista
    while (jogador != NULL) //Enquanto a lista não estiver vazia, percorremos a lista
    {
        ptAux = jogador; //O ponteiro auxiliar aponta para o item atual da lista
        jogador = jogador->prox; //O ponteiro da lista aponta para o próximo item da lista
        free(ptAux); //Liberamos a memória do item atual da lista
    }
    return NULL; //Retorna o ponteiro para NULL
}