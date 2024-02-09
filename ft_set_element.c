#include "philo.h"

void ft_set_element(t_big *p, int *ar)
{
    int i = 0;
    while(i < 4)
    {
        if (ar[i] == 0)
            ft_error(1);
        i++;
    }
    p->thread = malloc(sizeof(t_philo) * ar[0]);
    if (!p)
        return ;
    i = -1;
    while(++i < ar[0])
    {
        p->thread[i].time_to_die = ar[1];
        p->thread[i].time_to_eat = ar[2];
        p->thread[i].time_to_sleep = ar[3];
        p->thread[i].time_must_eat = ar[4];
    }
    p->thread_num = ar[0];
}
