

#include "philo.h"

void    display_message(t_philo *p, char *s)
{
    long long   time;

    time = clock_now() - p->info->start_prg;
    pthread_mutex_lock(&(p->info->message));
    printf("%lld %d %s\n", time, p->philo_id, s);
    pthread_mutex_unlock(&(p->info->message));
}

long long   clock_now()
{
    struct timeval p;

    gettimeofday(&p, 0);
    return ((p.tv_sec * 1000) + (p.tv_usec / 1000));
}
