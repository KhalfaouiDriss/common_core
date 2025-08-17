#include "../philo2.h"

int check_args(int ac, char **av)
{
    int i;

    if(ac < 5 || ac > 6)
    {
        write(2 ,"number args not valaid\n", 24);
        return 1;
    }
    i = 1;
    if(ft_atoi(av[1]) > PHILO_MAX_COUNT)
        return 1;
    while (i < ac)
    {
        if(ft_atoi(av[i]) < 1 || ft_atoi(av[1]) > INT_MAX)
        {
            write(2 ,"args not valaid\n", 17);
            return 1;
        }
        i++;
    }
    return 0;
}


int main(int ac, char **av)
{
    t_data data;

    if(check_args(ac, av))
        return 1;
    if(init_data(&data, ac, av))
        return 1;
    if(init_philo(&data))
        return 1;
}