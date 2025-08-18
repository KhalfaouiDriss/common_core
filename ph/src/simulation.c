/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:39 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/08/18 11:51:55 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	is_all_eat(t_philo *philos)
{
	int	finished;
	int	i;

	i = 0;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (false);
	while (i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
		i++;
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		philos->data->id_die = 1;
		pthread_mutex_unlock(philos->mutexes.write_lock);
		return (true);
	}
	return (false);
}

void	*monitor(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = 0;
		while (i < philos[0].philo_count)
		{
			if (get_time() - philos[i].times.last_meal > philos[i].times.die)
			{
				print_action(&philos[i], " died");
				pthread_mutex_lock(philos->mutexes.write_lock);
				philos->data->id_die = 1;
				pthread_mutex_unlock(philos->mutexes.write_lock);
				return (NULL);
			}
			i++;
		}
		if (is_all_eat(philos))
			return (NULL);
	}
	return (NULL);
}

int	philo_routine(t_philo *philo)
{
	if (print_action(philo, " is thinking"))
		return (1);
	usleep(2000);
	if (take_forks(philo))
		return (1);
	if (eating(philo))
		return (1);
	if (print_action(philo, " is sleeping"))
		return (1);
	if (ft_usleep(philo, philo->times.sleep))
		return (1);
	return (0);
}

void	*start_simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(2000);
	while (true)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		if (philo[0].data->id_die)
		{
			pthread_mutex_unlock(&philo->data->write_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->write_lock);
		if (philo_routine(philo))
			break ;
	}
	return (NULL);
}

int	simulation(t_data *data, int count)
{
	pthread_t	monitore_id;
	int			i;

	i = 0;
	if (pthread_create(&monitore_id, NULL, &monitor, data->philos) != 0)
		return (destroy_all(data, "Thread Creation error\n", count, 1));
	while (i < count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, start_simulation,
				&data->philos[i]) != 0)
			return (destroy_all(data, "Thread Creation error\n", count, 1));
		i++;
	}
	i = 0;
	if (pthread_join(monitore_id, NULL) != 0)
		return (destroy_all(data, "Thread Join error\n", count, 1));
	while (i < count)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			return (destroy_all(data, "Thread Detach error\n", count, 1));
		i++;
	}
	return (0);
}
