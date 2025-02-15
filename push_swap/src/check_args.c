/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:25:49 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/14 16:25:49 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_rpt_num(char **as)
{
	int	i;
	int	j;
	long	num;

	i = 0;
	while (as[i])
	{
		num = ft_atoi(as[i]);
		j = i + 1;
		while (as[j])
		{
			if (num == ft_atoi(as[j]) || num == 2147483648)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	char	**as;
	int		i;

	i = 0;
	as = av;
	while (as[i])
	{
		if (!is_digit(as[i]))
		(ft_split_free(as), ft_error("the args is not valid\n"));
		i++;
	}
	if (!ft_rpt_num(as))
		(ft_split_free(as),  ft_error("you have a number repeating\n"));
	return (1);
}
