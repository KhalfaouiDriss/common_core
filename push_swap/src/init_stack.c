#include "../push_swap.h"

void ft_init_Stuck(t_list **a, char **av, int ac)
{
    int i = (ac == 2) ? 0 : 1;
    t_list *new;

    while (av[i])
    {
        int val = ft_atoi(av[i]);
        if(val > INT_MAX || val < INT_MIN)
            ft_error("Invalid number (not in int range)\n");
        if (!is_digit(av[i]))
            ft_error("Invalid number\n");
        new = ft_lstnew(val);
        if (!new)
            ft_error("Memory allocation failed\n");
        ft_lstadd_back(a, new);
        i++;
    }
}