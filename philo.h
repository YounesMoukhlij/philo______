#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo
{
    pthread_t thread_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_must_eat;
} t_philo;

typedef struct s_big
{
    t_philo *thread;
    int thread_num;
}   t_big;

int ft_is_digits(char *str);
long ft_atoi(char *str);
void ft_error(int f);
void ft_set_element(t_big *p, int *ar);
void ft_creat_threads(t_big *p);
#endif