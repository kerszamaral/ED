/* Ian Kersz - Cartão UFRGS: 00338368
14.07.22
Implementação de uma Lista Simples Encadeada em C. O programa deixa voce entrar com um valor e a lista vai adicionando o valor no inicio lista.
Após sair dessa função, o solicitado pela atividade acontece, outro loop que insere e remove da lista.
Caso a lista estiver vazia, ela adiciona o numero ao inicio da lista.
Caso contrario, ela busca se o numero está na lista e, se estiver, adiciona o numero-1 e o numero+1 na posição anterior e posterior de onde o valor foi encontrado.
Caso não esteja, ela remove o primeiro e o ultimo elemento da lista.
*/

#include "LSE.h"

int main(void)
{
    int num = -1;
    ptLSE *ptLista = NULL;

    while (num !=0)
    {
        print_list(ptLista);
        printf("Digite um valor para inserir no inicio da lista(0 para sair): ");
        scanf("%d", &num);
        if (num != 0)
            insere_normal(&ptLista, num);
    }

    num = -1;
    while (num != 0)
    {
        print_list(ptLista);
        printf("Digite um valor (0 para sair): ");
        scanf("%d", &num);
        if (num != 0)
            insere(&ptLista, num);
    }
    
    print_list(ptLista);
    destroi(&ptLista); 
    print_list(ptLista);

    return 0;
}