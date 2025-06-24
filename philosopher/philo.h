#ifndef PHILO
# define PHILO

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
#include "libft/libft.h"


typedef struct s_data
{
    t_philo **philos;
    unsigned int _die_t;
    unsigned int _eat_t;
    unsigned int _sleep_t;
    int nb_philos;
    int must_eat_count;

} t_data;


typedef struct s_philo
{
    pthread_t thread;
    int id;
    unsigned int time_eat;
    unsigned int fork[2];
    pthread_mutex_t meal_time_lock;
	unsigned int last_meal;
	t_data *data;
} t_philo;


# endif