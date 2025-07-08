#include "../philo.h"

long long timestamp_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void ft_usleep(int ms)
{
	long long start = timestamp_ms();
	while ((timestamp_ms() - start) < ms)
		usleep(100);
}

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(const char *str)
{
	int i = 0;
	int res = 0;
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return res;
}

void print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!philo->data->simulation_over)
		printf("%lld %d %s\n", timestamp_ms() - philo->data->start_time, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}

int valid_args(char **av)
{
	int i = 1, j;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return 1;
		i++;
	}
	return 0;
}

int print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	return (0);
}


t_philo **init_philos(t_data *data)
{
	t_philo **philos = malloc(sizeof(t_philo *) * data->nb_philos);
	if (!philos)
		return NULL;

	for (int i = 0; i < data->nb_philos; i++)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return NULL;

		philos[i]->id = i;
		philos[i]->meals = 0;
		philos[i]->data = data;
		philos[i]->last_meal = timestamp_ms();
		pthread_mutex_init(&philos[i]->meal_time_lock, NULL);
		philos[i]->left_fork = &data->forks[i];
		philos[i]->right_fork = &data->forks[(i + 1) % data->nb_philos];
	}
	return philos;
}

t_data *init_data(int ac, char **av)
{
	t_data *data = malloc(sizeof(t_data));
	if (!data)
		return NULL;

	data->nb_philos = ft_atoi(av[1]);
	data->_die_t = ft_atoi(av[2]);
	data->_eat_t = ft_atoi(av[3]);
	data->_sleep_t = ft_atoi(av[4]);
	data->must_eat_count = -1;
    if(ac == 6)
        data->must_eat_count = ft_atoi(av[5]);
	if (data->nb_philos <= 0 || data->nb_philos > 200 ||
		data->_die_t < 60 || data->_eat_t < 60 || data->_sleep_t < 60)
		return NULL;

	data->simulation_over = 0;
	data->start_time = timestamp_ms();
	pthread_mutex_init(&data->print_lock, NULL);

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	for (int i = 0; i < data->nb_philos; i++)
		pthread_mutex_init(&data->forks[i], NULL);

	data->philos = init_philos(data);
	if (!data->philos)
		return NULL;

	return data;
}

void cleanup(t_data *data)
{
    // 1. أوقف المحاكاة لو لم تكن موقوفة
    data->simulation_over = 1;

    // 2. انتظر ان تنتهي كل threads في حالة لم تنتظرها مسبقاً
    for (int i = 0; i < data->nb_philos; i++)
    {
        pthread_join(data->philos[i]->thread, NULL);
    }

    // 3. دمر mutex الفلاسفة
    for (int i = 0; i < data->nb_philos; i++)
    {
        pthread_mutex_destroy(&data->philos[i]->meal_time_lock);
    }

    // 4. دمر mutexات الفورك
    for (int i = 0; i < data->nb_philos; i++)
    {
        pthread_mutex_destroy(&data->forks[i]);
    }

    // 5. دمر mutex طباعة الرسائل
    pthread_mutex_destroy(&data->print_lock);

    // 6. حرر ذاكرة الفلاسفة
    for (int i = 0; i < data->nb_philos; i++)
    {
        free(data->philos[i]);
    }
    free(data->philos);

    // 7. حرر mutexات الفورك
    free(data->forks);

    // 8. حرر بيانات المحاكاة
    free(data);
}

