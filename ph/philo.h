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

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	t_mutexes	mutexes;
	int			must_eat;
	t_id		thread_id;
	int			meals_eaten;
	int			philo_count;
}	t_philo;

typedef struct s_data
{
	t_mutex	*forks;
	t_philo	*philos;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}	t_data;

// init.c
void	init_philos(t_data *en, t_philo *philos, t_mutex *forks, char **argv);
void	init_forks(t_data *data, t_mutex *forks, int count);
void	init_data(t_data *data, t_philo *philos, t_mutex *forks);

// simulation.c
bool	is_all_eat(t_philo *philos);
void	*obsorver(void *ptr);
void	philo_routine(t_philo *philo);
void	*start_simulation(void *ptr);
void	launcher(t_data *data, int count);

// utils.c
void	error_message(char *text);
void	destroy_all(t_data *data, char *str, int count, int signal);
void	print_action(t_philo *philo, char *action);
size_t	get_current_time(void);
void	ft_usleep(size_t mls);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);

#endif 