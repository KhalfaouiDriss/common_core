#include "../push_swap.h"

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

void ft_split_free(char **split)
{
    int i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
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

