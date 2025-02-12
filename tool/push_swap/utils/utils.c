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

int is_digit(char *num)
{
    int i;

    if (!num || !*num)
        return (0); 
    i = 0;
    if (num[0] == '-')
        i++;
    while (num[i])
    {
        if (num[i] < '0' || num[i] > '9')
            return (0); 
        i++;
    }
    return (1);
}

t_list *ft_get_max(t_list **stack)
{
    if (!stack || !*stack)
        return NULL;
    t_list *tmp = *stack;
    t_list *max = *stack;
    while (tmp)
    {
        if (tmp->index > max->index)
            max = tmp;
        tmp = tmp->next;
    }
    return max;
}

int nb_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}

int ft_count_args(char **args)
{
    int count = 0;

    while (args[count])
        count++;
    
    return count;
}
