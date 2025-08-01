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
    data->mutexs = malloc(sizeof(t_mutexs));
    if (!data->mutexs)
        return 0;
    if (pthread_mutex_init(&data->mutexs->lock_eat, NULL) != 0)
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
			pthread_mutex_lock(&philo->mutexs->lock_eat);
			long now = get_time();
			if (now - philo->last_eat_time > philo->t_die)
			{
				printf("💀 philo[%d] died\n", philo->id);
				exit(1);
			}
			pthread_mutex_unlock(&philo->mutexs->lock_eat);
            i++;
        }
		usleep(1000);
	}
	return NULL;
}



void *simulation(void *ph)
{
	t_philo *philo = (t_philo *)ph;

	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(500);

		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->right_fork);

		pthread_mutex_lock(&philo->mutexs->lock_eat);
		philo->last_eat_time = get_time();
		philo->eat_count++;
		printf("philo[%d] : eating\n", philo->id);
		usleep(philo->t_eat);
		pthread_mutex_unlock(&philo->mutexs->lock_eat);

		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		printf("philo[%d] : sleeping\n", philo->id);
		usleep(philo->t_sleep);

		printf("philo[%d] : thinking\n", philo->id);
	}
	return NULL;
}


int create_philos(t_data *data)
{
    int i = 0;
    pthread_t monitor;

	pthread_create(&monitor, NULL, monitoring, data);
    while (i < data->philos_number)
    {
        t_philo *philo = &data->philo[i];
        philo->id = i;
        philo->t_die = data->_die_time;
        philo->t_eat = data->_eat_time;
        philo->t_sleep = data->_sleep_time;
        philo->mutexs = data->mutexs;
        philo->data = data;
        philo->eat_count = 0;
        philo->last_eat_time = get_time();
        pthread_mutex_init(&philo->right_fork, NULL);

        if (i > 0)
            philo->left_fork = &data->philo[i - 1].right_fork;

        i++;
    }
    data->philo[0].left_fork = &data->philo[data->philos_number - 1].right_fork;
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
    pthread_detach(monitor);
    return join_all(data);
}


int main(int ac, char **av)
{
    t_data *data = get_data();

    if (!init_data(data, av, ac))
        return 1;

    if (!create_philos(data))
        return 1;

    return 0;
}
