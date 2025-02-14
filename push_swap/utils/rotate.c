#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
