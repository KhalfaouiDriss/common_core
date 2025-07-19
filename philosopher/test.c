# include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct test
{
    int l;
    int k;
} t_test;


void mtx_lock(int *l)
{
    if(*l)
        while (*l)
            ;
    if(!(*l))
        *l = 1;
}

void mtx_unlock(int *l)
{
    *l = 0; 
}

void *rot(void *test)
{
    int i = 0, j = 0, k;
    t_test *tt = (t_test *)test;
    // pthread_mutex_lock((pthread_mutex_t *)m);
    mtx_lock(&tt->l);
    while(i <= 10)
    {
        printf("th[%d] : %d\n", tt->k, j);
        j++;
        i++;
        sleep(1);           
    }
     mtx_unlock(&tt->l);
}

int main()
{
    pthread_t th[6];
    pthread_mutex_t m;
    
    pthread_mutex_init(&m, NULL);
    t_test test;
    test.l = 0;
    test.k = 0;
    test.k++;
    pthread_create(&th[0], NULL, rot, (void *)&test);
    test.k++;
    pthread_create(&th[1], NULL, rot, (void *)&test);
    test.k++;
    pthread_create(&th[2], NULL, rot, (void *)&test);
    test.k++;
    pthread_create(&th[3], NULL, rot, (void *)&test);
    test.k++;
    pthread_create(&th[4], NULL, rot, (void *)&test);
    test.k++;
    pthread_create(&th[5], NULL, rot, (void *)&test);
    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    pthread_join(th[2], NULL);
    pthread_join(th[3], NULL);
    pthread_join(th[4], NULL);
    pthread_join(th[5], NULL);
}