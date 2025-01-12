#include "push_swap.h"

int is_digit(char const *s)
{
    int i = 0;

    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int islst_digit(char **s)
{
    int i = 0;

    while (s[i])
    {
        int k = 0;
        while (s[i][k])
        {
            if (!(s[i][k] >= '0' && s[i][k] <= '9'))
            {
                return 0;
            }
            k++;
        }
        i++;
    }
    return 1;
}


int main(int ac, char **av)
{
    t_list *a = NULL;
    t_list *b = NULL;

    if (ac == 1 || (ac == 2 && !av[1]))
    {
        printf("Error\n");
        return 0;
    }
    else if (ac == 2)
    {
        if (is_digit(av[1]) == 0)
        {
            printf("Error\n");
            return 0;
        }
        av = ft_split(av[1], ' ');
    }
    if (islst_digit(av) == 0)
    {
        printf("Error\n");
        if (ac == 2)
        {
            int i = 0;
            while (av[i])
                free(av[i++]);
            free(av);
        }
        return 0;
    }

    if (ac > 2)
        av++;

    fill_stuck(&a, av);
    ft_printlst(a);    
    printf("\n");

    free_list(&a);
    free_list(&b);


    if (ac == 2)
    {
        int i = 0;
        while (av[i])
            free(av[i++]);
        free(av);
    }

    return 0;
}
