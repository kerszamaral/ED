/* Ian Kersz - Cartão UFRGS: 00338368
09.07.22
Implementação de uma TAD para armazenar dados de jogadores de futebol.

Devido a não ser necessario no enunciado, a TAD foi implementada como uma lista encadeada sem nenhuma forma de apagar um jogador,
devido a isso, tambem não foi criado uma função para inserir um jogador no meio da lista nem no inicio, todos eles são adicionados ao final.

A implementação com conta 3 arquivos, "main.c", "jogadores.c" e "jogadores.h".
Main.c contem o codigo para o menu e acesso às funções.
Jogadores.c contem a implementação da TAD.
Jogadores.h contem a interface da TAD.

O trabalho foi feito e compilado no vscode em uma WSL, no windows 10. Acho que é possivel compilar o trabalho pelo terminal,
mas caso deseje está contido no arquivo .zip a pasta .vscode, que é utilizada para compilar o codigo, 
portanto, para compilar talvez seja simples como abrir a pasta do codigo no vscode e apertar f5.
*/

#include <stdio.h>
#include "jogadores.h"

int main(void)
{
    Jogadores *ptLista = NULL; //Inicializa o TAD vazio, a implementação é uma LSE, portante começamos com um ponteiro NULL

    while (1) //Criamos um loop infinito para servir de menu da nossa aplicação
    {
        int opcao; //Criamos uma variável para armazenar a opção do usuário e apresentamos elas com varios printfs
        printf("\n\n1 - Cadastrar jogador\n");
        printf("2 - Exibir estatisticas\n");
        printf("3 - Jogador eh bom?\n");
        printf("4 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao); //Lê a opção do usuário
        printf("\n");
        switch (opcao) //Com base na opção do usuario, utilizamos um switch para ir para a função desejada
        {
        case 1:
            ptLista = atribui_dados(ptLista); //Chamamos a função atribui_dados para cadastrar um novo jogador
            break;
        case 2:
            exibe_estatisticas(ptLista); //Chamamos a função exibe_estatisticas para exibir as estatisticas de todos os jogadores
            break;
        case 3:
            eh_o_bom(ptLista); //Chamamos a função eh_o_bom para verificar se um jogador eh bom
            break;
        case 4: //Caso a opção seja 4, o programa termina
            return 0;
        default:
            printf("Opcao invalida!\n"); //Caso o usuário digite uma opção inválida, exibimos um erro
            break;
        }
    }
    ptLista = destroi(ptLista); //Chamamos a função destroi para liberar toda a memória alocada para o TAD
}