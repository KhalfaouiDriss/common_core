/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/14 16:26:33 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:26:33 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*fill_stack_values(int ac, char **av)
{
	t_list	*stack_a;
	int		i;
	long	nb;

	stack_a = NULL;
	nb = 0;
	i = 0;
	if (ac > 2)
		i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error("error");
		if (!stack_a)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
