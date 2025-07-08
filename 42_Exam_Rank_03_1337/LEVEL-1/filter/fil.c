#include <stdio.h>
#include <unistd.h>
 #include <fcntl.h>
 #include <stdlib.h>
#include <string.h>

char *filtere(char *line, char *filter)
{
    int i = 0, j = 0, k = 0;
    char *str = malloc(strlen(line) + 1);
cd
    while(line[i])
    {
        printf("========\n");
        if(line[i] == filter[0])
        {
            j = 0;
            k = i;
            while(line[i] && filter[j] && line[i] == filter[j])
            {
                i++;
                j++;
            }
            if(!filter[j])
            {
                i = k;
                j = 0;
                while(filter[j])
                {
                    str[i] = '*';
                    i++;
                    j++;
                }
            }
            else
            {
                i = k;
            }
        }
        else
        {
            str[i] = line[i];
            i++;
        }
    }
    str[i] = '\0';
    // printf("str : %s\n", str);
    return str;
}

int main(int ac, char **av)
{
    char line[10];
    char *str;
    int j = 0;
    int i = read(0, line, 10);
    line[i - 1] = '\0';

    str = filtere(line, av[1]);
    printf("%s\n", str);
    // while(i)
    // {
    //     write(1, &line[j], 1);
    //     j++;
    //     i--;
    // }
}