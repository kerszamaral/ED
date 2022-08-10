/* Ian Kersz - Cartão UFRGS: 00338368
11.08.22 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main(void)
{
    ABP *raiz = createABP();
    insertABP(&raiz, 10);
    insertABP(&raiz, 5);
    insertABP(&raiz, 15);
    insertABP(&raiz, 3);
    insertABP(&raiz, 7);
    insertABP(&raiz, 13);
    insertABP(&raiz, 17);

    displayABP(raiz, 'C');
    printf("\n\n\n");

    displayABP(raiz, 'L');
    printf("\n\n\n");

    displayABP(raiz, 'R');
    printf("\n\n\n");

    printf("%d\n", searchABP(raiz, 10));
    printf("%d\n", searchABP(raiz, 2));

    destroiABP(&raiz);
    
    return 0;
}