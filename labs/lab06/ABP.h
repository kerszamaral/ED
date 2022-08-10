#ifndef ABP_H_
#define ABP_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct ABP ABP;

ABP *createABP(void);

int insertABP(ABP **raiz, int info);

int removeABP(ABP **raiz, int info);

int searchABP(ABP *raiz, int info);

int destroiABP(ABP **raiz);

int displayABP(ABP *raiz, char mode);

#endif