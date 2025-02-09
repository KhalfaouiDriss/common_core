#include "../push_swap.h"

int calc_chunk_size(t_list *stack)
{
    int i = 0;
    if(ft_lstsize(stack) <= 10)
        i = 2;
    else if(ft_lstsize(stack) <= 200)
        i = 4;
    else
        i = 8;
    return i;
}

t_list	*ft_get_max(t_list **a)
{
	t_list	*tmp;
	t_list	*max;

	if (!*a)
		return (NULL);
	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void push_to_b(t_list **stack_a, t_list **stack_b)
{
    int parts = calc_chunk_size(*stack_a);
    int size = ft_lstsize(*stack_a);
    int size_part = size / parts; 
    int limit = size_part;        

    while (ft_lstsize(*stack_a) > 3)
    {
        int count = 0;
        
        while (count < size_part && ft_lstsize(*stack_a) > 3)
        {
            if ((*stack_a)->index <= limit)
            {
                pb(stack_a, stack_b);
                count++;
            }
            else
                ra(stack_a);
            }
            
            limit += size_part;
        }
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*max;

	max = ft_get_max(stack_a);
	if (max == *stack_a)
		ra(stack_a);
	else if (max == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

// void swap_to_a(t_list **stack_a, t_list **stack_b)
// {
//     t_list *tmp;

// }

void push_swap(t_list **stack_a, t_list **stack_b)
{
    push_to_b(stack_a, stack_b);
    printf("\nStack A (Sorted):\n");
    ft_printlst(*stack_a);
    // printf("\nStack B:\n");
    // ft_printlst(*stack_b);
    if(!is_sorted(stack_a))
        ft_sort_three(stack_a);
    // push_to_a(stack_a, stack_b);
    index_stuck(stack_a);
    // index_stuck(stack_b);
}

int main(int ac, char **av)
{
    t_list **a = (t_list **)malloc(sizeof(t_list *));
    t_list **b = (t_list **)malloc(sizeof(t_list *));

    if (!a || !b)
        ft_error("Memory allocation failed\n");

    *a = NULL;
    *b = NULL;

    if (ac < 2)
        ft_error("args is empty\n");

    ft_check_args(ac, av);

    if (ac == 2)
        av = ft_split(av[1], ' ');

    ft_init_Stuck(a, av, ac);
    index_stuck(a);

    push_swap(a, b);

    printf("\nStack A (Sorted):\n");
    ft_printlst(*a);
    printf("\nStack B:\n");
    ft_printlst(*b);

    free_list(a);
    free_list(b);
    free(a);
    free(b);

    if (ac == 2)
        ft_split_free(av);

    return 0;
}
