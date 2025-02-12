#include "../push_swap.h"

void	cost_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->place;
		if (tmp_b->place > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->place) * -1;
		tmp_b->cost_a = tmp_b->target_place;
		if (tmp_b->target_place > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_place) * -1;
		tmp_b = tmp_b->next;
	}
}

void	best_moves(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}