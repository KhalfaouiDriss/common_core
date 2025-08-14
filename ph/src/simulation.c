/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:39 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/08/14 09:25:29 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	is_all_eat(t_philo *philos)
{
	int		finished;
	int		i;

	i = -1;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (false);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (true);
	}
	return (false);
}

void	*obsorver(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = 0;
		while (i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_time() - philos[i].times.last_meal
				> philos[i].times.die)
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_action(&philos[i], " died");
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
			i++;
		}
		if (is_all_eat(philos))
			return (NULL);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_action(philo, " is eating");
	philo->times.last_meal = get_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, " is thinking");
}

void	*start_simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = get_time();
	philo->times.last_meal = get_time();
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while (true)
		philo_routine(philo);
	return (NULL);
}

int	simulation(t_data *data, int count)
{
	pthread_t	monitore_id;
	int		i;

	i = 0;
	if (pthread_create(&monitore_id, NULL, &obsorver, data->philos) != 0)
		return (destroy_all(data, "Thread Creation error\n", count, 1));
	while (i < count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL,
				start_simulation, &data->philos[i]) != 0)
			return (destroy_all(data, "Thread Creation error\n", count, 1));
		i++;
	}
	i = 0;
	if (pthread_join(monitore_id, NULL) != 0)
		return (destroy_all(data, "Thread Join error\n", count, 1));
	while (i < count)
	{
		if (pthread_detach(data->philos[i].thread_id) != 0)
			return (destroy_all(data, "Thread Detach error\n", count, 1));
		i++;
	}
}
