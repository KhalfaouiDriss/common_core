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
# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DONE 6

typedef struct s_philo
{
    int id;
    int state;
    pthread_t th;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    struct s_data *data;
    long last_eat_time;
    long next_meal;
    int eat_count;
} t_philo;


typedef struct s_data
{
	int philos_number;
	int _die_time;
	int _eat_time;
	int _sleep_time;
	int _eat_max;
    long start_time;
    int is_all;
    int is_dead;
    pthread_mutex_t *lock_eat;
	pthread_mutex_t *lock_mon;
	pthread_mutex_t *lock_print;
	pthread_mutex_t *forks;
	t_philo philo[PHILO_MAX_COUNT];
} t_data;


// utils.c
int     ft_atoi(const char *str);
t_data	*get_data();
int     ft_isdigit(int c);
long	get_time(void);
void	*ft_memset(void *str, int c, size_t len);
void	print_message(int id, t_philo *philo);

// init.c
int init_data(t_data *data, char **av, int ac);
int init_philos(t_data *data);
int init_mutexs(t_data *data);

void	ft_take_fork(t_philo *philo);

#endif 