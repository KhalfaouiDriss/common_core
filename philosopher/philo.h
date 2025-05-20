#ifndef PHILO
#define PHILO

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

typedef struct s_data
{
    int n_philo;
    pthread_t *philos;
    int _eat;
    int _sleep;
    int _die;
    int n_eat;

} t_data;


// utils_1
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif