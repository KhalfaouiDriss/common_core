#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int check_dup(char *str)
{
    int i = 0, j;

    while (str[i])
    {
        j =  i + 1;

        while (str[j])
        {
            if(str[i] == str[j])
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

void sorted(char *str)
{
    int i = 0, j, tmp;
    
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if(str[j] < str[i])
            {
                tmp = str[j];
                str[j] = str[i];
                str[i] = tmp;
            }
            j++;
        }
        i++;
    }
}

void generate(char *str, char *result, int *used, int dep, int len)
{
    if(dep == len)
    {
        write(1, result, len);
        write(1, "\n", 1);
        return ;
    }
    int i = 0;
    while (i < len)
    {
        if(!used[i])
        {
            used[i] = 1;
            result[dep] = str[i];
            generate(str, result, used, dep + 1, len);
            used[i] = 0;
        }
        i++;
    }
    
}


int main(int ac, char **av)
{
    if(ac != 2 || check_dup(av[1]))
        return 1;
    int len = ft_strlen(av[1]);
    char *result = malloc(len + 1);
    int *used = calloc(sizeof(int), len);
    if(!result || !used)
        return 1;
    sorted(av[1]);
    generate(av[1], result, used, 0, len);
    free(result);
    free(used);
}