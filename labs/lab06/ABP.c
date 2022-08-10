#include "ABP.h"

typedef struct ABP
{
    int info;
    ABP *L;
    ABP *R;
} ABP;

ABP *createABP(void)
{
    return NULL;
}

int insertABP(ABP **raiz, int info)
{
    if (*raiz == NULL)
    {
        *raiz = (ABP *)malloc(sizeof(ABP));
        (*raiz)->info = info;
        (*raiz)->L = NULL;
        (*raiz)->R = NULL;
        return 1;
    }
    else if (info < (*raiz)->info)
    {
        return insertABP(&((*raiz)->L), info);
    }
    else if (info > (*raiz)->info)
    {
        return insertABP(&((*raiz)->R), info);
    }
    else
    {
        return 0;
    }
}

int removeABP(ABP **raiz, int info)
{
    return 0;
}

int searchABP(ABP *raiz, int info)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (info == raiz->info)
    {
        return 1;
    }

    if (info < raiz->info)
    {
        return searchABP(raiz->L, info);
    }
    else if (info > raiz->info)
    {
        return searchABP(raiz->R, info);
    }
    else
    {
        return 0;
    }
}

int destroiABP(ABP **raiz)
{
    if (*raiz != NULL)
    {
        destroiABP(&((*raiz)->L));
        destroiABP(&((*raiz)->R));
        free(*raiz);
        *raiz = NULL;
        return 1;
    }
    return 0;
}

void printABP(ABP *raiz, int level)
{
    if(raiz != NULL)
    {
        for (int i = 0; i < level; i++)
        {
            printf("---");
        }
        printf("%d\n", raiz->info);
    }
}

int displayABPNum(ABP *raiz, char mode, int level)
{
    level++;
    if (raiz == NULL)
    {
        return 0;
    }

    if (mode == 'L')
    {
        displayABPNum(raiz->L, mode, level);
        printABP(raiz, level);
        displayABPNum(raiz->R, mode, level);
    }
    else if (mode == 'R')
    {
        displayABPNum(raiz->R, mode, level);
        printABP(raiz, level);
        displayABPNum(raiz->L, mode, level);
    }
    else
    {
        printABP(raiz, level);
        displayABPNum(raiz->L, mode, level);
        displayABPNum(raiz->R, mode, level);
    }
    return 1;
}

int displayABP(ABP *raiz, char mode)
{
    int level = 0;
    if (raiz == NULL)
    {
        return 0;
    }

    if (mode == 'L')
    {
        displayABPNum(raiz->L, mode, level);
        printABP(raiz, level);
        displayABPNum(raiz->R, mode, level);
    }
    else if (mode == 'R')
    {
        displayABPNum(raiz->R, mode, level);
        printABP(raiz, level);
        displayABPNum(raiz->L, mode, level);
    }
    else
    {
        printABP(raiz, level);
        displayABPNum(raiz->L, mode, level);
        displayABPNum(raiz->R, mode, level);
    }
    return 1;
}
