#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// int primes[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17};

int global_fct(int blo)
{
	static int p;

	if(blo)
        p = blo;
	return p;
}

void routine()
{
    printf("%d\n", global_fct(0));
}
int main()
{
    global_fct(4);
    routine();
}