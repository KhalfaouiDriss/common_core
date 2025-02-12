#include "../push_swap.h"

void ft_sort_three(t_list **stack_a)
{
    t_list *max = ft_get_max(stack_a);
    if (max == *stack_a)
        ra(stack_a);
    else if (max == (*stack_a)->next)
        rra(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	lowest_pos = low_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
	printf("\nStack A (Sorted):\n");
	ft_printlst(*stack_a);
	printf("\nStack B:\n");
	ft_printlst(*stack_b);
	
    push_to_b(stack_a, stack_b);
    if (!is_sorted(stack_a))
		ft_sort_three(stack_a);
	printf("\nStack A (Sorted):\n");
	ft_printlst(*stack_a);
	printf("\nStack B:\n");
	ft_printlst(*stack_b);
    while (*stack_b)
    {
        target_position(stack_a, stack_b);
        cost_stack(stack_a, stack_b);
        best_moves(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
		shift_stack(stack_a);
    index_stuck(stack_b);
    index_stuck(stack_a);


}