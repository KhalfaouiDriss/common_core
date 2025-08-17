#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define PHILO_MAX_COUNT 200

typedef struct timeval	t_timeval;
typedef struct s_data t_data;

typedef struct s_mutexes
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	must_eat;
}	t_times;

typedef struct s_philo
{
	int id;
	pthread_t th;
	t_data *data;
	size_t	last_meal;
	size_t	born_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

}	t_philo;

typedef struct s_data
{
	int number_philos;
	t_philo *philos;
	t_times times;
	pthread_mutex_t *forks;
	pthread_mutex_t *write_lock;
	pthread_mutex_t *meal_lock;
}	t_data;



long	ft_atoi(const char *str);

#endif 