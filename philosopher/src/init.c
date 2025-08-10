#include "../philo.h"

int init_mutexs(t_data *data)
{
    int i;

    i = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
    while (i < data->philos_number)
    {
        if(pthread_mutex_init(&data->forks[i], NULL))
            return 1;
        i++;
    }
    data->lock_eat = malloc(sizeof(pthread_mutex_t));
    data->lock_mon = malloc(sizeof(pthread_mutex_t));
    data->lock_print = malloc(sizeof(pthread_mutex_t));
    if(pthread_mutex_init(data->lock_eat, NULL))
        return 1;
    if(pthread_mutex_init(data->lock_mon, NULL))
        return 1;
    if(pthread_mutex_init(data->lock_print, NULL))
        return 1;
    return 0;
}

int init_philos(t_data *data)
{
    int i;
    t_philo *philo;

    i = 0;
    while (i < data->philos_number)
    {
        philo = &data->philo[i];
        philo->id = i;
        philo->data = data;
        philo->last_eat_time = 0;
        philo->eat_count = 0;
        philo->left_fork = &data->forks[i];
        if(i < data->philos_number - 1)
            philo->right_fork = &data->forks[i + 1];
        if(i == data->philos_number - 1)
            philo->right_fork = &data->forks[0];
        i++;
    }
    return 0;
}
int init_data(t_data *data, char **av, int ac)
{
    if(ac < 5 || ac > 6)
        return 1;
    data->philos_number = ft_atoi(av[1]);
    data->_die_time = ft_atoi(av[2]);
    data->_eat_time = ft_atoi(av[3]);
    data->_sleep_time = ft_atoi(av[4]);
    data->_eat_max = -1;
    data->is_all = 0;
    data->is_dead = 0;
    if(ac == 6)
        data->_eat_max = ft_atoi(av[5]);
    if(init_mutexs(data))
        return 1;
    if (init_philos(data))
        return 1;
}