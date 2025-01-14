#include "../push_swap.h"

void ft_init_Stuck(t_list **a, char **av, int ac)
{
    int i = (ac == 2) ? 0 : 1;
    t_list *new;

    while (av[i])
    {
        int val = ft_atoi(av[i]);
        if (!is_digit(av[i]))
            ft_error("Invalid number");
        new = ft_lstnew(val);
        if (!new)
            ft_error("Memory allocation failed");
        ft_lstadd_back(a, new);
        i++;
    }
}


int	main(int ac, char **av)
{
    t_list	**a;
    t_list	**b;

    if (ac < 2)
        ft_error("args is empty");
    ft_check_args(ac, av);

    if (ac == 2)
        av = ft_split(av[1], ' ');

    a = (t_list **)malloc(sizeof(t_list *));
    b = (t_list **)malloc(sizeof(t_list *));
    if (!a || !b)
        ft_error("Memory allocation failed");
    *a = NULL;
    *b = NULL;

    ft_init_Stuck(a, av, ac);

    ft_printlst(*a);
    ft_putchar_fd('\n', 1);

    free_list(a);
    free_list(b);
    free(a);
    free(b);

    if (ac == 2)
        ft_split_free(av);

    return (0);
}

