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
# define EAT 1
# define THINK 2
# define HUNGRY 3

typedef struct s_philo
{
    int id;
    int state;
    pthread_t th;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    struct s_data *data;
    long last_eat_time;
    int eat_count;
} t_philo;


typedef struct s_data
{
	int philos_number;
	int _die_time;
	int _eat_time;
	int _sleep_time;
	int _eat_count;
    long start_time;
    pthread_mutex_t *lock_eat;
	pthread_mutex_t *lock_mon;
	pthread_mutex_t *lock_print;
	struct s_philo philo[PHILO_MAX_COUNT];
} t_data;


// utils.c
int     ft_atoi(const char *str);
t_data	*get_data();
int     ft_isdigit(int c);
long	get_time(void);
void	*ft_memset(void *str, int c, size_t len);

#endif 