/* Ian Kersz - Cartão UFRGS: 00338368
11.08.22
Implementação de uma ABP e diversas funções relacionadas para o Lab 06.
*/

#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

void menuUmaArv(AVL **raiz);

int main(void)
{
    AVL *arv1 = createTree(); // Cria arvore1 vazia
    menuUmaArv(&arv1); // Menu para arvore1

    arv1 = destroyTree(arv1); // Destroi arvore1
    return 0;
}

void menuUmaArv(AVL **raiz)
{
    while (1)
    {
        // Criação das opções do menu
        printf("\n\n1 - Inserir\n");
        printf("2 - Imprimir\n");
        printf("3 - Procurar e Retornar fator\n");
        printf("4 - Destroi\n");
        printf("5 - Contruir Arvore Positiva\n");
        printf("6 - É AVL\n");
        printf("7 - Valor mais proximo\n");
        printf("8 - Sair\n");
        printf("Digite uma opção: ");
        int opcao = -1;
        int valor = -1;
        scanf("%d", &opcao); // Leitura da opção
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
            printf("\n1 - Pre-Fixado Esquerdo\n");
            printf("2 - Pre-Fixado Direito\n");
            printf("3 - Pos-Fixado Esquerdo\n");
            printf("4 - Pos-Fixado Direito\n");
            printf("5 - Central Esquerdo\n");
            printf("6 - Central Direito\n");
            printf("Digite o modo de impressão: ");
            scanf("%d", &valor); // Leitura do modo de impressão
            displayTree(*raiz, valor);
            break;
        case 3:
            printf("\nDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            AVL *temp = searchTree(*raiz, valor);
            if (temp == NULL)
            {
                printf("\nValor não encontrado\n");
            }
            else
            {
                printf("\nFator do nó: %d\n", Factor(temp));
            }
            break;
        case 4:
            *raiz = destroyTree(*raiz);
            if (*raiz == NULL)
            {
                printf("\nÁrvore destruída com sucesso!\n");
            }
            else
            {
                printf("\nÁrvore não destruída!\n");
            }
            break;
        case 5:
            do // Função criada para criar arvores positivas grandes mais facilmente
            {
                printf("\nDigite o valor a ser inserido (Zero ou Negativo para sair): ");
                scanf("%d", &valor);
                if (valor > 0)
                {
                    insertABP(raiz, valor);
                    displayTree(*raiz, 1);
                }
            } while (valor > 0);
            break;
        case 6:
            if (is_avl(*raiz))
            {
                printf("\nArvore é uma AVL\n");
            }
            else
            {
                printf("\nArvore não é uma AVL\n");
            }
            break;
        case 7:
            printf("\nDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            printf("\nValor mais proximo: %d\n", closestValue(*raiz, valor));
            break;
        case 8:
            return; // Sair do menu
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    }
}