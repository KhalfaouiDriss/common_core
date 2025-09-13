#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int filter(char *filt, int len)
{
    int i = 0, j, l;
    char h;
    char str[10000];

    while (l = read(0, &h, 1) > 0)
    {
        str[i] = h;
        i++;
    }
    str[i] = '\0';
    i = 0;
    while (str[i])
    {
        if(!strncmp(&str[i], filt, len))
        {
            j = 0;
            while (j < len)
            {
                str[i] = '*';
                j++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("%s", str);
    return 0;
}

int main(int ac, char **av)
{

    if(ac == 2)
    {
        if(filter(av[1], strlen(av[1])))
            return 1;
        return 0;
    }
    return 1;
}