#include <unistd.h>
#include <stdio.h>

int main()
{

    char *s = "driss";

    int *g = (int *)s;

    printf("%s\n", (char *)g);
}