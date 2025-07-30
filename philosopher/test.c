// # include <pthread.h>
// #include <limits.h>
// #include <sys/time.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// typedef struct s_data t_data;

// typedef struct s_mutexs
// {
//     pthread_mutex_t lock_eat;
//     // pthread_mutex_t lock_eat;
// } t_mutexs;

// typedef struct s_philo
// {
//     int id;
//     pthread_t th;
//     t_data *data;
//     int t_eat;
//     int t_die;
//     int t_sleep;
//     int n_philos;
//     pthread_mutex_t right_fork;
//     pthread_mutex_t *left_fork;
//     t_mutexs *mutexs;

// } t_philo;

// typedef struct s_data
// {
//     t_philo th[200];
//     int t_eat;
//     int t_die;
//     int t_sleep;
//     int n_philos;
//     t_mutexs *mutexs;

// } t_data;


// void rot(t_philo *philo)
// {
//     if (philo->id % 2 == 0)
//         sleep(1);
//     if (philo->id % 2 == 0) {
//         pthread_mutex_lock(&philo->right_fork);
//         printf("philo[%d] : has taken right fork\n", philo->id + 1);
//         pthread_mutex_lock(philo->left_fork);
//         printf("philo[%d] : has taken left fork\n", philo->id + 1);
//     } else {
//         pthread_mutex_lock(philo->left_fork);
//         printf("philo[%d] : has taken left fork\n", philo->id + 1);
//         pthread_mutex_lock(&philo->right_fork);
//         printf("philo[%d] : has taken right fork\n", philo->id + 1);
//     }
//     pthread_mutex_lock(&philo->mutexs->lock_eat);
//     printf("philo[%d] : is eating\n", philo->id + 1);
//     sleep(1);
//     printf("philo[%d] : finish eating\n", philo->id + 1);
//     pthread_mutex_unlock(&philo->mutexs->lock_eat);

//     pthread_mutex_unlock(&philo->right_fork);
//     pthread_mutex_unlock(philo->left_fork);
//     printf("philo[%d] : is sleeping\n", philo->id + 1);
//     sleep(1);
//     printf("philo[%d] : is thinking\n", philo->id + 1);
//     usleep(1);
// }


// void *simulation(void *ph)
// {
//     t_philo *philo = (t_philo *)ph;
//     if(philo->id == 0)
//         usleep(1);
//     while (1)
//         rot((t_philo *)philo);
// }

// int init_data(t_data *data)
// {
//     t_mutexs *mutexs;

//     data->t_die = 210;
//     data->t_eat = 900;
//     data->t_sleep = 900;
//     data->n_philos = 5;
//     mutexs = malloc(sizeof(t_mutexs));
//     if (!mutexs)
//         return 0;
//     if (pthread_mutex_init(&mutexs->lock_eat, NULL) != 0)
//         return 0;
//     data->mutexs = mutexs;
//     return 1;
// }


// void create_philos(t_data *data)
// {
//     int i = 0;
//     while (data->n_philos > i)
//     {
//         data->th[i].id = i;
//         data->th[i].data = data;
//         data->th[i].mutexs = data->mutexs;
//         data->th[i].t_die = data->t_die;
//         data->th[i].t_eat = data->t_eat;
//         data->th[i].t_sleep = data->t_sleep;
//         pthread_mutex_init(&data->th[i].right_fork, NULL);
//         if(i > 0)
//             data->th[i].left_fork = &data->th[i - 1].right_fork; 
//         else
//             data->th[i].left_fork = &data->th[data->n_philos - 1].right_fork; 

//         pthread_create(&data->th[i].th, NULL, simulation, (void *)&data->th[i]);

//         i++;
//     }
//     i = 0;
//     while (data->n_philos > i)
//     {
//          pthread_join(data->th[i].th, NULL);
//          i++;
//     }
// }

// int main()
// {
//     t_data data;
//     if(!init_data(&data))
//     {
//         printf("====\n");
//         return 0;
//     }
//     create_philos(&data);

// }