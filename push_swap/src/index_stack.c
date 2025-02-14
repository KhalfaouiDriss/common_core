/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:46:11 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:46:11 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_list *stack)
{
	t_list	*tmp;
	int		size;
	int		arr[10000];
	int		i;

	if (!stack)
		return ;
	size = ft_lstsize(stack);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_arr(arr, size);
	i = 0;
	while (i < size)
	{
		tmp = ft_lstget(arr[i], stack);
		tmp->index = i + 1;
		i++;
	}
}
