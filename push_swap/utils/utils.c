#include "../push_swap.h"

void ft_error(char *msg)
{
    ft_putstr_fd(msg, 1);
    exit(0);
}

int is_sort(t_list **stuck)
{
    int i;
    t_list *tmp;

    tmp = *stuck;
    i = tmp->value;
    tmp = tmp->next;
    while (tmp)
    {
        if (i > tmp->value)
            return 0;
        i = tmp->value;
        tmp = tmp->next;
    }
    return 1;
}