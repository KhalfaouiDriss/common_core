#include "../push_swap.h"

void ft_error(char *msg)
{
    ft_putstr_fd(msg, 1);
    exit(0);
}

int is_sorted(t_list **stack)
{
    t_list *tmp = *stack;

    while (tmp && tmp->next)
    {
        if (tmp->index > tmp->next->index)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}