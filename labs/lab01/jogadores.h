#ifndef jogadores_H_
#define jogadores_H_
/* Ian Kersz - Cartão UFRGS: 00338368
09.07.22
Implementação de uma TAD para armazenar dados de jogadores de futebol.

Interface da TAD:
*/

//Incluimos todas as bibliotecas necessárias para as funções do TAD
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//Criamos uma estrutura para armazenar os dados de um jogador
typedef struct Tjogadores {
    char nome[50];
    int idade;
    int num_gols;
    int num_faltas;
    int num_passes_errados;
    int num_passes_corretos;
    struct Tjogadores *prox;
} Jogadores;

Jogadores *atribui_dados(Jogadores *jogador); //Interface da função que atribui os dados de um jogador

void exibe_estatisticas(Jogadores *jogador); //Interface da função que exibe as estatísticas de um jogador

void eh_o_bom(Jogadores *jogador); //Interface da função que verifica se um jogador é bom ou não

Jogadores *destroi(Jogadores *jogador); // Interface da função que destroi a lista de jogadores

#endif