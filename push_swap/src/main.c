#include "../push_swap.h"
#include <stdio.h>

int	is_digit(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int ft_free(char **as)
{
    
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
	long	tmp;

	i = 1;
	if (ac == 2)
		as = ft_split(av[1], " ");
	else
		as = av;
	while (as[i])
	{
		tmp = ft_atoi(as[i]);
		if (!is_digit(as[i]))
			return (0);
		i++;
	}
    if(ac == 2)
        ft_free(as);
	return (ft_rpt_num(as));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!ft_check_args(ac, av))
        return (0);
    
	return (0);
}
