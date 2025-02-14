#include "../push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
    int stack_size;

    stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2 && !is_sorted(*stack_a))
        sa(stack_a);
	else if (stack_size == 3)
        sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int main(int ac, char **av)
{
    t_list *a;
    t_list *b;

    if (ac < 2)
        ft_error("args is empty\n");
    ft_check_args(ac, av);
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        if (!av)
            ft_error("Memory allocation failed for arguments\n");
    }

    a = fill_stack_values(ac, av);
    index_stack(a);
    push_swap(&a, &b);
    // printf("Stack A\n");
    // ft_printlst(a);
    // printf("Stack B\n");
    // ft_printlst(b);
    if (ac == 2)
        ft_split_free(av);
    free_stack(&a);
    free_stack(&b);
}