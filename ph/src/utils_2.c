/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:37:27 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/08/18 01:23:52 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + (str[i] - '0');
		++i;
		if (num > INT_MAX)
			break ;
	}
	return (num * sign);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	if (print_action(philo, " has taken a fork"))
	{
		pthread_mutex_unlock(philo->mutexes.left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->mutexes.right_fork);
	if (print_action(philo, " has taken a fork"))
	{
		pthread_mutex_unlock(philo->mutexes.left_fork);
		pthread_mutex_unlock(philo->mutexes.right_fork);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	if (print_action(philo, " is eating"))
	{
		pthread_mutex_unlock(philo->mutexes.right_fork);
		pthread_mutex_unlock(philo->mutexes.left_fork);
		return (1);
	}
	philo->times.last_meal = get_time();
	philo->meals_eaten += 1;
	if (ft_usleep(philo, philo->times.eat))
	{
		pthread_mutex_unlock(philo->mutexes.left_fork);
		pthread_mutex_unlock(philo->mutexes.right_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	return (0);
}

void	init_times(t_philo *philo, char **argv)
{
	philo->philo_count = ft_atoi(argv[1]);
	philo->times.die = ft_atoi(argv[2]);
	philo->times.eat = ft_atoi(argv[3]);
	philo->times.sleep = ft_atoi(argv[4]);
}
