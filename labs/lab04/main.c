/* Ian Kersz - Cartão UFRGS: 00338368
00.03.22

in: 2 valores
out: 1 valor 
*/

#include "LSE.h"

int main(void)
{
    int num = -1;
    ptLSE *ptLista = NULL;

    print_list(ptLista);

    while (num !=0)
    {
        printf("Digite um valor para inserir no inicio da lista(0 para sair): ");
        scanf("%d", &num);
        if (num != 0)
        {
            insere_normal(&ptLista, num);
            print_list(ptLista);
        }
    }

    num = -1;
    while (num != 0)
    {
        printf("Digite um valor (0 para sair): ");
        scanf("%d", &num);
        if (num != 0)
        {
            insere(&ptLista, num);
            print_list(ptLista);
        }
    }
    
    print_list(ptLista);
    destroi(&ptLista); 
    print_list(ptLista);

    return 0;
}