/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:46 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/08/18 11:41:15 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Argument Count error\n", 22);
		return (1);
	}
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
		{
			write(1, "Argument error\n", 16);
			return (1);
		}
		else if ((num < 0 || num > INT_MAX))
		{
			write(1, "Argument error\n", 16);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			philos[PHILO_MAX_COUNT];
	pthread_mutex_t	forks[PHILO_MAX_COUNT];
	t_data			data;

	if (check_args(argc, argv))
		return (1);
	if (init_data(&data, philos, forks))
		return (1);
	if (init_forks(&data, forks, ft_atoi(argv[1])))
		return (1);
	init_philos(&data, philos, forks, argv);
	if (simulation(&data, philos[0].philo_count))
		return (1);
	destroy_all(&data, NULL, philos[0].philo_count, 0);
	return (0);
}
