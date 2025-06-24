#include "../philo.h"

t_philo *init_philos(t_data *data)
{
    t_philo **philos;
    int i;

    i = 0;
    philos = malloc(sizeof(t_philo) * data->nb_philos);
    while (i < data->nb_philos)
    {
        philos[i] = malloc(sizeof(t_philo));
        if(!philos[i])
            return NULL;
        pthread_mutex_init(&philos[i]->meal_time_lock, 0);
        philos[i]->id = i;
        philos[i]->time_eat = 0;
        
    }
    
}

t_data *init_data(int ac, char **av)
{
    t_data *data;
    int i = 1;
    
    data = malloc(sizeof(t_data) * 1);
    if(!data)
        return NULL;
    
    data->nb_philos = ft_atoi(av[i++]); 
    data->_die_t = ft_atoi(av[i++]); 
    data->_eat_t = ft_atoi(av[i++]); 
    data->_sleep_t = ft_atoi(av[i++]); 
    data->must_eat_count = -1;

    if (ac == 6)
        data->must_eat_count = ft_atoi(av[i]);

    if (data->nb_philos <= 0 || data->nb_philos > 200 ||
        data->_die_t < 60 || data->_eat_t < 60 || data->_sleep_t < 60)
        return NULL;
    data->philos = init_philos(data);
    if(!data->philos)
        return NULL;
    return data;
}

int valid_args(char **av)
{
    int i = 1;
    int j;

    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

int print_error(char *msg)
{
    printf("Error: %s\n", msg);
    return 0;
}

void *controller(void *dt)
{
    t_data *data = (t_data *)dt;

}

void *philo_job(void *dt)
{
    t_data *data = (t_data *)dt;

}

void start_simulation(t_data *data)
{
    int i;
    // pthread_t td[data->nb_philos];
    pthread_t mtr;

    pthread_create(mtr, NULL, controller, (void *)data);
    i = 0;

    while(i < data->nb_philos)
    {
        pthread_create(&data->philos[i]->thread, NULL, philo_job, (void *)data)
    }
}

int main(int ac, char **av)
{
    t_data *data;

    if (ac < 5 || ac > 6)
        return print_error("incorrect number of arguments");
    if (valid_args(av))
        return print_error("arguments must be positive numbers");
    data = init_data(ac, av);
    if (!data)
        return print_error("invalid values in arguments");
    start_simulation(&data);

    return 0;
}
