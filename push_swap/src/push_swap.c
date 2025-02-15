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

int	count(char **av)
{
	int		i;
	int		j;
	char	**test;

	i = 0;
	j = 0;
	while (av[i])
	{
		test = ft_split(av[i++], ' ');
		j += find_nb(test);
		ft_split_free(test);
	}
	return (j);
}

int	check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			return (0);
		i++;
	}
	return (1);
}

char	**fill_args(int ac, char **av)
{
	char	**args;
	char	**sp;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	args = malloc(count(av) * sizeof(char *));
	if (!args)
		ft_error("Error: Memory allocation failed.\n");
	while (i < ac)
	{
		k = 0;
		sp = ft_split(av[i++], ' ');
		if (!sp)
			ft_error("Error: Memory allocation failed.\n");
		while (sp[k])
			args[j++] = ft_strdup(sp[k++]);
		ft_split_free(sp);
		args[j] = NULL;
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**args;

	if (ac < 2 || !check(ac, av))
		ft_error("Error\n");
	args = fill_args(ac, av);
	ft_check_args(args);
	a = fill_stack_values(args);
	b = NULL;
	index_stack(a);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	ft_split_free(args);
	return (0);
}
