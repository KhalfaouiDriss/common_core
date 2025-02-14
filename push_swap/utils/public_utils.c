#include "../push_swap.h"

void ft_error(char *msg)
{
    ft_putstr_fd(msg, 1);
    exit(0);
}

void ft_split_free(char **split)
{
    int i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
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

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}