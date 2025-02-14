/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_utils_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:58 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:59:58 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstget(int val, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_lstsize(t_list *head)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_printlst(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	printf("[val->idx->pos->tar_pos]\n");
	printf("--------------------------\n");
	ft_putstr_fd(" [", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(tmp->index, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(tmp->pos, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(tmp->target_pos, 1);
		if (tmp->next)
			ft_putstr_fd("] \n [", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("]\n", 1);
}
