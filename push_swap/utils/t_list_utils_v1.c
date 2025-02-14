#include "../push_swap.h"
t_list *get_stack_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list *get_stack_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list *stack_new(int value)
{
	t_list *new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_bottom(t_list **stack, t_list *new)
{
	t_list *tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

int	get_stack_size(t_list *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}