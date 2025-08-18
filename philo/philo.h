/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 02:07:08 by khalfaoui47       #+#    #+#             */
/*   Updated: 2025/08/18 14:01:56 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX_COUNT 200

typedef struct timeval	t_timeval;
typedef struct s_data	t_data;

typedef struct s_mutexes
{
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*meal_lock;
}						t_mutexes;

typedef struct s_times
{
	size_t				die;
	size_t				eat;
	size_t				sleep;
	size_t				last_meal;
	size_t				born_time;
}						t_times;

typedef struct s_philo
{
	int					id;
	t_times				times;
	t_mutexes			mutexes;
	int					must_eat;
	pthread_t			thread_id;
	int					meals_eaten;
	int					philo_count;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	pthread_mutex_t		*forks;
	t_philo				*philos;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
	int					id_die;
}						t_data;

// init.c
void					init_philos(t_data *en, t_philo *philos,
							pthread_mutex_t *forks, char **argv);
int						init_forks(t_data *data, pthread_mutex_t *forks,
							int count);
int						init_data(t_data *data, t_philo *philos,
							pthread_mutex_t *forks);

// simulation.c
bool					is_all_eat(t_philo *philos);
void					*monitor(void *ptr);
int						philo_routine(t_philo *philo);
void					*start_simulation(void *ptr);
int						simulation(t_data *data, int count);

// utils.c
void					error_message(char *text);
int						destroy_all(t_data *data, char *str, int count,
							int signal);
int						print_action(t_philo *philo, char *action);
size_t					get_time(void);
int						ft_usleep(t_philo *philo, size_t ms);

// utils_2.c
size_t					ft_strlen(const char *str);
long					ft_atoi(const char *str);
int						eating(t_philo *philo);
int						take_forks(t_philo *philo);
void					init_times(t_philo *philo, char **argv);

int						check_args(int argc, char **argv);
int	one_philo(t_philo *philo);
#endif