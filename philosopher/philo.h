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
# define DBG printf("=====\n");

typedef struct s_mutexs
{
	pthread_mutex_t lock_eat;
} t_mutexs;

typedef struct s_philo
{
    int id;
    pthread_t th;
    pthread_mutex_t right_fork;
    pthread_mutex_t *left_fork;
    int t_die;
    int t_eat;
    int t_sleep;
    struct s_mutexs *mutexs;
    struct s_data *data;

    long last_eat_time;
    int eat_count;
    pthread_mutex_t meal_mutex;
} t_philo;


typedef struct s_data
{
	int philos_number;
	int _die_time;
	int _eat_time;
	int _sleep_time;
	int _eat_count;
	struct s_mutexs *mutexs;
	struct s_philo philo[PHILO_MAX_COUNT];
} t_data;


// utils.c
int     ft_atoi(const char *str);
t_data	*get_data();
int     ft_isdigit(int c);
long	get_time(void);		

#endif 