/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:46 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/07/19 10:26:30 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc < 5 || argc > 6)
		error_message("[Argument Count error]\n");
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
			error_message("[Argument error]\n");
		else if ((num < 0 || num > INT_MAX))
			error_message("[Argument error]\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo		philos[PHILO_MAX_COUNT];
	t_mutex		forks[PHILO_MAX_COUNT];
	t_data	data;

	check_args(argc, argv);
	init_data(&data, philos, forks);
	init_forks(&data, forks, ft_atoi(argv[1]));
	init_philos(&data, philos, forks, argv);
	launcher(&data, philos[0].philo_count);
	destroy_all(&data, NULL, philos[0].philo_count, 0);
	return (0);
}
