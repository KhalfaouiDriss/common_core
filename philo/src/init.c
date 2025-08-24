/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:09 by dapetros          #+#    #+#             */
/*   Updated: 2025/08/19 16:26:06 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_data *data, t_philo *philos, pthread_mutex_t *forks,
		char **argv)
{
	int		i;
	size_t	born;

	i = 0;
	born = get_time();
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		init_times(&philos[i], argv);
		philos[i].times.last_meal = born;
		philos[i].times.born_time = born;
		philos[i].data = data;
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].meals_eaten = 0;
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &data->write_lock;
		philos[i].mutexes.meal_lock = &data->meal_lock;
		i++;
	}
}

int	init_forks(t_data *data, pthread_mutex_t *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			destroy_all(data, "Mutex Init error\n", i, 1);
			return (1);
		}
	}
	return (0);
}

int	init_data(t_data *data, t_philo *philos, pthread_mutex_t *forks)
{
	data->forks = forks;
	data->philos = philos;
	data->id_die = 0;
	if (pthread_mutex_init(&data->write_lock, NULL) != 0
		|| pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		destroy_all(data, "Mutex Init error\n", -1, 1);
		return (1);
	}
	return (0);
}
