#include "../philo.h"

void	*philo_job(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->id % 2)
		usleep(1000); // delay to avoid race on forks

	while (!philo->data->simulation_over)
	{
		// take forks
		pthread_mutex_lock(philo->left_fork);
		 if (philo->data->simulation_over)
    	{
			pthread_mutex_unlock(philo->left_fork);
			break;
    	}
		print_action(philo, "has taken a fork");

		pthread_mutex_lock(philo->right_fork);
		if (philo->data->simulation_over)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			break;
		}
		print_action(philo, "has taken a fork");

		// eat
		pthread_mutex_lock(&philo->meal_time_lock);
		print_action(philo, "is eating");
		philo->last_meal = timestamp_ms();
		philo->meals++;
		pthread_mutex_unlock(&philo->meal_time_lock);

		ft_usleep(philo->data->_eat_t);

		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		// sleep
		print_action(philo, "is sleeping");
		ft_usleep(philo->data->_sleep_t);

		// think
		print_action(philo, "is thinking");
	}
	return NULL;
}


void	*controller(void *arg)
{
	int i = 0;
	t_data *data = (t_data *)arg;

	while (!data->simulation_over)
	{
		while(i < data->nb_philos)
		{
			t_philo *p = data->philos[i];

			pthread_mutex_lock(&p->meal_time_lock);
			if ((timestamp_ms() - p->last_meal) > data->_die_t)
			{
				print_action(p, "died");
				data->simulation_over = 1;
				pthread_mutex_unlock(&p->meal_time_lock);
				return NULL;
			}
			pthread_mutex_unlock(&p->meal_time_lock);
			i++;
		}
		usleep(1000);
	}
	return NULL;
}


void start_simulation(t_data *data)
{
    int i = 0;
	pthread_t monitor;

	pthread_create(&monitor, NULL, controller, data);
	while( i < data->nb_philos)
    {
        pthread_create(&data->philos[i]->thread, NULL, philo_job, data->philos[i]);
        i++;
    }
    i = 0;
	while(i < data->nb_philos)
    {
		pthread_join(data->philos[i]->thread, NULL);
        i++;
    }
	pthread_join(monitor, NULL);
}

int main(int ac, char **av)
{
	t_data *data;

	if (ac < 5 || ac > 6)
		return print_error("invalid argument count");
	if (valid_args(av))
		return print_error("arguments must be numbers");

	data = init_data(ac, av);
	if (!data)
		return print_error("failed to initialize data");

	start_simulation(data);
	cleanup(data);
	return 0;
}
