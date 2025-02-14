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

int find_nb(char **str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count(char **av)
{
	int i;
	int j;
	char **test;

	i = 0;
	j = 0;
	while (av[i])
	{
		test = ft_split(av[i++], ' ');
		j += find_nb(test);
		ft_split_free(test);
	}
	return(j);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char **sp;
	char **args;
	int		i;
	int		j;
	int		k;

	if (ac < 2)
		ft_error("Error: No arguments provided.\n");
		i = 1;
		j = 0;
		args = malloc(count(av) * 8);
		while (i < ac)
		{
			k = 0;
			sp = ft_split(av[i++], ' ');
			if (!sp)
			ft_error("Error: Memory allocation failed for arguments.\n");
			while (sp[k])
			{
				args[j] = ft_strdup(sp[k]);
				k++;
				j++;
			}
			ft_split_free(sp);
			args[j] = NULL;
		}
	ft_check_args(ac, args);
	a = fill_stack_values(ac, args);
	// printf("av = %s\n", args[j]);
	b = NULL;
	index_stack(a);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	ft_split_free(args);
	return (0);
}
