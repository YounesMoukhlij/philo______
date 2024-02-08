#include "philo.h"

void ft_set_element(int *ar)
{
    t_philo *p;
    p->philo_num = ar[0];
    p->time_to_die = ar[1];
    p->time_to_eat = ar[2];
    p->time_to_sleep = ar[3];
    p->time_must_eat = ar[4];
}