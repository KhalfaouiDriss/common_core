# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


void *rot(void *i)
{
    int lock;

   while (1)
   {
        lock = 0;
        while(lock){};

        *(int *)i += 1;
        sleep(2);
        lock = 1;
        printf("fnish\n");
   }
   
}

int main()
{
    pthread_t td[2];
    int i = 0;
    pthread_create(&td[0], NULL, rot, (void *)&i);
    pthread_create(&td[1], NULL, rot, (void *)&i);
    
    while (1)
    {
        printf("%d\n", i);
        sleep(2);
    }

}