#include "../philo2.h"

size_t get_time()
{
    t_timeval t;
    gettimeofday(&t, NULL);

    return((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int init_data(t_data *data, int ac, char **av)
{

    data = malloc(sizeof(t_data));
    data->philos = malloc(sizeof(t_philo) * ft_atoi(av[1]));
    data->meal_lock = malloc(sizeof(pthread_mutex_t));
    data->write_lock = malloc(sizeof(pthread_mutex_t));
    data->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));

    if(!data || !data->philos || ! data->meal_lock || !data->write_lock || !data->forks)
        return 1;
    data->number_philos = ft_atoi(av[1]);
    data->times.die = ft_atoi(av[2]);
    data->times.eat = ft_atoi(av[3]);
    data->times.sleep = ft_atoi(av[4]);
    data->times.sleep = -1;
    if(ac == 6)
        data->times.sleep = ft_atoi(av[5]);
    return 0;
}

int init_mutexs(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philos)
    {
        if(pthread_mutex_init(&data->forks[i], NULL))
            return 1;
        i++;
    }
    if(pthread_mutex_init(&data->write_lock, NULL) || 
        pthread_mutex_init(&data->meal_lock, NULL))
        return 1;
}

int init_philo(t_data *data)
{
    int i;
    size_t born;
    t_times *t = &data->times;
    t_philo *phil;

    i = 0;
    born = get_time();
    init_mutexs(data);
    while (i < data->number_philos)
    {
        phil = &data->philos[i];
        phil->data = data;
        phil->born_time = born;
        phil->last_meal = born;
        phil->
        i++;
    }
    
}