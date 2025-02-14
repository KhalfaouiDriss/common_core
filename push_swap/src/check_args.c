#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str); 
}

int	ft_rpt_num(char **as)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	while (as[i])
	{
		num = ft_atoi(as[i]);
		j = i + 1;
		while (as[j])
		{
			if (num == ft_atoi(as[j]))
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

	if (ac == 2)
		as = ft_split(av[1], ' ');
	else
	{
		as = av;
		i = 1;
	}
	while (as[i])
	{
		if (!is_digit(as[i]))
			ft_error("the args is not valid\n");
		i++;
	}
	if (!ft_rpt_num(as))
		ft_error("you have a number repeating\n");
	if (ac == 2)
		ft_free(as);
	return (1);
}