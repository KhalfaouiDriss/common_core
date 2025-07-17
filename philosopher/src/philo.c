#include "../philo.h"

void	*controller(void *arg)
{

	return NULL;
}

void *philo_job()
{

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
