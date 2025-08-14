/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:09 by dapetros          #+#    #+#             */
/*   Updated: 2025/07/19 10:16:25 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_data *en, t_philo *philos, t_mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].times.die = ft_atoi(argv[2]);
		philos[i].times.eat = ft_atoi(argv[3]);
		philos[i].times.sleep = ft_atoi(argv[4]);
		philos[i].times.last_meal = get_current_time();
		philos[i].times.born_time = get_current_time();
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].meals_eaten = 0;
		philos[i].philo_count = ft_atoi(argv[1]);
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &en->write_lock;
		philos[i].mutexes.meal_lock = &en->meal_lock;
	}
}

void	init_forks(t_data *data, t_mutex *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(data, "[Mutex Init ERROR]\n", i, 1);
	}
}

void	init_data(t_data *data, t_philo *philos, t_mutex *forks)
{
	data->forks = forks;
	data->philos = philos;
	if (pthread_mutex_init(&data->write_lock, NULL) != 0
		|| pthread_mutex_init(&data->meal_lock, NULL) != 0)
		destroy_all(data, "[Mutex Init ERROR]\n", -1, 1);
}
