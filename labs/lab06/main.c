/* Ian Kersz - Cartão UFRGS: 00338368
11.08.22 
Implementação de uma ABP e diversas funções relacionadas para o Lab 06.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

void menuUmaArv(ABP **raiz);

void menuDuasArv(ABP **raiz, ABP **raiz2);

int main(void)
{
    ABP *arv1 = createABP(); // Cria arvore1 vazia
    ABP *arv2 = createABP(); // Cria arvore2 vazia
    while (1)
    {
        printf("\n\n1 - Operação na Arvore1\n");
        printf("2 - Operação na Arvore2\n");
        printf("3 - Operação nas duas Arvores\n");
        printf("4 - Sair\n");
        printf("Escolha qual operação deseja realizar: ");
        int op;
        scanf("%d", &op); // Escolha da operação
        switch (op)
        {
        case 1:
            menuUmaArv(&arv1);
            break;
        case 2:
            menuUmaArv(&arv2);
            break;
        case 3:
            menuDuasArv(&arv1, &arv2);
            break;
        case 4:
            destroiABP(&arv1); // Destroi arvore1
            destroiABP(&arv2); // Destroi arvore2
            return 0; // Sai do programa
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }

    return 0;
}

void menuUmaArv(ABP **raiz)
{
    while(1)
    {
        //Criação das opções do menu
        printf("\n\n1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Procurar\n");
        printf("5 - Destroi\n");
        printf("6 - Contruir Arvore Positiva\n");
        printf("7 - Testar ABP\n");
        printf("8 - Construir Arvore ao Contrario\n");
        printf("9 - Sair\n");
        printf("Digite uma opção: ");
        int opcao = -1;
        int valor = -1;
        scanf("%d", &opcao); //Leitura da opção
        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            if (insertABP(raiz, valor)) 
            {
                printf("\nValor inserido com sucesso!\n");
            }
            else
            {
                printf("\nValor não inserido!\n");
            }
            break;
        case 2:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &valor);
            if (removeABP(raiz, valor))
            {
                printf("\nValor removido com sucesso!\n");
            }
            else
            {
                printf("\nValor não encontrado!\n");
            }
            break;
        case 3:
            printf("\n1 - Pre-Fixado Esquerdo\n");
            printf("2 - Pre-Fixado Direito\n");
            printf("3 - Pos-Fixado Esquerdo\n");
            printf("4 - Pos-Fixado Direito\n");
            printf("5 - Central Esquerdo\n");
            printf("6 - Central Direito\n");
            printf("Digite o modo de impressão: ");
            scanf("%d", &valor); //Leitura do modo de impressão
            displayABP(*raiz, valor);
            break;
        case 4:
            printf("\nDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            if (searchABP(*raiz, valor) == NULL)
            {
                printf("\nValor não encontrado\n");
            }
            else
            {
                printf("\nValor encontrado\n");
            }
            break;
        case 5:
            if (destroiABP(raiz))
            {
                printf("\nÁrvore destruída com sucesso!\n");
            }
            else
            {
                printf("\nÁrvore não destruída!\n");
            }
            break;
        case 6:
            do // Função criada para criar arvores positivas grandes mais facilmente
            {
                printf("\nDigite o valor a ser inserido (Zero ou Negativo para sair): ");
                scanf("%d", &valor);
                if (valor > 0)
                {
                    insertABP(raiz, valor);
                    displayABP(*raiz, 1);
                }
            } while (valor > 0);
            break;
        case 7:
            if(isABP(*raiz))
            {
                printf("\nArvore é uma ABP\n");
            }
            else
            {
                printf("\nArvore não é uma ABP\n");
            }
            break;
        case 8:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            if (insertMirrorABP(raiz, valor))
            {
                printf("\nValor inserido com sucesso!\n");
            }
            else
            {
                printf("\nValor não inserido!\n");
            }
            break;
        case 9:
            return; //Sair do menu
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
}

void menuDuasArv(ABP **arv1, ABP **arv2)
{
    while (1)
    {
        printf("\n\n1 - Comparar\n"); //Comparação de ABPs
        printf("2 - Copia Espelhada (arv1 -> arv2)\n"); //Copia espelhada de arv1 para arv2
        printf("3 - Sair\n");
        printf("Digite uma opção: ");
        int opcao = -1;
        scanf("%d", &opcao); //Leitura da opção
        switch (opcao)
        {
        case 1:
            if (compareABP(*arv1, *arv2))
            {
                printf("\nArvores iguais!\n");
            }
            else
            {
                printf("\nArvores diferentes!\n");
            }
            break;
        case 2:
            if (mirrorABP(*arv1, arv2))
            {
                printf("\nArvore copiada com sucesso!\n");
                printf("\nArvore 1:\n");
                displayABP(*arv1, 1);
                printf("\nArvore 2:\n");
                displayABP(*arv2, 1);
            }
            else
            {
                printf("\nArvore não copiada!\n");
            }
            break;
        case 3:
            return;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
}