#include "../philo.h"

int init_data(t_data *data, char **av, int ac)
{
    if (ac < 5)
    {
        printf("needs args\n");
        return 0;
    }

    data->philos_number = ft_atoi(av[1]);
    data->_die_time = ft_atoi(av[2]);
    data->_eat_time = ft_atoi(av[3]);
    data->_sleep_time = ft_atoi(av[4]);
    data->_eat_count = -1;
    if (ac == 6)
        data->_eat_count = ft_atoi(av[5]);
    int i = 0;
    while (i < data->philos_number)
    {
        data->philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(data->philo[i].left_fork, NULL);
        i++;
    }
    data->lock_eat = malloc(sizeof(pthread_mutex_t));
    data->lock_print = malloc(sizeof(pthread_mutex_t));
    data->lock_mon = malloc(sizeof(pthread_mutex_t));

    if (!data->lock_eat || !data->lock_print || !data->lock_mon)
        return 0;

    if (pthread_mutex_init(data->lock_eat, NULL) != 0)
        return 0;
    if (pthread_mutex_init(data->lock_print, NULL) != 0)
        return 0;
    if (pthread_mutex_init(data->lock_mon, NULL) != 0)
        return 0;

    return 1;
}

int join_all(t_data *data)
{
    int i = 0;
    
    while(i < data->philos_number)
    {
        if (pthread_join(data->philo[i].th, NULL) != 0)
        {
            printf("error joining\n");
            return 0;
        }
        i++;
    }
    return 1;
}

void *monitoring(void *arg)
{
	t_data *data = (t_data *)arg;
    int i = 0;

	while (1)
	{
        i = 0;
		while (i < data->philos_number)
		{
			t_philo *philo = &data->philo[i];
			pthread_mutex_lock(philo->data->lock_mon);
			if (get_time() - philo->last_eat_time >= philo->data->_die_time)
			{
				printf("philo[%d] died\n", philo->id);
				exit(1);
			}
			pthread_mutex_unlock(philo->data->lock_mon);
            i++;
        }
	}
	return NULL;
}



void *simulation(void *ph)
{
	t_philo *philo = (t_philo *)ph;
    

    if (philo->id % 2 == 0)
        usleep(1000);
	while (1)
	{
        pthread_mutex_lock(philo->left_fork);
        printf("philo[%d] : take left fork\n", philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf("philo[%d] : take right fork\n", philo->id);

		pthread_mutex_lock(philo->data->lock_eat);
        philo->state = EAT;
		philo->last_eat_time = get_time();
		philo->eat_count++;
		printf("philo[%d] : eating\n", philo->id);
		usleep(philo->data->_eat_time);
		pthread_mutex_unlock(philo->data->lock_eat);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		printf("philo[%d] : sleeping\n", philo->id);
		usleep(philo->data->_sleep_time * 1000);
		printf("philo[%d] : thinking\n", philo->id);
	}
	return NULL;
}


int create_philos(t_data *data)
{
    int i = 0;
    pthread_t monitor;

    
    while (i < data->philos_number)
    {
        t_philo *philo = &data->philo[i];
        philo->id = i+1;
        philo->data = data;
        philo->eat_count = 0;
        philo->last_eat_time = get_time();

        philo->left_fork = data->philo[i].left_fork;
        philo->right_fork = data->philo[(i + 1) % data->philos_number].left_fork;
        i++;
    }
    i = 0;
    while (i < data->philos_number)
    {
        if (pthread_create(&data->philo[i].th, NULL, simulation, &data->philo[i]) != 0)
        {
            printf("thread creation failed\n");
            return 0;
        }
        i++;
    }

    pthread_create(&monitor, NULL, monitoring, data);

    join_all(data);
    pthread_join(monitor, NULL);
    return 1;
}



int main(int ac, char **av)
{
    t_data *data = malloc(sizeof(t_data));
    if (!data)
        return 1;
    ft_memset(data, 0, sizeof(t_data));

    if (!init_data(data, av, ac))
        return 1;

    if (!create_philos(data))
        return 1;

    return 0;
}

