#include "../philo.h"

int check_args(char **av)
{
    int i = 1;
    int num;
    // printf("hear----------------\n");
    while (av[i])
    {
        num = ft_atoi(av[i]);
        if(!num)
            return 0;
        i++;
    }
    return 1;
}

int init_philos(t_data *data, char **av, int ac)
{
    int num_philo;

    int i;

    i = 1;
    num_philo = ft_atoi(av[1]);
    data->_die = ft_atoi(av[2]);
    data->_eat = ft_atoi(av[3]);
    data->_sleep = ft_atoi(av[4]);
    data->n_philo = num_philo;
    data->n_eat = 0;
    if(ac == 6)
        data->n_eat = ft_atoi(av[5]);
    if(num_philo < 1 || data->_die < 1 || data->_eat < 1 || data->_sleep < 1 || data->n_eat < 0)
        return 0;
    printf("philo num : %d\n", num_philo);
    data->philos = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
    while (i <= num_philo)
    {
        data->philos[i] = i;
        i++;
    }
    
}

int main(int ac, char **av) 
{
    t_data data;

    if(ac == 5 || ac == 6)
    {
        if(!check_args(av))
        {
                printf("args not valide 1");
                return 0;
        }
        if(!init_philos(&data, av, ac))
        {
                printf("args not valide");
                return 0;
            }
            
        printf("%ld\n", data.philos[8]);
    }
    else
    {
        printf("syntax : ./philo [number of philos] [time_to_die] [time_to_eat] [time_to_sleep]"
             " [each_philosopher_must_eat]\n");
        return 0;
    }
}