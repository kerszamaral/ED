#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Ttimes{
    char time[30];
    struct Ttimes *elo;
}times;

int main(void)
{
    times *t1;
    times *t2;
    times *t3;
    times *t4;
    t1 = NULL;
    if (t1 == NULL)
        printf("%p\n", t1);
    t1 = (times *)malloc(sizeof(times));
    t2 = (times *)malloc(sizeof(times));
    t3 = (times *)malloc(sizeof(times));
    t4 = (times *)malloc(sizeof(times));

    t1->elo = t2;
    t2->elo = t3;
    t3->elo = t4;

    strcpy(t1->time, "Inter");
    strcpy(t2->time, "Gremio");
    strcpy(t3->time, "Juventude");
    strcpy(t4->time, "Caxias");
    
    free(t1);
    free(t2);
    free(t3);
    free(t4);
    
    return 0;
}

// int main(void)
// {
//     int *p;
    
//     p = (int *)malloc(sizeof(int));
//     *p=123;
    
//     p = (int *)malloc(sizeof(int));
//     *p =456;
    
//     p = (int *)malloc(sizeof(int));
//     *p=789;
    
//     p = NULL;
    
//     return 0;
// }

// int main(){
//     int *p;
//     int i;

//     p = (int *)malloc(sizeof(int));

//     i=100;
//     *p=i;
//     i=40;
//     p=&i;
//     i=55;
//     free(p);
//     return 0;
// }