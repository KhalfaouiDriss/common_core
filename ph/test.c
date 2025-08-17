// #include "philo.h"

// typedef struct test
// {
//     pthread_t th;
//     int *i;
//     pthread_mutex_t *m;
// } t_test;

// void *rot1(void *t)
// {
//     t_test *th = (t_test *)t;
//     pthread_mutex_lock(th->m);
//     while (*(th->i) < 100000000)
//         (*(th->i))++;
//     // printf("done 1 || i : %d\n", *(th->i));
//     pthread_mutex_unlock(th->m);
// }

// void *rot2(void *t)
// {
//     t_test *th = (t_test *)t;
//     pthread_mutex_lock(th->m);
//     while (*(th->i) > 0)
//         (*(th->i))--;
//     // printf("done 2 || i : %d\n", *(th->i));
//     pthread_mutex_unlock(th->m);
// }

// int main()
// {
//     int i = 0;
//     t_test th1;
//     t_test th2;
//     pthread_mutex_t m;

//     pthread_mutex_init(&m, NULL);
//     th1.i = &i;
//     th2.i = &i;
//     th1.m = &m;
//     th2.m = &m;
//     pthread_create(&th1.th, NULL, rot1, (void *)&th1);
//     usleep(100);
//     pthread_create(&th2.th, NULL, rot2, (void *)&th2);
    
//     pthread_join(th1.th, NULL);
//     pthread_join(th2.th, NULL);

//     printf("i : %d\n", i);
// }