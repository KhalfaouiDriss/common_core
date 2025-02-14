/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:28:03 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:28:03 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(0);
}

void	ft_split_free(char **split)
{
	int	i;

	i = 0;
	if (!split || !(*split))
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_digit(char *num)
{
	int	i;

	if (!num || !*num)
		return (0);
	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
