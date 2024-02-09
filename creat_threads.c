#include "philo.h"
pthread_mutex_t m;

void *ft_life_circle(void *p)
{
    int *x;
    x = (int *)p;
    int i = 0;
    pthread_mutex_lock(&m);
    while(i < 500)
    {
        (*x)++;
        i++;
    }
    pthread_mutex_unlock(&m);
    return NULL;
}

void ft_creat_threads(t_big *p)
{
    int i = 0;

    pthread_mutex_init (&m, NULL);
    int *n = malloc(sizeof(int));
    *n = 0;
    while(i < p->thread_num)
    {
        if(pthread_create(&(p->thread[i].thread_philo) , NULL , ft_life_circle, n) != 0)
            ft_error(1);
        i++;
    }
    i = 0;
    while(i < p->thread_num)
    {
        if (pthread_join(p->thread[i].thread_philo , NULL) != 0)
            return ;
        i++;
    }
    printf("%d\n", *n);
    pthread_mutex_destroy(&m);
}