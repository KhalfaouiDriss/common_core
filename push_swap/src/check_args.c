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

int	find_nb(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	int		i;
	int		j;
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

int	ft_check_args(char **av)
{
	char	**as;
	int		i;

	i = 0;
	as = av;
	while (as[i])
	{
		if (!is_digit(as[i]))
		{
			ft_split_free(as);
			ft_error("Error: The arguments are not valid\n");
		}
		if(ft_atoi(as[i]) == 2147483648)
			ft_error("Error\n");
		i++;
	}
	if (!ft_rpt_num(as))
		(ft_split_free(as), ft_error("Error: Duplicate numbers detected\n"));
	return (1);
}
