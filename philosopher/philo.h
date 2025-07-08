// #ifndef PHILO
// # define PHILO

// # include <pthread.h>
// # include <limits.h>
// # include <unistd.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <sys/time.h>
// #include "libft/libft.h"


// typedef struct s_data
// {
//     t_philo **philos;
//     unsigned int _die_t;
//     unsigned int _eat_t;
//     unsigned int _sleep_t;
//     int nb_philos;
//     int must_eat_count;

// } t_data;


// typedef struct s_philo
// {
//     pthread_t thread;
//     int id;
//     unsigned int time_eat;
//     unsigned int fork[2];
//     pthread_mutex_t meal_time_lock;
// 	unsigned int last_meal;
// 	t_data *data;
// } t_philo;


// # endif

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;
	int				meals;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	meal_time_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				_die_t;
	int				_eat_t;
	int				_sleep_t;
	int				must_eat_count;
	long long		start_time;
	int				simulation_over;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	t_philo			**philos;
}	t_data;

// utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long long	timestamp_ms(void);
void		ft_usleep(int ms);
void		print_action(t_philo *philo, char *msg);
t_philo **init_philos(t_data *data);
t_data *init_data(int ac, char **av);
int valid_args(char **av);
int print_error(char *msg);
void cleanup(t_data *data);

#endif
