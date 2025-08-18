/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:14 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/08/18 13:24:15 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_message(char *text)
{
	if (text)
		write(2, text, ft_strlen(text) + 1);
}

int	destroy_all(t_data *data, char *str, int count, int signal)
{
	int	i;

	i = 0;
	if (signal == 1)
	{
		while (i < count)
		{
			pthread_join(data->philos[i].thread_id, NULL);
			i++;
		}
	}
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	if (str)
		write(1, str, ft_strlen(str) + 1);
	return (1);
}

int	print_action(t_philo *philo, char *action)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	if (!philo->data->id_die)
	{
		time = get_time() - philo->times.born_time;
		printf("%ld %d%s\n", time, philo->id, action);
		pthread_mutex_unlock(philo->mutexes.write_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->mutexes.write_lock);
	return (1);
}

size_t	get_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, size_t ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < ms)
	{
		pthread_mutex_lock(philo->mutexes.write_lock);
		if (philo->data->id_die)
		{
			pthread_mutex_unlock(philo->mutexes.write_lock);
			return (1);
		}
		pthread_mutex_unlock(philo->mutexes.write_lock);
		usleep(50);
	}
	return (0);
}
