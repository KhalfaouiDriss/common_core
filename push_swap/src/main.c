#include "../push_swap.h"


void swap_to_b(t_list **stuck_a, t_list **stuck_b)
{
    int med = ((*stuck_a)->list_size / 2) + 1;
    int i;
    t_list *tmp;

    i = 1;
    while(i <= 1)
    {
        tmp = *stuck_a;
        if(tmp->index <= med)
        {
            pb(stuck_a, stuck_b, tmp->index);
            i++;
        }
        // else
        // {
        //     ra()
        // }
    }
    index_stuck(stuck_a);
    index_stuck(stuck_b);
}



void push_swap(t_list **stuck_a, t_list **stuck_b)
{
    index_stuck(stuck_a);
    while(!is_sort(stuck_a))
    {
        swap_to_b(stuck_a, stuck_b);

        ft_putstr_fd("\n not sorted\n", 1);
        return;
    }
    ft_error("stuck a is sorted\n");
    return;
}

int	main(int ac, char **av)
{
    t_list	**a;
    t_list	**b;

    if (ac < 2)
        ft_error("args is empty\n");
    ft_check_args(ac, av);

    if (ac == 2)
        av = ft_split(av[1], ' ');

    a = (t_list **)malloc(sizeof(t_list *));
    b = (t_list **)malloc(sizeof(t_list *));
    if (!a || !b)
        ft_error("Memory allocation failed\n");
    *a = NULL;
    *b = NULL;

    ft_init_Stuck(a, av, ac);
    push_swap(a, b);


    printf("\n stuck a");
    ft_printlst(*a);
    printf("\n stuck b");
    ft_printlst(*b);
    ft_putchar_fd('\n', 1);
    free_list(a);
    free_list(b);
    free(a);
    free(b);

    if (ac == 2)
        ft_split_free(av);

    return (0);
}

