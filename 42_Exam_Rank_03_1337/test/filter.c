#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_is_filter(char *line, char *filter, int i)
{
    int j;
    
    j = 0;
    while (line[i + j] && filter[j] && line[i + j] == filter[j])
        j++;
    if(!filter[j])
        return 1;
    return 0;
}

int print_filter(char *line, char *filter)
{
    int i, j, k;
    char c;

    c = '*';
    i = 0;
    while (line[i])
    {
        j = 0;
        if(check_is_filter(line, filter, i))
        {
            while (filter[j])
            {
                write(1, &c, 1);
                j++;
            }
            i += j; 
        }
        else
        {
            write(1, &line[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    char *line;
    int len;

    while (1)
    {
        line = malloc(1024);
        write(1, "srt: ", 5);
        len = read(0, line, 1024);
        line[len] = '\0';
        print_filter(line, av[1]);
        free(line);
    }
    
}