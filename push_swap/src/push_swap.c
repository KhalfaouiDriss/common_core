/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:27:23 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:27:23 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		ft_error("Error: No arguments provided.\n");
	ft_check_args(ac, av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			ft_error("Error: Memory allocation failed for arguments.\n");
	}
	a = fill_stack_values(ac, av);
	b = NULL;
	index_stack(a);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
