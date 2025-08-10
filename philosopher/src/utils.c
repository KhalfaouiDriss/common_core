#include "../philo.h"

int     ft_atoi(const char *str)
{
        int     sign;
        int     value;

        sign = 1;
        value = 0;
        while ((*str >= 9 && *str <= 13) || *str == 32)
                str++;
        if (*str == '-')
                sign = -1;
        if (*str == '-' || *str == '+')
                ++str;
        while (ft_isdigit(*str))
        {
                value = value * 10 + (*str - '0');
                str++;
        }
        value = sign * value;
        return (value);
}

t_data *get_data()
{
    static t_data *data;
    data = malloc(sizeof(t_data));
    return data;
}

int     ft_isdigit(int c)
{
        if (c >= 48 && c <= 57)
                return (1);
        return (0);
}

long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)str + i) = c;
		i++;
	}
	return ((void *)str);
}

void	print_message(int id, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->data->lock_print);
	time = get_time() - philo->data->start_time;
	if (id == FORK)
		printf("%u\t%d has taken a fork\n", time, philo->id + 1);
	else if (id == EATING)
		printf("%u\t%d is eating\n", time, philo->id + 1);
	else if (id == SLEEPING)
		printf("%u\t%d is sleeping\n", time, philo->id + 1);
	else if (id == THINKING)
		printf("%u\t%d is thinking\n", time, philo->id + 1);
	else if (id == DIED)
		printf("%u\t%d died\n", time, philo->id + 1);
	else if (id == DONE)
		printf("Simulation is Done :)\n");
	if (id != DIED && id != DONE)
		pthread_mutex_unlock(philo->data->lock_print);
}