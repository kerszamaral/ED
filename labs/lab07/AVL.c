#include "AVL.h"

typedef int Typeinfo;

typedef struct AVL
{
    Typeinfo info;
    struct AVL *L;
    struct AVL *R;
    int k;
}AVL;

int insertABP(AVL **raiz, int info)
{
    if (*raiz == NULL) 
    {
        *raiz = (AVL *)malloc(sizeof(AVL)); //Aloca memoria para a raiz
        if(raiz == NULL)
        {
            return 0; //Retorna 0 para indicar que nao foi possivel alocar memoria
        }
        (*raiz)->info = info; //Insere o valor na raiz
        (*raiz)->L = NULL; //Insere NULL na esquerda
        (*raiz)->R = NULL; //Insere NULL na direita
        (*raiz)->k = 0;
        return 1;
    }
    else if (info < (*raiz)->info)
    {
        return insertABP(&((*raiz)->L), info); //Insere na esquerda
    }
    else if (info > (*raiz)->info)
    {
        return insertABP(&((*raiz)->R), info); //Insere na direita
    }
    else
    {
        return 0; //Retorna 0 para indicar que o valor ja existe na arvore
    }
}

int Factor(AVL *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return heightTree(root->L) - heightTree(root->R);
}

void _closestValue(AVL *root, int value, int *Closest)
{
    if (root == NULL)
    {
        return;
    }
    
    if (root->info == value)
    {
        *Closest = root->info;
        return;
    }

    if (root->info - *Closest < value - *Closest)
    {
        *Closest = root->info;
    }
    
    if (root->L != NULL)
    {
        _closestValue(root->L, value, Closest);
    }

    if (root->R != NULL)
    {
        _closestValue(root->R, value, Closest);
    }

    return;
}

int closestValue(AVL *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    int closest = root->info;
    _closestValue(root->L, value, &closest);
    _closestValue(root->R, value, &closest);
    return closest;
}

AVL *sRotateR(AVL *root)
{
    AVL *temp = root->L;
    root->L = temp->R;
    temp->R = root;
    root->k = 0;
    root = temp;
    return root;
}

AVL *sRotateL(AVL *root)
{
    AVL *temp = root->R;
    root->R = temp->L;
    temp->L = root;
    root->k = 0;
    root = temp;
    return root;
}

AVL *dRotateoR(AVL *root)
{
    AVL *temp = root->L;
    AVL *temp2 = temp->R;
    temp->R = temp2->L;
    temp2->L = temp;
    root->L = temp2->R;
    temp2->R = root;
    if (temp2->k == 1)
        root->k = -1;
    else
        root->k = 0;
    if (temp2->k == -1)
        temp->k = 1;
    else
        temp->k = 0;
    root = temp2;
    return root;
}

AVL *dRotateL(AVL *root)
{
    AVL *temp = root->R;
    AVL *temp2 = temp->L;
    temp->L = temp2->R;
    temp2->R = temp;
    root->R = temp2->L;
    temp2->L = root;
    if (temp2->k == -1)
        root->k = 1;
    else
        root->k = 0;
    if (temp2->k == 1)
        temp->k = -1;
    else
        temp->k = 0;
    root = temp2;
    return root;
}

AVL *Case1(AVL *root, int *ok)
{
    AVL *temp = root->L;
    if (temp->k == 1)
    {
        printf("Single Rotation Right\n");
        root = sRotateR(root);
    }
    else
    {
        printf("Double Rotation Right\n");
        root = dRotateoR(root);
    }
    root->k = 0;
    *ok = 0;
    return root;
}

AVL *Case2(AVL *root, int *ok)
{
    AVL *temp = root->R;
    if (temp->k == -1)
    {
        printf("Single Rotation Left\n");
        root = sRotateL(root);
    }
    else
    {
        printf("Double Rotation Left\n");
        root = dRotateL(root);
    }
    root->k = 0;
    *ok = 0;
    return root;
}

AVL *_insertAVL(AVL *root, Typeinfo info, int *ok)
{
    if (root == NULL)
    {
        root = (AVL *)malloc(sizeof(AVL));
        root->info = info;
        root->L = NULL;
        root->R = NULL;
        root->k = 0;
        *ok = 1;
    }
    else if (info < root->info)
    {
        root->L = _insertAVL(root->L, info, ok);
        if (*ok)
        {
            switch (root->k)
            {
            case -1:
                root->k = 0;
                *ok = 0;
                break;
            case 0:
                root->k = 1;
                break;
            case 1:
                root = Case1(root, ok);
                break;
            }
        }
    }
    else
    {
        root->R = _insertAVL(root->R, info, ok);
        if (*ok)
        {
            switch (root->k)
            {
            case 1:
                root->k = 0;
                *ok = 0;
                break;
            case 0:
                root->k = -1;
                break;
            case -1:
                root = Case2(root, ok);
                break;
            }
        }
    }
    return root;
}

int insertAVL(AVL **root, Typeinfo info)
{
    int ok = 0;
    *root = _insertAVL(*root, info, &ok);
    return ok;
}

int is_avl(AVL *a)
{
    int alt_esq, alt_dir;

    if (a != NULL)
    {
        alt_esq = heightTree(a->L);
        alt_dir = heightTree(a->R);
        return ((alt_esq - alt_dir < 2) && (alt_dir - alt_esq < 2) && (is_avl(a->L)) && (is_avl(a->R)));
    }
    else
        return 1;
}