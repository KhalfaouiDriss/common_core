#include "../philo.h"


void *check_dead(void *ph)
{
    t_philo *philo = (t_philo *)ph;

    while (1)
    {
        if(philo->next_meal < get_time() || philo->data->is_dead == YES)
        {
            philo->data->is_dead = YES;
            pthread_mutex_lock(philo->data->lock_print);
            print_message(DIED, philo);
            pthread_mutex_unlock(philo->data->lock_print);
            break;
        }
    }
    return NULL;

}

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	print_message(FORK, philo);
}

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->data->lock_eat);
	print_message(EATING, philo);
    if (philo->data->_eat_max != -1)
		philo->eat_count++;
    philo->last_eat_time = get_time();
    philo->next_meal = philo->last_eat_time + philo->data->_die_time;
    usleep(philo->data->_eat_time * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->data->lock_eat);
}

int check_eat(t_philo *philo)
{
    if(philo->data->_eat_max != -1 && philo->data->_eat_max <= philo->eat_count)
    {
        philo->data->is_dead = YES;
        pthread_mutex_lock(philo->data->lock_print);
        print_message(DONE, philo);
        pthread_mutex_unlock(philo->data->lock_print);
        return 1;
    }
    return 0;
}

void	ft_sleep(t_philo *philo)
{
	usleep(10);
	print_message(SLEEPING, philo);
	usleep(philo->data->_sleep_time * 1000);
}

void *rotine(void *ph)
{
    t_philo *philo;
    pthread_t monitore;

    philo = (t_philo *)ph;
    pthread_create(&monitore, NULL, check_dead, ph);
    pthread_detach(monitore);
    philo->next_meal = get_time() + philo->data->_die_time;
    while (1)
    {
        if(philo->data->is_dead)
            break;
        ft_take_fork(philo);
        ft_eat(philo);
        if(check_eat(philo))
            break;
        ft_sleep(philo);
        print_message(THINKING, philo);
    }
    return NULL;
}

int start_simulation(t_data *data)
{
    int i;
    t_philo *philo = data->philo;

    i = 0;
    while (i < data->philos_number)
    {
        pthread_create(&philo[i].th, NULL, rotine, (void *)&philo[i]);
        pthread_detach(philo[i].th);
        usleep(100);
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    t_data *data = malloc(sizeof(t_data));
    if (!data)
        return 1;
    ft_memset(data, 0, sizeof(t_data));
    if (init_data(data, av, ac))
        return 1;
    data->start_time = get_time();
    if(start_simulation(data))
        return 1;
    return 0;
}

