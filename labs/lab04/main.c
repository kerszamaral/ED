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
    int num = -1; //numero a ser inserido na lista
    ptLSE *ptLista = criaLista(); //cria a lista

    while (num !=0) //loop que pede o numero a ser inserido na lista
    {
        print_list(ptLista); //imprime a lista
        printf("Digite um valor para inserir no inicio da lista(0 para sair): "); //pede o numero a ser inserido na lista
        scanf("%d", &num); //pega o numero a ser inserido na lista
        if (num != 0) //se o numero nao for 0, insere o numero na lista
            insere_normal(&ptLista, num); //insere o numero na lista
    }

    num = -1; //numero a ser removido da lista
    while (num != 0) //loop que faz a função maluca lá
    {
        print_list(ptLista); //imprime a lista
        printf("Digite um valor (0 para sair): "); //pede o numero a ser inserido na função maluca
        scanf("%d", &num); // pega o numero a ser inserido na função maluca
        if (num != 0) //Testa se o numero nao for 0
            insere(&ptLista, num); //Executa a função
    }
    print_list(ptLista); //imprime a lista
    destroi(&ptLista);  //destroi a lista
    print_list(ptLista); //imprime a lista

    return 0;
}